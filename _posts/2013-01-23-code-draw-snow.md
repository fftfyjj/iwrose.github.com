---
layout: post
title: "Code: Draw Snow"
description: ""
category: Code
tags: []
---
{% include JB/setup %}
>在linux下利用libgraph库实现的一个精度不高的雪花绘图程序。  
>利用《[jekyll-bootstrap添加代码高亮](http://heroin.so/javascript/2012/05/22/jekyll-bootstrap-code-highlighting/)》这篇文章做的代码高亮，效果很奇怪，将就用用先。  
>利用《[Ubuntu的gcc编译找不到graphics.h解决方法](http://perzect.blog.163.com/blog/static/434595512011719193957/)》这篇文章在linux下实现了graphics.h。不是原装，提供的函数啥的都区别很大。  
<pre class="prettyprint linenums">
#include <math.h>
#include <graphics.h>
#define Pi 3.1415925535


void drawline(int len, int rad);
void fun(int, int, int);
void drawSnow();
void drawline(int len, int rad)
{
  int x0= getx();
  int y0=gety();
  double tmp = (rad*Pi)/180;
  int x1= x0+(len*cos(tmp));//现在才知道cos函数用的是弧度。。。
  int y1=y0+(len*sin(tmp));
  //  printf("cos(%d) is %f",rad, cos(tmp));
  //  printf("cos(rad) is %d", (len*cos(tmp)));
  //  printf("(x0,y0)is %d, %d\n",x0,y0);
  //  printf("(x1,y1)is %d, %d\n", x1,y1);
  lineto(x1,y1);

}

void fun(int len, int rad, int order)
{
  if(order==0)
    drawline(len, rad);
  else
    {
      fun(len/3, rad, order-1);
      fun(len/3, rad-60, order-1);
      fun(len/3, rad+60, order-1);
      fun(len/3, rad, order-1);
    }
  return;
}

void drawSnow()
{
  int gd=DETECT, gm=VGAMAX;
  initgraph(&gd, &gm, 0);
  moveto(100,100);//move to canvas's center
  fun(400, 0, 2);
  fun(400, 120,2);
  fun(400, 240,2);
  return; 
  
}
int main()
{

  drawSnow();
  pause();
  return 0;
}
</pre>
