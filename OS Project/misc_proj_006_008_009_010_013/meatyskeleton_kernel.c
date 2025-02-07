// Meaty Skeleton Kernel
void meaty_skeleton_kernel() {
    const char *message = "Hello, Meaty Skeleton Kernel!";
    char *video_memory = (char *)0xb8000;

    // Print the message to the screen
    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];
        video_memory[i * 2 + 1] = 0x07;
    }

    // Set up GDT and interrupts
    setup_gdt();        // Set up GDT
    setup_interrupts(); // Set up interrupts

    // Halt the CPU after printing the message
    asm volatile("hlt");  // This halts the CPU and should exit cleanly
}
