---
layout: post
title: "RHCE Study Notes: X Window System"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
### What is X Window System?
X Window就是在UNIX/Linux操作系统中提供图形化用户界面（GUI）支持的视窗系统（Window System），也被称为X。
### 
**startx命令的作用：**  
分析整理startx命令后面的参数，并结合默认的设定参数，最终以`xinit $client $clientargs -- $server $display $serverargs` 方式调用xinit程序。  
当startx后面不加任何参数运行时, `$client`的默认值是"xterm", `$clientargs`的默认值为"xinitrc"的值，`$server`默认值为"/usr/bin/X", `$display`默认值为":0", `$serverargs`默认值为"xserverrc"的值。  
具体的可以参考startx命令的脚本代码。  

**xinit命令点作用:** 
xinit根据传过来的参数启动X server，成功后呼叫X client，根据xinitrc设置相关资源，启动窗口管理器,输入法和其他应用程序等X client程序


