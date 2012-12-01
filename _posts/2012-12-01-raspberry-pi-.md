---
layout: post
title: "Raspberry Pi 备忘"
description: ""
category: 
tags: []
---
{% include JB/setup %}
### Raspberry Pi 构建Web服务器
1. 安装及配置mysql+php+nginx见<http://i2cq.com/2012/10/1908> 
2. 构建动态域名见：<http://i2cq.com/2012/10/1860>
3. 利用<http://zengrong.net/post/1524.htm>实现动态解析

[备份下载]({{site.url}}/downloads/dnspodsh.sh)

### Logitech Media Server安装
按照<http://allthingspi.webspace.virginmedia.com/lms.php>中的步骤安装即可。
相关帖子：<http://www.raspberrypi.org/phpBB3/viewtopic.php?f=38&t=10666>

<pre>
sudo su -

wget http://downloads.slimdevices.com/nightly/7.8/sc/6ae78d4/logitechmediaserver_7.8.0~1346674706_all.deb
wget http://allthingspi.webspace.virginmedia.com/files/lms-rpi-raspbian.tar.gz

apt-get -y install libjpeg8 libpng12-0 libgif4 libexif12 libswscale2 libavcodec53 lame

dpkg -i logitechmediaserver_7.8.0~1346674706_all.deb

service logitechmediaserver stop

tar -zxvf lms-rpi-raspbian.tar.gz 
patch /usr/share/perl5/Slim/bootstrap.pm lms-rpi-bootstrap.patch
mv arm-linux-gnueabihf-thread-multi-64int /usr/share/squeezeboxserver/CPAN/arch/5.14/
mv libmediascan.so.0.0.0 libfaad.so.2.0.0 /usr/local/lib
mv /usr/share/squeezeboxserver/Bin/arm-linux/faad /usr/share/squeezeboxserver/Bin/arm-linux/faad.old
mv faad /usr/share/squeezeboxserver/Bin/arm-linux
ln -s /usr/local/lib/libmediascan.so.0.0.0 /usr/local/lib/libmediascan.so
ln -s /usr/local/lib/libmediascan.so.0.0.0 /usr/local/lib/libmediascan.so.0
ln -s /usr/local/lib/libfaad.so.2.0.0 /usr/local/lib/libfaad.so
ln -s /usr/local/lib/libfaad.so.2.0.0 /usr/local/lib/libfaad.so.2
ldconfig

chown -R squeezeboxserver:nogroup /usr/share/squeezeboxserver /var/lib/squeezeboxserver

service logitechmediaserver start
</pre>