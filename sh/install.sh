# Létrehozunk egy üres floppy image-t (pl. 1.44 MB = 2880 szektor * 512 bájt)
dd if=/dev/zero of=./disk.img bs=512 count=2880

# Beleírjuk az első szektorba a bootloadert
dd if=./boot.bin of=./disk.img bs=512 count=1 conv=notrunc

# Beleírjuk a kernel bináris fájlt a 2. szektortól kezdve
dd if=./kernel.bin of=./disk.img bs=512 seek=1 conv=notrunc
