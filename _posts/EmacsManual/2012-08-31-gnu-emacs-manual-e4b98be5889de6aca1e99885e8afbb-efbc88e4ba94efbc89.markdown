---
comments: true
date: 2012-08-31 23:28:05
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e4%ba%94%ef%bc%89
title: GNU Emacs Manual 之初次阅读 （五）
wordpress_id: 152
categories:
- Emacs
tags:
- Emacs
---

这篇文章就记录下关于Minibuffer的内容。
**minibuffer中可以使用到的命令有：
**C-o 可以用于扩充minibuffer的大小。
C-q
C-x o
C-a
C-k
C-y
C-M-v可以用于scroll帮助窗口。

**minibuffer中补全操作种类及详解：
**



> usually TAB, RET, and SPC) are rebound in the minibuffer to special completion commands.
'TAB'
     Complete the text in the minibuffer as much as possible; if unable
     to complete, display a list of possible completions
     ('minibuffer-complete').

'SPC'
     Complete up to one word from the minibuffer text before point
     ('minibuffer-complete-word').  This command is not available for
     arguments that often include spaces, such as file names.

'RET'
     Submit the text in the minibuffer as the argument, possibly
     completing first ('minibuffer-complete-and-exit'). 

'?'
     Display a list of completions ('minibuffer-completion-help').




**minibuffer中对history的操作：
**通过M-p M-n可以对minibuffer history进行操作。M-r M-s对minibuffer history进行搜索。

**另外：
**相比与C-x z的重复命令操作，针对minibuffer C-x ESC ESC可以同样重复命令。
M-x list-command-history可以列举所以minibuffer中输入的命令历史，注意，只是针对minibuffer。

在minibuffer中输入密码时，可以使用c-u(一般输入状态下无法使用)

