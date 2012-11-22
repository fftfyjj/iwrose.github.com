---
layout: post
title: "RHCE Study Notes: VMs and iptables"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
### 背景条件
机器包含的网卡有:

+ eth0 主机的物理网卡 192.168.1
+ virbr0 安装虚拟机时生成的虚拟网络接口 192.168.122.1

虚拟网络通过NAT方式与主机连接。

### 利用syslog记录数据包通过iptables的流程
修改/etc/rsyslog.conf文件： 
添加一行代码： `kern.debug    /var/log/iptables` 将日志保存到/var/log/iptables文件.  
建立如下脚本，并运行:  
`iptables -A INPUT -j LOG --log-prefix="[filter_input]" --log-level debug`  
`iptables -A OUTPUT -j LOG --log-prefix="[filter_output]" --log-level debug`  
`iptables -A FORWARD -j LOG --log-prefix="[filter-forward]" --log-level debug`  
`iptables -t nat -A PREROUTING -j LOG --log-prefix="[nat_prerouting]" --log-level debug`  
`iptables -t nat -A OUTPUT -j LOG --log-prefix="[nat_output]" --log-level debug`  
`iptables -t nat -A POSTROUTING -j LOG --log-prefix="[nat_postrouting]" --log-level debug`  

###实验一
在虚拟机(192.168.122.186)中telnet www.baidu.com 80  
grep提取到的日志结果如下:  
<pre>
首先是虚拟机发送到DNS进行域名解析的数据包。注意, SPT表示源端口，DPT表示目的端口。  
(VM发送到53端口的UDP包，经过prerouting链)
Nov 20 15:51:11 negatlov kernel: nat_t PREROUTING negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=56366 DF PROTO=UDP SPT=1024 DPT=53 LEN=39 
(转入input链)
Nov 20 15:51:11 negatlov kernel: filter_t INPUT negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=56366 DF PROTO=UDP SPT=1024 DPT=53 LEN=39 
(virb0处无法查到DNS, 由主机发出查询请求到达192.168.0.1（主机所连的路由器）)
Nov 20 15:51:11 negatlov kernel: nat_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=65523 DPT=53 LEN=39 
（转入filter表output链）
Nov 20 15:51:11 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=65523 DPT=53 LEN=39 
(转入postrouting链)
Nov 20 15:51:11 negatlov kernel: nat_t POSTROUTING negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=65523 DPT=53 LEN=39 
（192.168.0.1返回查询结果)
Nov 20 15:51:11 negatlov kernel: filter_t INPUT negatlovIN=eth0 OUT= MAC=00:22:68:1b:d7:1e:c8:3a:35:64:47:dc:08:00 SRC=192.168.0.1 DST=192.168.0.9 LEN=86 TOS=0x00 PREC=0x00 TTL=64 ID=48477 PROTO=UDP SPT=53 DPT=65523 LEN=66 
(得到查询结果，转交给虚拟机)
Nov 20 15:51:11 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.186 LEN=86 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=53 DPT=1024 LEN=66 
以下是重复DNS查询
Nov 20 15:51:11 negatlov kernel: filter_t INPUT negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=56376 DF PROTO=UDP SPT=1024 DPT=53 LEN=39 
Nov 20 15:51:11 negatlov kernel: nat_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=40249 DPT=53 LEN=39 
Nov 20 15:51:11 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=40249 DPT=53 LEN=39 
Nov 20 15:51:11 negatlov kernel: nat_t POSTROUTING negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=40249 DPT=53 LEN=39 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=eth0 OUT= MAC=00:22:68:1b:d7:1e:c8:3a:35:64:47:dc:08:00 SRC=192.168.0.1 DST=192.168.0.9 LEN=254 TOS=0x00 PREC=0x00 TTL=64 ID=48480 PROTO=UDP SPT=53 DPT=40249 LEN=234 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.186 LEN=254 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=53 DPT=1024 LEN=234 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=56397 DF PROTO=UDP SPT=1024 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: nat_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=24271 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=24271 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: nat_t POSTROUTING negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=24271 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=eth0 OUT= MAC=00:22:68:1b:d7:1e:c8:3a:35:64:47:dc:08:00 SRC=192.168.0.1 DST=192.168.0.9 LEN=161 TOS=0x00 PREC=0x00 TTL=64 ID=48482 PROTO=UDP SPT=53 DPT=24271 LEN=141 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.186 LEN=161 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=53 DPT=1024 LEN=141 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=56416 DF PROTO=UDP SPT=1024 DPT=53 LEN=39 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.186 LEN=89 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=53 DPT=1024 LEN=69 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=56416 DF PROTO=UDP SPT=1024 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: nat_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=12309 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=12309 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: nat_t POSTROUTING negatlovIN= OUT=eth0 SRC=192.168.0.9 DST=192.168.0.1 LEN=72 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=12309 DPT=53 LEN=52 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=eth0 OUT= MAC=00:22:68:1b:d7:1e:c8:3a:35:64:47:dc:08:00 SRC=192.168.0.1 DST=192.168.0.9 LEN=161 TOS=0x00 PREC=0x00 TTL=64 ID=48484 PROTO=UDP SPT=53 DPT=12309 LEN=141 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.186 LEN=161 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=53 DPT=1024 LEN=141 
Nov 20 15:51:12 negatlov kernel: filter_t INPUT negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=192.168.122.1 LEN=59 TOS=0x00 PREC=0x00 TTL=64 ID=56436 DF PROTO=UDP SPT=1024 DPT=53 LEN=39 
Nov 20 15:51:12 negatlov kernel: filter_t OUTPUT negatlovIN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.186 LEN=89 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=UDP SPT=53 DPT=1024 LEN=69  
下面开始虚拟机到百度服务器三次握手：   
1 虚拟机发送的SYN包  分别经过了 PREROUTING FORWARD POSTROUTING 链： 
Nov 20 15:51:12 negatlov kernel: nat_t PREROUTING negatlovIN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:2f:96:3f:52:54:00:59:b1:a6:08:00 SRC=192.168.122.186 DST=119.75.218.77 LEN=60 TOS=0x10 PREC=0x00 TTL=64 ID=42088 DF PROTO=TCP SPT=1025 DPT=80 WINDOW=5840 RES=0x00 SYN URGP=0 
Nov 20 15:51:12 negatlov kernel: filter_t FORWARD negatlovIN=virbr0 OUT=eth0 PHYSIN=vnet0 SRC=192.168.122.186 DST=119.75.218.77 LEN=60 TOS=0x10 PREC=0x00 TTL=63 ID=42088 DF PROTO=TCP SPT=1025 DPT=80 WINDOW=5840 RES=0x00 SYN URGP=0 
Nov 20 15:51:12 negatlov kernel: nat_t POSTROUTING negatlovIN= OUT=eth0 PHYSIN=vnet0 SRC=192.168.122.186 DST=119.75.218.77 LEN=60 TOS=0x10 PREC=0x00 TTL=63 ID=42088 DF PROTO=TCP SPT=1025 DPT=80 WINDOW=5840 RES=0x00 SYN URGP=0 
2 服务器回的ACK/SYN包  
Nov 20 15:51:12 negatlov kernel: filter_t FORWARD negatlovIN=eth0 OUT=virbr0 SRC=119.75.218.77 DST=192.168.122.186 LEN=44 TOS=0x00 PREC=0x00 TTL=61 ID=0 DF PROTO=TCP SPT=80 DPT=1025 WINDOW=5840 RES=0x00 ACK SYN URGP=0 
3 虚拟机发送的ACK包  
Nov 20 15:51:12 negatlov kernel: filter_t FORWARD negatlovIN=virbr0 OUT=eth0 PHYSIN=vnet0 SRC=192.168.122.186 DST=119.75.218.77 LEN=40 TOS=0x10 PREC=0x00 TTL=63 ID=42089 DF PROTO=TCP SPT=1025 DPT=80 WINDOW=5840 RES=0x00 ACK URGP=0 
</pre>

