---
comments: true
date: 2012-09-02 20:23:53
layout: post
slug: gnu-emacs-manual-%e4%b9%8b%e5%88%9d%e6%ac%a1%e9%98%85%e8%af%bb-%ef%bc%88%e5%8d%81%ef%bc%89
title: ' GNU Emacs Manual 之初次阅读 （十）'
wordpress_id: 166
categories:
- Emacs
tags:
- Emacs
---

Display讲解的都是和显示有关的内容，如屏幕滚动，自定义显示字体颜色等等。

**Scrolling**:
C-v M-v两命令。
不过，一般滚动时，下一屏会留2行上一屏的内容, next-screen-context-lines可以自定义。
M-x scroll-down-line
M-x scroll-up-line
可以用来只滚动一行。默认没有绑定任何快捷键。

**Recentering:
**C-l : recenter-top-bottom看命令的名字可以猜出是中－上－下的顺序重新在屏幕中显示当前行。
>注意，这个命令和M-r命令的区别：
>C-l: 光标不移动，屏幕动。
>M-r: 屏幕不移动，光标动。光标移动顺序是从 光标点-中－上－下－中－上－下...的顺序移动
对于C-l还有点小技巧：



> You can also give 'C-l' a prefix argument.  A plain prefix argument,
'C-u C-l', simply recenters point.  A positive argument N puts point N
lines down from the top of the window.  An argument of zero puts point
on the topmost line.  A negative argument -N puts point N lines from
the bottom of the window.  When given an argument, 'C-l' does not clear
the screen or cycle through different screen positions.






M-x recenter 只居中，不会轮回移动。
C-M-l：reposition-window：非常智能的居中，例如在写 lisp的时候， 会努力把当前整个函数显示在screen中。

**Automatic Scrolling:
**这个automatic scrolling是不同于我们平常理解的自动滚屏。它是指，当你用C-n命令把光标移动到当前屏幕上下两头时，如果马上就要看不见光标了，那么，屏幕会自动向下或向上尽量滚动，显示一半屏幕新内容，并使光标居中。
不过这种默认的行为是可以通过scroll-conservatively和scroll-step变量设置的。
if you set 'scroll-conservatively' to a small number N, then if you move point just a little off the screen (less than N lines), Emacs scrolls the text just far enough to bring point back on screen.

The variable 'scroll-step' determines how many lines to scroll the window when point moves off the screen.The default value is zero, which causes point to always be centered after scrolling.

**Horizontal Scrolling:
**如果开启了truncated lines，则，当光标移动到左右边缘时，会触发自动滚动。hscroll-margin和hscroll-step可以自定义auto hscroll时的行为。
另外，用C-x <和C-x >可以人工滚动。不过滚动时text lines are truncated rather than continued.

**Narrowing:
**Portion:一部分，部分的意思。
narrowing有
该节的术语：
accessibel portion
widening
restriction: bounds of narrowing
涉及的命令有：
C-x n n: narrow-to-region
C-x n w: widen
C-x n p: narrow-to-page
C-x n d: narrow-to-defun

**View Mode:
**a minor mode, 用来查看文档很方便，而且会让你不会误修改内容.
M-x view-buffer
M-x view-file

q: view-quit 退出view mode也退出当前buffer
e: view-exit 只退出view mode

**Follow Mode:
**开启要的条件，用C-x 3命令分两window。
然后M-x follow-mode
follow-mode的功能类似于第一个windows的内容中没显示完成的，会在第二屏中显示。
不过，如果使用C-x C-+命令放大字体后，第二屏的内容该变动却没变动。而且，好像也用不了M->, M-<命令。

**Text Faces:
**之前看这节时没看明白，这次争取看明白。然后用自己语言总结出来.
face实际就是文字显示风格。包括有font, height, weight, salnt, foreground and background color, underlining or overlining.
大多是主模式通过Font Lock mode来给文字赋予face.

