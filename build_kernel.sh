#!/bin/bash

export PREFIX="$HOME/opt/cross"
export TARGET=i686-elf
export PATH="$PREFIX/bin:$PATH"

rm -f *.o *.bin
echo "Start Build"
$TARGET-as boot.s -o boot.o
$TARGET-gcc -c *.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$TARGET-gcc -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib *.o -lgcc
echo "Done !"

if grub-file --is-x86-multiboot myos.bin; then
  echo multiboot confirmed
else
  echo the file is not multiboot
fi

# QEMU supports booting multiboot kernels directly without bootable medium
qemu-system-i386 -kernel myos.bin

