---
layout: post
title: "RHCE Study Notes: Install System"
description: ""
category: RHCE
tags: [linux]
---
{% include JB/setup %}

本文章的内容主要来自Chapter 1
##知识点
1. As rebuild distributions such as the Community Enterprise Operating System(CentOS) and Scientific Linux are essentially identical to RHEL, we should be able to use these solutions too.
2. Hard driver:
   + With port multipliers, it’s relatively easy to configure 16 Serial Advanced Technology Attachment (SATA) drives on a system。
   + Older PCs could handle only four Parallel Advanced Technology Attachment (PATA) drives.
   + Depending on the SCSI (Small Computer Systems Interface) hardware available, you can attach up to 31 different SCSI hard drives.
3. As different VMs rarely use the same RAM similtaneously, it's possible to "Overbook" RAM. 
4. 建立多个虚拟机，然后保证每个虚拟机都只有独立的Role。
5. Disk Partitions命名规则：
   * The first letter identifies the type of drive (s is for PATA, SATA, or SCSI; and v is for virtual disks on KVM-based VMs). 
   * The second letter is d for disk, and 
   * the third letter represents the relative position of that disk, starting with a.
   * The number that follows is based on the relative position of the primary,
extended, or logical partition.

##如何安装系统
####1. 确定安装的前提条件
1. *Architectures*，
    Red Hat supports four basic different CPU architectures:
   + x86 (32-bit)
   + Intel/AMD64 (x86_64)
   + IBM Power Architecture (64-bit)
   + IBM System Z Architecture
2. *RAM*，
   + At least 512MiB
   + Not greater than 16GiB on 32-bit architecture
   + Not greater than 2TiB on 64-bit architecture 
3. *Hard Drive*,
   + Linux boot file from the /boot directory works only on the PATA or SATA hard dirvers, but not SCSI driver。
   + If install system on SCSI，you need a USB or CD/DVD to boot system.
   + 80GiB free space will be sufficient
4. KVM Support,
   + A configuration that supports hardware-assisted virtualization will have either the vmx (Intel) or svm (AMD) flags in the /proc/cpuinfo file.

####2. 选择安装方法
安装实际分两步走，引导系统，通过获取指定位置的安装文件实现系统安装。
引导方法： 

* Boot from an RHEL 6 DVD.
* Boot from a RHEL boot CD.
* Boot from a USB key.
* Boot from a Kickstart server using a PXE network boot card

安装文件读取方法： 

* From RHEL 6 DVD.
* From hard drivers.
* From USB.
* From Network Server(NFS, Http, Ftp...).

####3. 确定安装细节

1. 分区时，如果选择LVM分区方案，/boot文件系统不能在LVM分区中建立，需单独建立一个标准分区。
2. 在安装boot loader(RHEL 6即Grub)的时候，需要确定所安装的设备的选择是正确的（主要针对多硬盘用户）。
3. Swap Space的大小按照如下公式计算：
   + IF RAM <= 2GiB, THEN Swap=2*RAM
   + IF RAM > 2GiB, THEN Swap=RAM+2
   + 这些不是绝对的，可以根据硬盘空间实际调整。
4. 安装时，在GRUB中按TAB建，输入text可以强制进入text mode安装。
5. If you encounter problems, examine the messages in the third and fourth consoles; to do so, press ALT-F3, ALT-F4, or ALT-F5. A command line is available by pressing ALT-F2.To return to the GUI screen, press CTRL-ALT-F6. If in text-mode installation, you can return to that screen by pressing ALT-F1.
6. RHEL will recognize only up to 16 partitions on any individual SATA, SCSI, PATA, or virtual hard drive.

