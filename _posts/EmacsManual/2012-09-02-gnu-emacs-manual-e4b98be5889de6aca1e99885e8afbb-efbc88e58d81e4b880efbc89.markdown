---
comments: true
date: 2012-09-02 22:34:07
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e5%8d%81%e4%b8%80%ef%bc%89
title: ' GNU Emacs Manual 之初次阅读 （十一）'
wordpress_id: 170
categories:
- Emacs
tags:
- Emacs
---

终于开始学Search这一节了，为自己的坚持鼓励下吧。
Searching and Replacement

四种Search类型：Incremental Search, Nonincremental Search, Word search, Regexp Search.接下来会具体分类介绍。

**Incremental Search:
**C-s isearch-forward
C-r isearch-backward

DEL删除错误的输入字符。
RET停止搜索。另外，任何和搜索没有关系的命令也都可以stop search。当exit search的时候，会自动把当前point保存到mark ring中，使用C-u C-@跳转。

在搜索时显示的结果中，非选中的其他词也会高亮，它们的face是有lazy-highlight控制的。
当结束了搜索后，可以用C-s C-s或C-r C-r命令重复之前的搜索。The first 'C-s' is the key that invokes incremental search, and the second 'C-s' means "search again".

在输入搜索词时，可以用M-p M-n来选择之前的搜索词；搜索过程中，可以用M-e临时修改搜索词。

如果输入词是小写，则，the search is case-insensitive，如果有大写字符，则，the search is case-sensitive。

最最重要的：在Incremental search状态下，输入C-h C-h显示帮助列表。

在Incremental serach中，可以进行如下yank操作：
C-y isearch-yank-killn
M-y isearch-yank-pop
C-w isearch-yank-word-or-char: appends the next character or word at point to the search string.
M-s C-e isearch-yank-line: appends the rest of the current line to the search string.
C-M-w delete the last charater from the search string
C-M-y appends the character after point to the search string.

当minibuffer激活的时候，c-s c-r也可以对minibuffer操作。M-r M-s对minibuffer进行regex search操作。

**Nonincremental Search:
**
'C-s  STRING '
     Search for STRING.

'C-r  STRING '

**Word Search:
**'M-s w'
     If incremental search is active, toggle word search mode
     ('isearch-toggle-word'); otherwise, begin an incremental forward
     word search ('isearch-forward-word').

'M-s w  WORDS '
     Search for WORDS, using a forward nonincremental word search.

'M-s w C-r  WORDS '
     Search backward for WORDS, using a nonincremental word search.

**Regular Expression Search
**'C-M-s'
     Begin incremental regexp search ('isearch-forward-regexp').

'C-M-r'
     Begin reverse incremental regexp search
     ('isearch-backward-regexp').

**Searching and Case:
**Typing 'M-c' within an incremental search toggles the case sensitivity of that search.

**Replace:
**Simple replace: M-x replace-string
Regexp replace: M-x replace-regex
Query replace: M-%
Regexp Query replace: C-M-%