###实验二（换了台机器）
Host IP: 192.168.1.101  
VM IP: 192.168.122.176  
在VM中ping 192.168.1.101, 得到如下日志： 
<pre>
Nov 21 22:01:59 localhost kernel: [nat_prerouting]IN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:ae:f2:2c:52:54:00:76:0b:a6:08:00 SRC=192.168.122.176 DST=192.168.1.101 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=373 SEQ=1 
Nov 21 22:01:59 localhost kernel: [filter_input]IN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:ae:f2:2c:52:54:00:76:0b:a6:08:00 SRC=192.168.122.176 DST=192.168.1.101 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=373 SEQ=1 
Nov 21 22:01:59 localhost kernel: [filter_output]IN= OUT=virbr0 SRC=192.168.1.101 DST=192.168.122.176 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=37841 PROTO=ICMP TYPE=0 CODE=0 ID=373 SEQ=1 
</pre>
流程图： 
![]({{site.url}}/media/1121vm2host.png)

###实验三
Host IP: 192.168.1.101  
VM IP: 192.168.122.176  
在VM中ping 192.168.122.1, 得到如下日志： 
<pre>
Nov 21 22:19:30 localhost kernel: [nat_prerouting]IN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:ae:f2:2c:52:54:00:76:0b:a6:08:00 SRC=192.168.122.176 DST=192.168.122.1 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=389 SEQ=1 
Nov 21 22:19:30 localhost kernel: [filter_input]IN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:ae:f2:2c:52:54:00:76:0b:a6:08:00 SRC=192.168.122.176 DST=192.168.122.1 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=389 SEQ=1 
Nov 21 22:19:30 localhost kernel: [filter_output]IN= OUT=virbr0 SRC=192.168.122.1 DST=192.168.122.176 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=37844 PROTO=ICMP TYPE=0 CODE=0 ID=389 SEQ=1 
</pre>
可以发现，与实验二的结论一致。到底为什么这样需要想明白。。。  
<font color="red">补充：KVM在NAT模式下，虚拟接口virbr0和eth0是相互独立的。它们之间的关系和真实路由器的不同以太网接口之间的关系类似，相互之间可以进行分组（数据包）的转发。   
而在桥接模式下，虚拟接口和eth0之间是在第二层直接连接的。就像两个电脑通过交换机汇聚在一起，通过一根网线与外界通信。这样，两接口可以设置成同一网段的ip, 模拟两个独立的机器。
</font>

