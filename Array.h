#pragma once

#include <iostream>
#include <stdexcept>

class Array {
protected:
    static const int MAX_SIZE = 100;
    unsigned char arr[MAX_SIZE];
    int size;

    bool rangeCheck(int index) const;

public:
    void setSize(int s);
    void setInitialValue(unsigned char val);

    Array(int s = 0, unsigned char val = 0);
    virtual ~Array();

    unsigned char& operator[](int index);
    const unsigned char& operator[](int index) const;

    int getSize() const;

    virtual Array* add(const Array* other) const;
    virtual void print() const;
};