#ifndef RUBIKSCUBE_HPP
#define RUBIKSCUBE_HPP

#include <cstdint>
#include <QString>

class RubiksCube {
public:
    /*
     * Initializes the class and generates a scramble between 20 and 30 moves long.
     */
    RubiksCube();
    RubiksCube(const RubiksCube& other);
    ~RubiksCube();

    int getScrambleLen() const { return m_scrambleLen; }

    /*
     * The raw scramble is the scramble in its binary representation. 
     * The string scramble is the scrambled translated from binary to 
     */
    uint8_t* getRawScramble() const { return m_scramble; };
    QString getStringScramble() const;
 
    void generateScramble();
private:
    uint8_t* m_scramble;
    int m_scrambleLen;
};

#endif
