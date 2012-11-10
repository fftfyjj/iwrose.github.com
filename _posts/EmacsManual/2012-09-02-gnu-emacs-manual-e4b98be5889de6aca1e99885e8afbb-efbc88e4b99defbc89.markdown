---
comments: true
date: 2012-09-02 14:48:51
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e4%b9%9d%ef%bc%89
title: ' GNU Emacs Manual 之初次阅读 （九）'
wordpress_id: 163
categories:
- Emacs
tags:
- Emacs
---

Registers这一节倒是新鲜，之前用的很少，但是得了解，以后用处还是很大的。
**Save Position to Registers:
**C-x r SPC R 其中，R表示寄存器名，字母或数字，a-zA-Z0-9。 point-to-register
C-x r j R jump-to-register
记忆诀窍：C-x r表示对register进行操作， SPC表示操作对象是position of point, 而C-SPC表示mark point，用SPC表示记录position倒是很合适。

**Saving Text to Registers:
**C-x r s R :copy-to-register 保存文本到register  记忆s:save
C-x r i R :insert-register 插入register到buffer
M-x append-to-register
M-x prepend-to-register




> 'C-x r i R' inserts in the buffer the text from register R.
Normally it leaves point before the text and sets the mark after,
without activating it.  With a numeric argument, it instead puts point
after the text and the mark before.





**Saving rectangles to registers:
**C-x r r R: copy-rectangle-to-register 其实这节内容和之前的rectangle C-x r d/k/y/t等操作很容易弄混。不过，努力记吧，谁让register和rectangle的名字都是r开头呢。
C-x r i R:同上。不过这个插的是rectangle,上面插的是text

**Saving Window Configurations to Registers:
**C-x r w R: window-configuration-to-register
C-x r f R: frame-configuration-to-register
C-x r j R:同上，上面是跳转到point, 这个是跳转到window or frame configuration.

**Keeping Numbers in Registers:
**C-u Number C-x r n R number-to-register
C-u Number C-x r + R increment-register
C-x r i R: instert-register

**Keeping File names in registers:
**如果经常在emacs对某文件操作（如，linux下某配置文件），可以在emacs的register中存下该文件的路径，便于用C-x r j R快捷打开该文件。
Lisp code：
(set-register ?R '(file . NAME))

**Bookmarks:
**bookmark的操作非常类似于对特殊的register的操作，
C-x r m BOOKMARK: bookmark-set
C-x r b BOOKMARK: bookmark-jump
C-x r l list-bookmarks
M-x bookmark-save:保存bookmark到硬盘文件中

 



>  Here are some additional commands for working with bookmarks:

'M-x bookmark-load  FILENAME '
     Load a file named FILENAME that contains a list of bookmark
     values.  You can use this command, as well as 'bookmark-write', to
     work with other files of bookmark values in addition to your
     default bookmark file.

'M-x bookmark-write  FILENAME '
     Save all the current bookmark values in the file FILENAME.

'M-x bookmark-delete  BOOKMARK '
     Delete the bookmark named BOOKMARK.

'M-x bookmark-insert-location  BOOKMARK '
     Insert in the buffer the name of the file that bookmark BOOKMARK
     points to.

'M-x bookmark-insert  BOOKMARK '
     Insert in the buffer the _contents_ of the file that bookmark
     BOOKMARK points to.





