#include "chip8.hpp"
#include <iostream>

int main() {
    Chip8 chip8;
    chip8.LoadROM("roms/1-ibm-logo.ch8");

    std::cout << std::hex << int(chip8.memory[0x200]) << " "
          << int(chip8.memory[0x201]) << "\n";

    return 0;
}