---
comments: true
date: 2012-08-31 18:55:31
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e4%b8%89%ef%bc%89
title: GNU Emacs Manual 之初次阅读 （三）
wordpress_id: 143
categories:
- Emacs
tags:
- Emacs
---

继续接上篇文章。按照手册顺序来学习
**Kinds of User Input：
**Emacs最强大的一点就是能够完全无鼠标操作。所以，鼠标的运用我不打算去了解。


> Simple characters and control characters, as well as certain non-keyboard inputs such as mouse clicks, are collectively referred to as "input events".


Simple characters是指数字、字母、基础符号、空格等，它们都能通过按键盘上相应键就直接插入到buffer中。
Control charaters相反，无法直接插入，需要用C-q命令插入。
不过，不论是输入的普通字符还是控制字符，都叫做Input event.

**Keys**(文档写的很清晰，这节就直接摘录了):
A "key sequence", or "key" for short, is a sequence of one or more input events that is meaningful as a unit.
If a key sequence invokes a command, we call it a "complete key";
If a key sequence isn't long enough to invoke a command, we call it a "prefix key".
所以说：Every key sequence is either a complete key or a prefix key.
要注意：You can't add input events onto a complete key.
做个统计：By default, the prefix keys in Emacs are 'C-c', 'C-h', 'C-x', 'C-x', 'C-x @', 'C-x a', 'C-x n', 'C-x r', 'C-x v', 'C-x 4', 'C-x 5', 'C-x 6',, 'M-g', and 'M-o'.

有个小诀窍：
Typing the help character ('C-h' or ) after a prefix key displays a list of the commands starting with that prefix.
不过对于ESC键是失效的。

**Keys and Commands:
**虽然Emacs中有非常多的快捷键，不过按下这些键后，Emacs并不是直接就执行指定任务。相反，每个快捷键背后都和一个command绑定着，没有例外。按下键，相当于查寻了一个keymaps表，然后执行对应的commands。这样便于shortcuts自定义。
通常，我们说的例如执行C-n命令的说法严格意义来说都是不准确的，C-n只是key, 命令是next-line。

**Entering & Exiting Emacs:
**If the variable 'inhibit-startup-screen' is non-'nil', Emacs does not display the startup screen.
不过自定义的时候，注意： Setting 'inhibit-startup-screen' in 'site-start.el' doesn't work, because the startup screen is set up before reading 'site-start.el'.
不知道的小技巧：
To kill Emacs without being prompted about saving, type 'M-x kill-emacs'.
