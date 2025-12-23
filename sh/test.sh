qemu-system-i386 \
  -machine pc \
  -drive file=disk.img,format=raw,if=ide \
  -boot c