Emacs中有一系列默认的faces。所有的face都是在default face的基础上发展起来的。
buffer中显示的文字就是用的default face.
cursor face用来定义光标，不过只有 background color属性有用。光标覆盖下的文字的颜色和文字的背景色相同。(其实就是和default face中的background color属性一样。)不过，在text terminal下，光标的样式是由终端决定的。

**Colors for faces:
**M-x set-face-foreground	
M-x set-face-background
M-x set-foreground-color
M-x set-background-colar
M-x list-colors-display

**Standard Faces:
**该节列举了各种各样的face，自定义时可以对照看。

**Text Scale:
**C-x C-+
C-x C-=
C-x C--
C-x C-0
这些键都与text-scale-adjust绑定在一起。通过最后的按键来判断该大该小。
text-scale-mode-step能设置变化量。

**Font Lock Mode:
**这节看的云里雾里。先暂略过。

**Highlight Interactively:
**M-x highlight-changes-mode开启该模式，高亮文档中修改过的部分
M-x hi-lock-mode 开启该模式，高亮和指定正则表达匹配的内容。
对于hi-lock-mode:
C-x w h REGEXP 用于指定正则表达式，匹配，高亮。highlight-regexp
C-x w r REGEXP unhighlight REGEXP，取消高亮。unhighlight-regexp
C-x w l REGEXP highlight-lines-matching-regexp
C-x w b hi-lock-write-interactive-patterns
C-x w i hi-lock-find-patterns
这一节内容，对于以后编程啥的还是很有用处。

**Window Fringes:
**fringe:边缘.
On graphical displays, each Emacs window normally has narrow "fringes" on the left and right edges.
M-x fringe-mode能够关闭／开启fringe
window fringes的用处：
1. indicate a contiunation line.
2. indicate line truncation.
3. indicate buffer boundaries,
4. indicate when a program you are debuggis in executing.

**Displaying Boundaries:
**通过设置indicate-buffer-boundaries变量，可以控制显示效果。
该变量的值的结构是(INDICATOR . POSITION)
INDICATOR: top, bottom, up, down, t
POSITION: left, right, nil
For example, ((top . left)(t . right)) ((top . left)(bottom . left))

**Useless Whitespace:
**可用通过设置 trailing-whitespace来使得trailing whitespace显示出来。
用M-x delete-trailing-whitespace可以删除buffer/region的trailing whitespace.

M-x whitespace-mode能够显示whitespace-style变量中的所有whitespace.
其中，whitespace-style能支持的style可以通过c-h v命令来查看。

**Selective Display:
**To hide lines in the current buffer, type 'C-x $'('set-selective-display') with a numeric argument N.  Then lines withat least N columns of indentation disappear from the screen.  The onlyindication of their presence is that three dots ('...') appear at theend of each visible line that is followed by one or more hidden ones.


**Displaying The Cursor:
**这节介绍如何自定义cursor的样式。
在Text terminal中，cursor的样式是由终端控制。
在graphic display中:
1. 可以设置color: change the background attribute of the face named 'cursor'.
2. 可以设置shape：设置cursor-type变量，可以通过c-h v查看种类。
3. 可以设置是否blink：设置blink-cursor-mode变量为nil。
4. 可以设置对tab是否当整体用光标覆盖：设置x-stretch-cursor为non nil。
5. 可以设置非激活窗口是否显示空心光标：cursor-in-non-selected-windows to nil。
注意，使用M-x hl-line-mode可以让鼠标所在的位置更加容易找到。'M-x global-hl-line-mode' enables or disables the same mode globally.

**Line Truncation:
**You can explicitly enable line truncation for a particular buffer with the command 'M-x toggle-truncate-lines'.  This works by locally changing the variable '
truncate-lines'.
如果window变的太窄的话，emcas会自动开启line truncation。

**Visual Line Mode:
**之前有介绍过，会自动wrap logical lines，而且是在单词与单词之间的空格处wrap。这样不会影响阅读。
visual line mode在fringe处没有指示符，可以通过设置变量visual-line-fringe-indicators来决定是否显示。

这节内容很多，也有很多新知识。目前来说，只能说是看过一遍，离掌握还差些。

