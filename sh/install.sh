#!/bin/bash
echo "Lemezkép létrehozása..."
dd if=/dev/zero of=disk.img bs=512 count=2880
echo "FAT12 struktúra kialakítása (offset: 64)..."
mkfs.fat -F 12 -n 'KAKTUSZOS' --offset 64 disk.img
echo "Bootloader beírása..."
dd if=boot.bin of=disk.img bs=512 count=1 conv=notrunc
echo "Kernel beírása..."
dd if=kernel.bin of=disk.img bs=512 seek=1 count=63 conv=notrunc
echo "Kiírás a pendrive-ra (/dev/sda)..."
sudo dd if=disk.img of=/dev/sda bs=4M status=progress
sync

echo "Kész! Próbáld bootolni valós vason."