---
layout: post
title: "RHCE Study Notes:KVM Configuration"
description: ""
category: RHCE
tags: []
---
{% include JB/setup %}

###知识点
Virtualization can be divided into five different categories:

1. **Bare-metal virtualization**:  Some VM systems include a minimal operating system dedicated to VM operation. Two examples of bare-metal virtualization systems are VMware ESX and Citrix XenServer.
2. **Hardware-assisted virtualization**: A hardware interface where VMs have access to the hardware features of a CPU, such as those described earlier with vmx or svm flags in the /proc/cpuinfo file.
3. **Paravirtualization**: While it’s functionally similar to a platform-level VM, it works with fewer resources and usually requires a specialized kernel such as Xen.
4. **Platform-level VMs**: Applications such as VMware Player and Virtualbox
are open-source edition examples of platform-level VMs that emulate a
complete computer system for the installation of a separate operating system.
5. **Application-level**: Systems like Wine Is Not an Emulator (WINE) support the installation of a single application. In this case, WINE allows an application designed for Microsoft Windows to be installed on Linux. Loosely, that is one example of an application configured in a VM.

---
###1. Install
####Install Seven Packages：

Package| Description
:---------|:----------
qemu-kvm |The main KVM package
python-virtinst | Command line tools and libraries for creating VMs
virt-manager | GUI VM administration tool
virt-top | Command for VM statistics
virt-viewer | GUI connection to configured VMs
libvirt | C language toolkit with the libvirtd service
libvirt-client | C language toolkit for VM clients

####Check KVM Modules
Using command `lsmod|grep kvm`, the output may be kvm\_intel/kvm\_amd & kvm modules. 
If no output, check `/proc/cpuinfo`, and `modprobe kvm`.

###2. Configuration
####Configure Virtual Machine Manager

1. Virtual Network
2. Virtual Network Interfaces
3. Virtual Storage

####Configure VM
KVM-based VMs are normally configured in two different directories: 

+ /etc/libvirt/ : VMs configure files are in qemu directory.
+ /var/lib/libvirt : VM images are stored in images directory.

###3. Control VM from Command Line
#### Install VMs
virt-install --prompt  
more details: 
![]({{ site.url }}/media/11_14_1.png)
#### Clone VMs
virt-clone --prompt
#### Start VMs
virsh start <domain>  
virsh autostart <domain> 
#### Stop VMs
virsh destroy (gracefully)  
virsh -> shutdown <domain>  
virsh autostart --disable <domain>
#### List VMs
virsh list --all  
vrish -> list --all
#### Configure VMs
virsh -> edit <domain>
####How to Delete a VM
1. virsh destroy xxx_vm
2. remove xml file about the VM: /etc/libvirt/qemu/xxx_vm.xml 
3. delete virtual disk files in /var/lib/libvirt/images
4. restart VM daemon, to erase xxx_vm from RAM: /etc/init.d/libvirtd restart
