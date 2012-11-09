---
layout: post
title: "关于在RHEL 6上运维jekyll博客"
description: ""
category: jekyll
tags: [markdown, jekyll]
---
{% include JB/setup %}

##Install

1. install gcc: yum install gcc 
   这一步必需,否则后面gem安装jekyll时会出错.
2. install ruby: yum install -y ruby; yum install -y ruby-devel ruby-docs ruby-ri ruby-irb ruby-rdoc 
3. install gem: yum install rubygems
4. install jekyll: gem install jekyll
5. install rake: gem install rake


##Config jekyll blog

1. 一些基本的初始化步骤请按照[Jekyll Quick Start](http://jekyllbootstrap.com/usage/index.html "starter")设置。
2. 关于主题的选择和设置请参考：[Using Themes](http://jekyllbootstrap.com/usage/jekyll-theming.html)。
3. 如果想自定义主题，需保证自己对html, css, ruby有一定的了解。如果你了解，可以参考[Theme API](http://jekyllbootstrap.com/api/theme-api.html)进行定制。
4. 关于BASE_PATH, Comments等设置见：[Blog Configuration](http://jekyllbootstrap.com/usage/blog-configuration.html)。
5. 想深入了解jekyll工作原理，请参考：[jekyll Introduction](http://jekyllbootstrap.com/lessons/jekyll-introduction.html)。
6. 另外，还有些文档挺不错，可以参考：[jekyll install & configuration](https://github.com/mojombo/jekyll/wiki/Install)、[jekyll Wiki](https://github.com/mojombo/jekyll/wiki)、[使用github+jekyll搭建blog环境，完美替代wordpress](http://www.heiniuhaha.com/lessons/2012/08/09/use-jekyll-build-blog/)、[use-jekyll-build-blog-on-github](http://hzmook.github.com/2012/07/01/use-jekyll-build-blog-on-github.html)



##Install Markdown mode for Emacs
Emacs是我喜欢的工具，用Emacs来写博客也是必然的选择，特别是在Linux平台。 
markdown mode的安装具体可以参考<http://linuxtoy.org/archives/emacs-markdown-mode.html>。  
但是，Emacs采用何种markdown解释器还是得好好考虑的，必须保证解释的效果是和jekyll解释的效果一致。个人建议直接采用jekyll的解释器来作Emacs写作时预览所用的解释器。在jekyll中，默认的是Maruku，可以选择速度更快的C语言实现的RDiscount。  
`ln -s \usr\bin\rdiscount \usr\bin\markdown`



##一些喜好jekyll的博客
LevanLifan <http://levanlifan.diandian.com/>  
谢益辉<http://yihui.name/cn/> 
阮一峰的个人网站 <http://www.ruanyifeng.com/home.html>
