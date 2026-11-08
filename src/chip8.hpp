#pragma once
#include <cstdint>
#include <random>

class Chip8
{
public:

    // functions;
    Chip8();
    void LoadROM(char const* filename);

    // machine state
    uint8_t registers[16]{}; // 16 8-Bit registers V0-VF
    uint8_t memory[4096]{};  // 4096KB memory 0x000-0xFFF
    uint16_t index{};
    uint16_t pc{}; // program counter
    uint16_t stack[16]{};
    uint8_t sp{}; // stack pointer
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint8_t keypad[16]{};
    uint32_t video[64 * 32]{}; // 64x32p screen
    uint16_t opcode;

    // rand engine
    std::default_random_engine randGen;
    std::uniform_int_distribution<uint8_t> randByte;
};