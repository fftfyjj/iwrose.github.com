---
layout: post
title: "RHCE Study Notes:SSH Configure"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
### 1.SSH Client Configure
**Configure file:**   
/etc/ssh/ssh-config

**Directives in Configure file**

+ `Host *`: applies the other directives to all connections. 
+ `GSSAPIAuthentication yes`:using the Generic Security Services Application Programming Interface for client/server authentication.  
+ `ForwardX11Trusted yes`: supports remote access to GUI tools. 
+ `SendEnv LANG LC_CTYPE LC_NUMERIC LC_TIME LC_COLLATE LC_MONETARY LC_MESSAGES 
SendEnv LC_PAPER LC_NAME LC_ADDRESS LC_TELEPHONE LC_MEASUREMENT 
SendEnv LC_IDENTIFICATION LC_ALL`
: allow the client to set several environmental variables. 

### 2.SSH Commands  
$ ssh root@server1.example.com  
$ ssh -l root server1.example.com  
\# scp F02-20.tif michael@server1:/home/michael/RHbook/Chapter2/ 

---此文待补充。