###实验四
Host IP: 192.168.1.101  
VM IP: 192.168.122.176  
Host B IP: 192.168.1.102
在VM中ping 192.168.1.102, 得到如下日志： 
<pre>
Nov 21 22:15:52 localhost kernel: [nat_prerouting]IN=virbr0 OUT= PHYSIN=vnet0 MAC=52:54:00:ae:f2:2c:52:54:00:76:0b:a6:08:00 SRC=192.168.122.176 DST=192.168.1.102 LEN=84 TOS=0x00 PREC=0x00 TTL=64 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=386 SEQ=1 
Nov 21 22:15:52 localhost kernel: [filter-forward]IN=virbr0 OUT=eth1 PHYSIN=vnet0 SRC=192.168.122.176 DST=192.168.1.102 LEN=84 TOS=0x00 PREC=0x00 TTL=63 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=386 SEQ=1 
Nov 21 22:15:52 localhost kernel: [nat_postrouting]IN= OUT=eth1 PHYSIN=vnet0 SRC=192.168.122.176 DST=192.168.1.102 LEN=84 TOS=0x00 PREC=0x00 TTL=63 ID=0 DF PROTO=ICMP TYPE=8 CODE=0 ID=386 SEQ=1 
Nov 21 22:15:52 localhost kernel: [filter-forward]IN=eth1 OUT=virbr0 SRC=192.168.1.102 DST=192.168.122.176 LEN=84 TOS=0x00 PREC=0x00 TTL=63 ID=15138 PROTO=ICMP TYPE=0 CODE=0 ID=386 SEQ=1 
</pre>
###总结
还需要具体的弄明白KVM的nat到底怎么回事...(见上面红色补充文字)
如果关闭防火墙，虚拟机为什么不能访问外网？（RHEL中KVM的机制需要iptables来实现分组的nat）

###参考链接
<http://www.linuxidc.com/Linux/2012-05/61445.htm>
