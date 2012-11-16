---
layout: post
title: "RHCE Study Notes: VNC"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
There are three kinds of vnc server in RHEL 6: 

+ display associated with a KVM-based virtual machine.
+ GNOME-based VNC server: vino.
+ TigerVNC server. 

### Install & Configure a TigerVNC Server 
1. Install  
yum install vinagre tigervnc tigervnc-server  
2. Configure    
/etc/sysconfig/vncserver  
注意，需要切换到相应的用户目录，然后运行vncpasswd设置密码，否则的话，不能启动该帐号对应的vnc服务)  
3. Start   
First stop vncserver, Then start it:  
/etc/init.d/vncserver start   
service vncserver start 
4. Another Quick Method to Start vncserver  
run `vncserver :port` in the user home directory. 
我测试发现在RHEL 6.3上，该命名运行后不需要输入密码，以帐号的密码作认证密码。

### Install & Configure a vino server
run vino-preferences command.

### Client Usage
+ Using `vncviewer ip_address:port`(such as, vncviewer 127.0.0.1:2)  
+ Use Remote Desktop Viewer(or run `vinagre`)
Beware: 防火墙必须保证支持VNC连接。


### Through SSH Tunnel to Use VNC
利用vncviewer命令的-via选项，可以设置先链接SSH，然后通过SSH隧道链接VNC，保证安全性。例如： 
vncviewer -via apple@192.168.0.2 192.168.0.2:1 
不过，这只是主动利用SSH实现客户端安全VNC链接。通过设置/etc/sysconfig/vncserver配置文件，可以强制客户端必须通过SSH隧道实现VNC连接。例如：  
*\# VNCSERVERARGS[2]="-geometry 800x600 -nolisten tcp -localhost"*    
>Use "-localhost" to prevent remote VNC clients connecting except when doing so through a secure tunnel.  See the "-via" option in the `man vncviewer' manual page.  
>Use "-nolisten tcp" to prevent X connections to your VNC server via TCP.

在书中Chapter 9里面有介绍另外的一种方法：

1. 在客户端使用SSH命令和服务器端建立隧道连接。例如：  
ssh -L 5903:server\_ip:5903 username@server\_ip
2. 运行vncviewer ip\_address:port 命令建立到服务器的连接。

### Configure files in User Home
There are four kinds of files:

+ password
+ log file
+ process identifier (PID) file  
provides information on what happened, and what is happening with the connection. 
+ configuration file  
preconfigured to start the local default desktop environment.


