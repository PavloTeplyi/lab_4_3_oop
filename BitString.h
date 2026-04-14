#pragma once

#include "Array.h"

class BitString : public Array {
public:
    BitString(int s = 0, unsigned char val = 0);

    Array* add(const Array* other) const override;
    void print() const override;

    BitString operator~() const;

    friend BitString operator&(const BitString& a, const BitString& b);
    friend BitString operator|(const BitString& a, const BitString& b);
    friend BitString operator^(const BitString& a, const BitString& b);
    friend BitString operator<<(const BitString& a, int shift);
    friend BitString operator>>(const BitString& a, int shift);
};