nasm -f elf32 ./sources/kernel_entry.asm -o ./nomindbin/kernel_entry.o
gcc -m32 -ffreestanding -c ./kernel/kernel.c -o ./nomindbin/kernel.o
ld -m elf_i386 -T ./sources/linker.ld -o ./nomindbin/kernel.elf ./nomindbin/kernel_entry.o ./nomindbin/kernel.o
objcopy -O binary ./nomindbin/kernel.elf kernel.bin
