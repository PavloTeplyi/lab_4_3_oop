#pragma once

#include "Array.h"

class Money : public Array {
public:
    Money(int s = 0, unsigned char val = 0);
    Array* add(const Array* other) const override;
    void print() const override;
};