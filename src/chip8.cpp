#include "chip8.hpp"
#include <fstream>

// Chip-8 memory from 0x000 to 0x1FF reserved
    const unsigned int START_ADDRESS = 0x200;

    Chip8::Chip8() {
        pc = START_ADDRESS; // first instruction starts at 0x200
    }

    void Chip8::LoadROM(char const *filename) {
        // open file as a stream of binary and move file pointer to end
        std::ifstream file(filename, std::ios::binary | std::ios::ate);

        if (file.is_open()) {
            // get file size and allocate buffer to hold contents
            std::streampos size = file.tellg();
            char* buffer = new char[size];

            // Go back to beginning of file and fill buffer
            file.seekg(0, std::ios::beg);
            file.read(buffer, size);
            file.close();

            // load rom content into chip8 memory, start at 0x200
            for(long i = 0; i < size; ++i) {
                memory[START_ADDRESS + i] = buffer[i];
            }

            // free buffer
            delete[] buffer;
        }
    }

