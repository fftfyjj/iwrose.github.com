---
layout: post
title: "RHCE Study Notes:Kickstart"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
**How to Get Kickstart File:**

1. From /root directory.
2. Use graphic kickstart Configurator: system-config-kickstart

**How to Access to Kickstart during Install**

1. From Local Host:
   + ks=hd:sdb1:/ks.cfg
   + ks=cdrom:/ks.cfg
   + ks=hd:fd0:/ks.cfg
2. From Network:
   + ks=ftp://192.168.122.1/pub/ks.cfg
   + ks=nfs:192.168.122.1/ks.cfg
   + ks=http://192.168.122.1/ks.cfg
   
**What is the meaning of Kickstart File**  
All the diectives is explained in this [file]({{site.url}}/downloads/kickstart.pdf).
