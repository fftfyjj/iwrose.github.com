---
comments: true
date: 2012-08-31 22:11:47
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e5%9b%9b%ef%bc%89
title: GNU Emacs Manual 之初次阅读 （四）
wordpress_id: 145
categories:
- Emacs
tags:
- Emacs
---

前面的文章已经将Emacs的基础概念介绍完毕，现在开始进入EMacs的编辑命令的学习。
先学习下Basic Editing Commands，这大概也就是Emacs Tutorial的内容。也是大多是初学习必须掌握的知识，学完这一节就可以完成日程的基础编辑工作了。
**Inserting Text:** 
在这节Emacs manual又将charater分为graphic charater 和 nongraphic charater，而前面所说的却是simple character 和control charater。这点让我还是有些迷惑,找了找wikipedia，也没找到啥标准的称呼，暂且标记下来。

C-q可以用来插入nongraphic character, 还可以:
'C-q' followed by a sequence of octal digits inserts the character with the specified octal character code.（默认是八进制，不过可以通过设置 read-quoted-char-radix变量为十或十六进制）
另外，Instead of 'C-q', you can use the command 'C-x 8 ' ('ucs-insert').

Changing the Location of Point
**这节就是告诉你如何移动光标。不细说了。只列举一般教程中都没介绍的keys.
**M-r : move-to-window-line-top-bottom
M-g g 或 M-g M-g: goto-line

When a line of text in the buffer is longer than the width of the window, Emacs usually displays it on two or more "screen lines". C-n C-p命令是操作在screen lines基础上，而其他的命令则是针对的logical line。 可以设置line-move-visual为nil, 使得c-n c-p命令也是针对logical line。


**Erasing Text
**基础，此节忽略。

**Undoing Changes
**undo的快捷键有3个。

**Files & Help
**忽略，help在后面详细讲解

**Blank Lines
**C-o命令本质是：在光标处插入2个newline，光标再移到空行首。
用c-x c-o删除一空行或多个连在一起的空行。

**Continuation Lines
**默认的情况，句子太长的话，emcas可能the wrapping发生在单词中间，这样会严重影响阅读。在编写文字时，可以通过Auto Fill mode来让Emacs自动插入newline。
另一种情况是，你需要修改包含很多长句子的文本。这样auto fill mode就没用了，因为文章已经是完成状态。这时就需要Visual Line mode，自动在词间wrap。
Emacs can optionally "truncate" long logical lines instead of continuing them.

**Cursor Position Informaiton
**
掌握了解如下命令，还是会有些用处的。例如，统计字数，查看字符的character code，即character encoding。关于什么是character encoding, 参见这篇文章：[http://www.iwrose.com/?p=146](http://www.iwrose.com/?p=146)



> 'M-x what-line'
     Display the line number of point.

'M-x line-number-mode'
'M-x column-number-mode'
     Toggle automatic display of the current line number or column
     number.

'M-='
     Display the number of lines, words, and characters that are
     present in the region ('count-words-region').  for
     information about the region.

'M-x count-words'
     Display the number of lines, words, and characters that are
     present in the buffer.  If the region is active display the 
     numbers for the region instead.

'C-x ='
     Display the character code of character after point, character
     position of point, and column of point ('what-cursor-position').

'M-x hl-line-mode'
     Enable or disable highlighting of the current line. 

'M-x size-indication-mode'
     Toggle automatic display of the size of the buffer. 





**Numeric Arguments**
有两种输入方式：




> Instead of typing 'M-1', 'M-2', and so on, another way to specify a
numeric argument is to type 'C-u' ('universal-argument') followed by
some digits, or (for a negative argument) a minus sign followed by
digits.





**Repeating a Command**
用数字参数可以让某些命令重复N次，但是如果数字参数别有用处的时候，此方法就不行了。
这时，用C-x z命令可以完成重复操作。z的个数表明重复次数。不过该命令前也可以通过加数字参数来实现指定次数的重复操作。

:) End!
