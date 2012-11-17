---
layout: post
title: "RHCE Study Notes: All About iptables (资源收集)"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
今天一天就花在iptables上了，本来在看资料时，以为iptables很简单，却没想到越看越模糊，现在暂时是没法用自己的语言来表达自己对iptables的了解。 不过在网络上找到不少关于iptables的各类资料,统一都收集在自己这个帖子中。

1. 两个流程图： 
![]({{site.url}}/media/111701.png)   
![]({{site.url}}/media/111703.gif)  
2. iptables命令框架结构图:  
![]({{site.url}}/media/111704.jpg)
3. [iptables的基本概念和数据包流程图](http://www.ha97.com/4093.html) 
4. 官网的一份文档：  
[Iptables-tutorial 1.2.2](http://www.frozentux.net/documents/iptables-tutorial/) [备份下载]({{site.url}}/downloads/iptables-tutorial.html.tgz)  
[Iptables-tutorial中文版1.1.19](http://www.frozentux.net/iptables-tutorial/cn/iptables-tutorial-cn-1.1.19.html)
5. 这是某网友读过这份文档后做的思维导图笔记[下载]({{site.url}}/media/111702.jpg)：  
![]({{site.url}}/media/111702.jpg)
6. 以下代码是RHEL 6.3 2.6.32-279.el6.x86_64中`kernel/include/linux/netfilter_ipv4.h`文件的一部分定义table优先级的内容：
<pre>
/* IP Hooks */
/* After promisc drops, checksum checks. */
#define NF_IP_PRE_ROUTING	 0
/* If the packet is destined for this box. */
#define NF_IP_LOCAL_IN	     	 1
/* If the packet is destined for another interface. */
#define NF_IP_FORWARD	     	 2
/* Packets coming from a local process. */
#define NF_IP_LOCAL_OUT	       3
/* Packets about to hit the wire. */
#define NF_IP_POST_ROUTING  4
#define NF_IP_NUMHOOKS		5
#endif /* ! __KERNEL__ */

enum nf_ip_hook_priorities {
     NF_IP_PRI_FIRST = INT_MIN,
     NF_IP_PRI_CONNTRACK_DEFRAG = -400,
     NF_IP_PRI_RAW = -300,
     NF_IP_PRI_SELINUX_FIRST = -225,
     NF_IP_PRI_CONNTRACK = -200,
     NF_IP_PRI_MANGLE = -150,
     NF_IP_PRI_NAT_DST = -100,
     NF_IP_PRI_FILTER = 0,
     NF_IP_PRI_SECURITY = 50,
     NF_IP_PRI_NAT_SRC = 100,
     NF_IP_PRI_SELINUX_LAST = 225,
     NF_IP_PRI_CONNTRACK_CONFIRM = INT_MAX,
     NF_IP_PRI_LAST = INT_MAX,
};
</pre>

**所有参考过的链接汇总在此, 在此表示衷心感谢：**  
<http://ishare.iask.sina.com.cn/f/34645357.html?retcode=0>
<http://blog.wuxinan.net/archives/99>
<http://www.ha97.com/4093.html>
<http://bbs.chinaunix.net/thread-2190723-1-1.html>