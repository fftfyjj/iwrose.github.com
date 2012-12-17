---
layout: post
title: "Install Djvu Viewer For CentOS 6"
description: ""
category: 
tags: []
---
{% include JB/setup %}
####安装rpmforge仓库
<pre>
# Name: RPMforge RPM Repository for Red Hat Enterprise 5 - dag
# URL: http://rpmforge.net/
[rpmforge]
name = Red Hat Enterprise $releasever - RPMforge.net - dag
#baseurl = http://apt.sw.be/redhat/el6/en/$basearch/dag
mirrorlist = http://apt.sw.be/redhat/el6/en/mirrors-rpmforge
#mirrorlist = file:///etc/yum.repos.d/mirrors-rpmforge
enabled = 1
protect = 0
gpgkey = file:///etc/pki/rpm-gpg/RPM-GPG-KEY-rpmforge-dag
gpgcheck = 1
</pre>
将以上文字保存为rpmforge.repo到/etc/yum.repos.d目录。
#### 安装
`sudo yum install djvulibre`  
