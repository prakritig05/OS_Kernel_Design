# Assemble multiboot header
multiboot_header_barebones.o: multiboot_header.asm
	nasm -f elf $< -o $@

multiboot_header_meaty.o: multiboot_header.asm
	nasm -f elf $< -o $@

# Compile the Bare Bones Kernel
barebones_kernel.o: kernel/barebones_kernel.c
	gcc -ffreestanding -m32 -nostdlib -O2 -c $< -o $@

# Compile the Meaty Skeleton Kernel
meatyskeleton_kernel.o: kernel/meatyskeleton_kernel.c
	gcc -ffreestanding -m32 -nostdlib -O2 -c $< -o $@

# Compile gdt.c and interrupts.c
gdt.o: kernel/gdt.c kernel/gdt.h
	gcc -ffreestanding -m32 -nostdlib -O2 -c kernel/gdt.c -o gdt.o

interrupts.o: kernel/interrupts.c kernel/interrupts.h
	gcc -ffreestanding -m32 -nostdlib -O2 -c kernel/interrupts.c -o interrupts.o

# Link the Bare Bones Kernel
kernel_barebones.bin: multiboot_header_barebones.o barebones_kernel.o
	ld -m elf_i386 -T linker.ld -o $@ $^

# Link the Meaty Skeleton Kernel
kernel_meatyskeleton.bin: multiboot_header_meaty.o meatyskeleton_kernel.o gdt.o interrupts.o
	ld -m elf_i386 -T linker.ld -o $@ $^

# Create ISO for Bare Bones
kernel_barebones.iso: kernel_barebones.bin grub.cfg
	mkdir -p isodir/boot/grub
	cp kernel_barebones.bin isodir/boot/kernel_barebones.bin
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o $@ isodir

# Create ISO for Meaty Skeleton
kernel_meatyskeleton.iso: kernel_meatyskeleton.bin grub.cfg
	mkdir -p isodir/boot/grub
	cp kernel_meatyskeleton.bin isodir/boot/kernel_meatyskeleton.bin
	cp grub.cfg isodir/boot/grub/
	grub-mkrescue -o $@ isodir

# Clean everything
clean:
	rm -rf *.o *.bin *.iso isodir
