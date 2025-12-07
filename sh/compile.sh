nasm -f bin ./sources/boot.asm -o ./boot.bin
nasm -f elf32 ./sources/kernel_entry.asm -o ./nomindbin/kernel_entry.o
gcc -m32 -ffreestanding -c ./kernel/kernel.c -o ./nomindbin/kernel.o
ld -m elf_i386 -T ./sources/linker.ld -o ./nomindbin/kernel.elf ./nomindbin/kernel_entry.o ./nomindbin/kernel.o
objcopy -O binary ./nomindbin/kernel.elf kernel.bin
dd if=/dev/zero of=./kernel.bin bs=1 count=1 seek=$((63 * 512 - 1)) conv=notrunc 2>/dev/null
