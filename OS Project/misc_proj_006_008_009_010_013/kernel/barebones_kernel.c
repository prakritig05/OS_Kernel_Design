void bare_bones_kernel() {
    const char *str = "Hello, Bare Bones Kernel!";
    char *video_memory = (char *)0xb8000;

    // Print the message to the screen
    for (int i = 0; str[i] != '\0'; i++) {
        video_memory[i * 2] = str[i];
        video_memory[i * 2 + 1] = 0x07;
    }

    while (1);  // Halt the CPU
}

void kernel_main() {
    bare_bones_kernel();
}
