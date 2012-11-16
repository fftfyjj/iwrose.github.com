---
layout: post
title: "RHCE Study Notes: Network & Tools"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}
### Network Tools
1. ** ping**  
2. ** ifconfig**  
`ifconfig eth0 192.168.122.150 netmask 255.255.255.0`  
![ifconfig argument]({{site.url}}/media/12_11_15.png)
3. ** arp**  
4. ** netstat**  
`netstat -rn`: show the routing table, equivalent to `route -n`.  
其中，Flag列的意义分别为：  
 ![]({{site.url}}/media/12_15_1.png)
