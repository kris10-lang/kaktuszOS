# 1. Teljes, üres lemezkép létrehozása (1.44 MB = 2880 szektor)
echo "1. Létrehozás: üres lemezkép (disk.img)"
dd if=/dev/zero of=./disk.img bs=512 count=2880

# 2. FAT12 partíció létrehozása közvetlenül a disk.img-ben, az LBA 64-es eltolással!
#    --offset 64: Ez a KULCS, ami beállítja a BPB-ben a 64 rejtett szektort.
echo "2. FAT12 létrehozása eltolással (LBA 64) a KAKTUSZOS névvel"
sudo mkfs.fat -F 12 -n 'KAKTUSZOS' --offset 64 ./disk.img

# 3. Bootloader beírása (LBA 0 / 1. szektor)
echo "3. Telepítés: boot.bin beírása az LBA 0-ra"
dd if=./boot.bin of=./disk.img bs=512 count=1 conv=notrunc

# 4. Kernel Betöltő beírása (LBA 1-63 / 2. szektortól 64. szektorig)
#    seek=1: a 2. szektortól indul az írás
#    count=63: 63 szektort írunk be
echo "4. Telepítés: kernel.bin (63 szektor) beírása az LBA 1-től"
dd if=./kernel.bin of=./disk.img bs=512 seek=1 count=63 conv=notrunc