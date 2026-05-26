#include <cstdint>
#include <random>
#include <QString>

#include "RubiksCube.hpp"

RubiksCube::RubiksCube() {
    this->generateScramble();

    this->scrambleLen = (rand() % 11) + 20; // 20 - 30 move scramble

    // Allocate space for 30 moves as the scramble
    this->scramble = new uint8_t[30];

    // Create the scramble
    for (int i = 0; i < this->scrambleLen; ++i) {
        // Generate lower 4 bytes (determines the move) -- bounded [0, 5]
        uint8_t move = rand() % 6;

        // Add a modifier, bounded [0, 2]
        // Using binary, we have 00, 01, or 10. We can transfer these to 
        // 0000 0000, 0100 0000, and 1000 0000 via a left bit shift by 6.
        move += ((rand() % 3) << 6);

        // Add to the list of moves
        this->scramble[i] = move;
    }

    // Fill any unused moves in the scramble with 1111 1111 (marker for "no move")
    for (int i = this->scrambleLen; i < 30; ++i) {
        this->scramble[i] = 0xFF;
    }
}

RubiksCube::RubiksCube(const RubiksCube& other) {
    this->scrambleLen = other.scrambleLen;
    
    // Allocate space for all 30 moves in this copy
    this->scramble = new uint8_t[30];

    // Copy over the scramble from other
    for (int i = 0; i < 30; ++i) {
        this->scramble[i] = other.scramble[i];
    }
}

RubiksCube::~RubiksCube() {
    delete [] this->scramble;
}

QString RubiksCube::getStringScramble() const {
    QString scrambleStr("");

    // Translate the scramble in binary to a string.
    for (int i = 0; i < this->scrambleLen; ++i) {
        // Error check, if the given move is a "no move", just skip past.
        // A value of 0xFF is "no move"
        if (this->scramble[i] == 0xFF) continue;

        // The raw move, without including the modifier (lower 4 bits)
        uint8_t move = this->scramble[i] % 16;

        // Convert the raw move
        switch (move) {
            case 0:
                scrambleStr.append("R");
                break;
            case 1:
                scrambleStr.append("U");
                break;
            case 2:
                scrambleStr.append("F");
                break;
            case 3:
                scrambleStr.append("L");
                break;
            case 4:
                scrambleStr.append("D");
                break;
            case 5:
                scrambleStr.append("B");
                break;
            default:
                scrambleStr.append("[INVALID MOVE - " + std::to_string(move) + "]");
                break;
        }

        // The modifier applied to the move (upper 4 bits)
        // Converted to 0, 1, or 2 via a right bit shift by 6.
        uint8_t modifier = this->scramble[i] >> 6;

        switch (modifier) {
            case 0: // No modifier, do nothing
                scrambleStr.append(" ");
                break;
            case 1: // Prime
                scrambleStr.append("' ");
                break;
            case 2: // Double
                scrambleStr.append("2 ");
                break;
            default:
                scrambleStr.append("[INVALID MODIFIER - " + std::to_string(modifier) + "] ");
                break;
        }
    }

    // The last character in scrambleStr will always be an extraneous space, remove that here
    scrambleStr[scrambleStr.length() - 1] = '\0';

    return scrambleStr;
}

void RubiksCube::generateScramble() {
    this->scrambleLen = (rand() % 11) + 20; // 20 - 30 move scramble

    // Allocate space for 30 moves as the scramble
    this->scramble = new uint8_t[30];

    // Create the scramble
    for (int i = 0; i < this->scrambleLen; ++i) {
        // Generate lower 4 bytes (determines the move) -- bounded [0, 5]
        uint8_t move = rand() % 6;

        // Add a modifier, bounded [0, 2]
        // Using binary, we have 00, 01, or 10. We can transfer these to 
        // 0000 0000, 0100 0000, and 1000 0000 via a left bit shift by 6.
        move += ((rand() % 3) << 6);

        // Add to the list of moves
        this->scramble[i] = move;
    }

    // Fill any unused moves in the scramble with 1111 1111 (marker for "no move")
    for (int i = this->scrambleLen; i < 30; ++i) {
        this->scramble[i] = 0xFF;
    }
}
