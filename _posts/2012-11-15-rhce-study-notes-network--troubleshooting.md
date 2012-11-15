---
layout: post
title: "RHCE Study Notes: Network & Troubleshooting"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
###Troubleshooting
遇到本地网络问题时，可以做的事情： 

+ Check the current status of the network: `/etc/init.d/network status`
+ Restart network: `/etc/init.d/network restart`
+ Check configure file /etc/sysconfig/network
+ Check files in /etc/sysconfig/network-scripts

###Configure files about Network
+ /etc/sysconfig/network： 决定是否开启网络，/etc/init.d/network脚本会最先检查这个配置文件，决定是否使用网络。同时，在系统启动阶段会根据该文件中的主机名决定系统的主机名。
+ /etc/sysconfig/network-scripts：
+ /etc/resolv.conf: 记录DNS服务器，一般由dhclient获取DNS后保存到该文件中。
+ /etc/hosts: DNS解析的第一站。
+ /etc/nsswitch.conf:

###Misc.
**关于主机名的修改：**  
1. 用hostname命令修改/etc/sysconfig/network中的主机名信息。   
2. 然后修改/etc/hosts中的对应解析信息。

**一句话：**  
网络的设置主要是掌握各种配置文件，必须了解每个配置文件中每个指令的意义。
