---
layout: post
title: "Simplediagrams On RHEL 6.3安装历程"
description: ""
category: 
tags: []
---
{% include JB/setup %}
中午，学习iptables的时候，想画个流程图类表达自己的对iptables的理解。在找流程图软件的时候，发现了Simplediagrams这个多平台air软件。个人非常喜欢它的界面,不过安装的时候各种纠结，好在最后终于成功。

####下载  

+ Adobe air 2.6(32-bit): (Adobe公司不再支持Linux air版本，从2.6版开始没有Linux版。而且只有坑爹的32位版，我64位的RHEL 6.3伤不起啊。)  
<http://helpx.adobe.com/air/kb/archived-air-sdk-version.html>   
+ Simplediagrams 1.0.50: (官网最新版不支持Adobe air 2.6)  
<http://www.baidu.com/link?url=pH1DGJqjJ4zBBpC8yDF8xDhssDy72F1fHmk4r9UONBqwNo27THAphBMwRHGqpjvRAomWAJTjglQv> [备份]({{site.url}}/downloads/SimpleDiagrams_1_5_20.air)

####安装  
32-bit Adobe air 2.6 安装在64位RHEL的详细步骤如下：

1. Install libraries: 
<pre>
sudo yum install ld-linux.so.2
sudo yum install gtk2-devel.i686
sudo yum install libdbus-glib-1.so.2
sudo yum install libhal.so.1
sudo yum install rpm-devel.i686
sudo yum install libXt.so.6
sudo yum install --skip-broken gnome-keyring-devel.i686
sudo yum install libDCOP.so.4
sudo yum install libxml2-devel.i686
sudo yum install nss-devel.i686
sudo yum install libxslt.i686
</pre>
*注意，在安装gnome-keyring 32位版的时侯，依赖的32位pam包和64位pam包冲突，在此用`--skip-broken`解决(自己试了多次后，在rpm man文档中找到这个解决办法的)。*   
其他Linux系统按住那个air可以参考该网站。<http://helpx.adobe.com/air/kb/install-air-2-64-bit.html>  
2. Install AIR 2   
如果是bin文件： ./AdobeAIRIntaller.bin  
如果是rpm文件： rpm -ivh <adobe_air_package_name> --ignorearch  
3. Install Simplediagrams  
运行Applications->Accessories中的Adobe AIR Application installer，选择air程序，安装。

####收获 
+ 安装程序时，如果提示缺少什么库文件，则可以用 yum provides 命令查找。
例如： yum provides \*/libgtk-x11-2.0.so.0\*
+ 如果要对某个需要安装的包文件进行模糊搜索，可以用yum list *package_name*命令。

####感谢所有以下网站的资源
<http://www.simplediagrams.com/>  
<https://www.centos.org/modules/newbb/viewtopic.php?topic_id=35497>  
<http://www.cnblogs.com/dkblog/archive/2007/06/01/1980889.html>  
<http://helpx.adobe.com/air/kb/install-air-2-64-bit.html>  