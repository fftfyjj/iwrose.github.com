---
comments: true
date: 2012-09-03 18:30:19
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e5%8d%81%e4%ba%8c%ef%bc%89
title: ' GNU Emacs Manual 之初次阅读 （十二）'
wordpress_id: 174
categories:
- Emacs
tags:
- Emacs
---

Fixtit是关于修正文本内容的一节，里面有一些内容前面已经讲解过。
**Undo：**
工作原理：
通常，
1. 每个编辑命令都会被当作一个个体保存到undo records中，
2. 但是例如query-replace等命令则会被分成小的部分记录在undo records中，
3. 连续的单个字符插入操作通常被整合成一个整体记录在undo record中。

关于如何redo即 undo the undo，我插入原文的解说（有些拗口）:
   



> Any command other than an undo command breaks the sequence of undo commands.  Starting from that moment, the entire sequence of undo commands that you have just performed are themselves placed into the undo record, as a single set of changes.  Therefore, to re-apply changes you have undone, type `C-f' or any other command that harmlessly breaks the sequence of undoing; then type `C-/' to undo the undo command.




如果在redo的过程中想恢复undo，使用M-x undo-only命令。

如果区域是激活状态，undo命令可以只针对该区域。
C-u C-/可以针对非激活区域。

You can specify how much undo records to keep by setting the variables `undo-limit`, `undo-strong-limit`, and `undo-outer-limit`.

**Transposing Text**
C-t character
M-t word
C-M-t sexps 
C-x C-t sentence

**Case Conversion**
M-l
M-u
M-c
由于一般是需要修改前一个单词，所以用:
M-- M-l
M-- M-u
M-- M-c会更加的快捷。而不需要移动鼠标。

**Checking and Correcting Spelling
**了解以下命令：
M-$ ispell-word
M-x ispell
M-x ispell-buffer
M-x ispell-region
M-x ispell-message
M-x ispell-change-dictionary
M-x ispell-kill-ispell
M-x flyspell-mode: highlight all mispelled words.
M-x flyspell-prog-mode: enabel flyspell mode for comments and strings only.


这是在寝室完成的内容，写的也简洁。另外，接下来的keyboard Macro这一章就不学习了。说实在的，没发现它有啥用处。
EOF
