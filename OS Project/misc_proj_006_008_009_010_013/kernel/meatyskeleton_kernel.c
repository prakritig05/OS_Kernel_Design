#include "gdt.h"         // Include the GDT header for setup_gdt()
#include "interrupts.h"  // Include the interrupts header for setup_interrupts()
void meaty_skeleton_kernel() {
    const char *message = "Hello, Meaty Skeleton Kernel!";
    char *video_memory = (char *)0xb8000;

    // Print the message to the screen
    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07;
    }

    // Set up GDT, interrupts, etc.
    setup_gdt();    // Make sure setup_gdt() is defined
    setup_interrupts();  // Make sure setup_interrupts() is defined

    while (1);  // Halt the CPU
}

void kernel_main() {
    meaty_skeleton_kernel();
}
