---
comments: true
date: 2012-09-01 20:25:33
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e4%b8%83%ef%bc%89
title: ' GNU Emacs Manual 之初次阅读 （七）'
wordpress_id: 158
categories:
- Emacs
tags:
- Emacs
---

接下来要学习的内容，都是和text changing文字修改有关的知识。
先介绍学习Mark这一节
Mark是个标记，就象锚点，在emcas的buffer中对当前光标位置做个标记。
这样有什么用处呢？一是，方便快速的回到之前光标位。二是，用来选择region,即区域。而emacs默认的情况也是mark后，在移动光标的话会动态的高亮显示一个region。这中行为被emacs称为 transient mark mode，可以M-x transient-mark-mode命令来关闭。这样，高亮显示就不会出现了，不过region还是继续存在的。

下面介绍下mark更多详细情况：
**Setting the Mark:
**除去鼠标操作的话，还有3个方法设置mark。C-SPC, C-@, Shifled cursor motion keys(按住shift再移动光标时会自动mark)。
之前说到mark的一个用处就时方便快速的回到之前的光标位，那么如何操作呢？ 首先，在某一位置，按C-@或C-SPC两次，然后，你可以在任何其他位置通过C-u C-@来回到标记位.

C-x C-x命令是用来在mark和point之间交换位置的快捷键。不过要注意的是，如果你之前mark某点，然后又取消了，使用C-x C-x命令会一样生效，而且会激活之前的被取消的mark。

mark在设置后，可能处于两种状态，激活和非激活。处于激活状态时，移动光标时会高亮显示区域。而非激活状态时则相反。

C-y命令在插入时，会在插入的文字开头设置非激活标记。便于使用C-u C-@来跳转。

**Commands to Mark Textual Objecs:
**下面的是些快捷的用来选择区域的命令：
M-@ : set mark at the end of next word.
C-M-@: Mark expression
M-h: Mark-paragraph
C-M-h: Mark-defun
C-x C-p: mark-page
C-x h: mark-whole-buffer

**The Mark Ring
**每次设置mark的时候，当前的mark都会被保存在mark ring中，就想kill ring。可以用C-u C-@来不断的回跳到之前的mark点。

不过如果是经常要与某固定点来回跳动，更好的方法是把position保存到register中。

**The Global Mark Ring
**在每个buffer中mark时，除了当前buffer的mark ring会保存，global mark ring也会保存。这样，当切换到别的buffer时，也可以用C-x C-@来回到之前的buffer的mark位置。

**Disabling Transient Mark Mode
**



> The default behavior of the mark and region, in which setting the mark activates it and highlights the region, is called Transient Mark mode.




transient mark mode的特点是，set mark & activate it.
在transient mark mode下和非transient mark mode，C-x C-x的表现是不同的。在TM mode，如果disactivate mark后再使用C-x C-x会交换point和mark,并且激活mark，重新高亮region。而C-u C-x C-x则不会重新激活它。
而在非TM mode下，虽然默认的mark点就是非激活状态，但是，C-x C-x却不会激活它。而用C-u C-x C-x却可以激活。
这有点让人迷惑。。


EOF
