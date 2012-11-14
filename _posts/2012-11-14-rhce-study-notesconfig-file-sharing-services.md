---
layout: post
title: "RHCE Study Notes:Config File Sharing Services"
description: ""
category: RHCE
tags: [linux]
---
{% include JB/setup %}
本章知识主要来源Chapter 1
###General File Sharing Services Configure Steps:
1. Install
2. Config
3. Copy
4. Chcon
5. Start
6. Autostart

###Apache Server
1. Install: yum install httpd
2. Config: /etc/httpd/conf/
3. Copy: copy files to /var/www/html
4. Chcon: chcon -R --reference=/var/www/html /var/www/html/*.*
5. Start: /etc/init.d/httpd start
6. Autostart: chkconfig httpd on

###VSFtp Server
1. Install: yum install vsftpd
2. Config: /etc/vsftp/
3. Copy: copy files to /var/ftp/pub/
4. Chcon: chcon -R --reference=/var/ftp/pub /var/ftp/pub/*.*
5. Start: /etc/init.d/vsftpd start
6. Autostart: chkconfig vsftpd on