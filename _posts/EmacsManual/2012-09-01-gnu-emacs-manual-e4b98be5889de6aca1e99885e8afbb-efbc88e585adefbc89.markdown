---
comments: true
date: 2012-09-01 11:41:23
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e5%85%ad%ef%bc%89
title: ' GNU Emacs Manual 之初次阅读 （六）'
wordpress_id: 156
categories:
- Emacs
tags:
- Emacs
---

先说说M-x的事，然后具体的学习help命令。
关于M-x的两个小事：
1. 当你输入的命令有相应的key binding的话，按完RET键后，在echo area，emacs会提示对应的key信息。可以设置suggest-key-bindings变量为nil来关闭。
2. M-x是通过运行execute-extended-command来读取输入的命令名，然后来调用运行。

Help
help这一节没啥难点，就是记忆。还好manul对常用的c-h命令分类了，这样便于记忆。我也在此分类记录下来：
**Key Help命令有：
**C-h c show the command of key
C-h k serveral lines describe key
C-h K document for key
C-h w list the key that are bound to command 和C-h c的功能恰好相反

**Command and Variable Help命令有：
**C-h f display the document of function(command).
C-h v descibe variables instead of functions.
C-h F document for command，与C-h K相呼应。

**Apropos Help命令：
**C-h a 命令名中包含apropos pattern的command。 apropos-command
M-x apropos 查找functions and variables。 GNU Emacs Manual 之初次阅读 （四）
M-x apropos-variable
M-x apropos-value
C-h d document中包含apropos pattern的函数和变量。

**Package Help命令：
**C-h p
C-h P
M-x list-packages 用于便捷安装管理包。

**Multi Language Help命令：
**C-h L describe-language-environment
C-h I describe-input-method
C-h C describe-coding-system
C-h h view-hello-file

**History Message Help命令：
**C-h l view-lossage
C-h e view-echo-area-messages

**Misc Help命令：
**C-h b describe-bindings
C-h r info-emacs-manual

**除了以上命令，还有些可以用来查看版权，漏洞报告和调试说明，发行说明等文档的命令：**
C-h C-c describe-copying
C-h C-e view-external-packages
C-h C-f view-emacs-FAQ
C-h g describe-gnu-project Richard Stallman写的文章。
C-h C-m 如何订购打印的文档
C-h C-n 或 C-h n view-emacs-news
C-h C-p view-emacs-problems如果你发现emcas的某个问题，可以查看这个文档，确定是否是emacs本身的bug.
C-h C-t emacs的开发计划。

另外，还有些其他的C-h命令，可以通过C-h C-h 或C-h ？ 来查看完整的命令列表。
C-h .也是个命令。用来显示tooltips.

这一节的命令和实际的编辑操作是没有直接关系的，但是它们和我们是否能精通Emacs却有着无法衡量的重要作用。想成为高手，必定得会熟练的从Emacs内置的文档查找知识。就如在Manual开头所说的，Emacs在Self document上做的非常好，不懂Emacs就问Emacs。:)

I'm the End!
