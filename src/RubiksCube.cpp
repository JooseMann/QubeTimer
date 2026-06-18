#include <cstdint>
#include <random>
#include <QString>

#include "RubiksCube.hpp"

RubiksCube::RubiksCube() {
    // Allocate space for 30 moves as the scramble
    // This space will be reused for each new solve
    m_scramble = new uint8_t[30];

    // Generate the scramble here
    // Also determines the scramble length
    this->generateScramble();
}

RubiksCube::RubiksCube(const RubiksCube& other) {
    m_scrambleLen = other.m_scrambleLen;
    
    // Allocate space for all 30 moves in this copy
    m_scramble = new uint8_t[30];

    // Copy over the scramble from other
    for (int i = 0; i < 30; ++i) {
        m_scramble[i] = other.m_scramble[i];
    }
}

RubiksCube::~RubiksCube() {
    delete [] m_scramble;
}

QString RubiksCube::getStringScramble() const {
    QString scrambleStr("");

    // Translate the scramble in binary to a string.
    for (int i = 0; i < m_scrambleLen; ++i) {
        // Error check, if the given move is a "no move", just skip past.
        // A value of 0xFF is "no move"
        if (m_scramble[i] == 0xFF) continue;

        // The raw move, without including the modifier (lower 4 bits)
        uint8_t move = m_scramble[i] % 16;

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
        uint8_t modifier = m_scramble[i] >> 6;

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
    m_scrambleLen = (rand() % 11) + 20; // 20 - 30 move scramble

    // Scramble creation process: generate the move, then add an optional modifier

    // Generate the lower 4 bytes
    // The first move can be any of the 6 faces, so we use % 6
    uint8_t move = rand() % 6;

    // Store the raw move in prevMove, so we can make sure that we don't have the same move twice in a row
    uint8_t prevMove = move;

    // Add a modifier, bounded [0, 2]
    // Using binary, we have 00, 01, or 10. We can transfer these to 
    // 0000 0000, 0100 0000, and 1000 0000 via a left bit shift by 6.
    move += ((rand() % 3) << 6);

    // Add this to the list of moves
    m_scramble[0] = move;

    // Now repeat for the rest of the moves, making sure we never repeat the same move twice
    for (int i = 1; i < m_scrambleLen; ++i) {
        // Generate lower 4 bytes
        // We now want to disallow the same move from happening twice.
        // So we take % 5 instead, and add 1 if move > prevMove
        // This keeps the odds of the remaining 5 moves the same, but prevents the same move from happening again.
        move = rand() % 5;

        if (move >= prevMove) ++move;

        // Update prevMove
        prevMove = move;

        // Add a modifier, same as above
        move += ((rand() % 3) << 6);

        // Add to the list of moves
        m_scramble[i] = move;
    }

    // Fill any unused moves in the scramble with 1111 1111 (marker for "no move")
    for (int i = m_scrambleLen; i < 30; ++i) {
        m_scramble[i] = 0xFF;
    }
}
