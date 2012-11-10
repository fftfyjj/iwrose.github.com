---
comments: true
date: 2012-08-31 00:11:47
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e4%b8%80%ef%bc%89
title: GNU Emacs Manual 之初次阅读 （一）
wordpress_id: 78
categories:
- Emacs
tags:
- Emacs
---

晚上，开后台下载VMware Fusion 5，然后随意摆弄电脑，突然想到前些天稍微看过GNU Emacs Manual的前几节。于是，有了想法，打算再复习一遍，然后记录下来。一为加深印象，二为以后复习。Manual还是非常厚的，看完还是狠需要花点时间，所以做成一个系列吧。

Manual中前面的最开始有3小节内容，之前没有看，本以为没啥东西，现在看来是我之前太过急躁，忽略了好东西了。
**Distrib**:: How to get the latest Emacs distribution.这一节真没啥，忽略。

**Intro**这一节是对Emacs介绍，现摘录其中个人觉得不错的文字：


> Emacs editing commands operate in terms of characters, words, lines, sentences, paragraphs, and pages, as well as expressions and comments in various programming languages.



说实在的，在buffer中做的一切文字编辑操作，归结起来就是对从字符到段落，表达式，评论等一系列对象的Control。恰好，Emacs的主modify key就是Control。:) 所以记忆快捷键的时候是可以利用这个原理来找点记忆规律的。例如GNU Emacs Reference Card中对于移动和删除操作的总结就很不错的，见下图：

[![](http://www.iwrose.com/wp-content/uploads/2012/08/屏幕快照-2012-08-30-下午11.43.40-234x300.png)](http://www.iwrose.com/wp-content/uploads/2012/08/屏幕快照-2012-08-30-下午11.43.40.png)



> You are reading about GNU Emacs, the GNU incarnation of the advanced, self-documenting, customizable, extensible editor Emacs.


这段文字描述了个事实，Emacs的事实，编辑器能做到这三点，真的已经是修炼到无上境界了，它可以说自己是天下无敌了。这也是Emacs能够当“操作系统”用的原因了。:)
self-documenting means：无论你什么时候遇到新命令或者是忘记什么命令了，用C-h帮助就可以获得你不知道或遗忘的任何信息。所以，学习Emacs最先要学好的命令是C-h相关命令。
customizable means：Emacs编辑器在手你可以改变它现有任意一点用户体验，说到底就是可以替换改变任何现有命令的操作方式。修改快捷键，自定义主题等等。
extensible means：Emacs不仅能自定义，还能发明。用Lisp语言发明、构建全新的命令。

**Glossary**::Terms used in this manual.这一节可以在看完Manual后再看，巩固、找漏用还是不错的。现在先略过。

:)打字还真是麻烦事，这篇文字就到这先。啥时能大脑直接控制打字就好了，或者语音识别到达新一层次就轻松了。

