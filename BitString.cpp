#include "BitString.h"
#include <iostream>
#include <algorithm>

using namespace std;

BitString::BitString(int s, unsigned char val) {
    setSize(s);
    setInitialValue(val ? 1 : 0);
}

Array* BitString::add(const Array* other) const {
    const BitString* b2 = dynamic_cast<const BitString*>(other);
    if (!b2) return new BitString(size);

    int newSize = max(size, b2->size);
    BitString* res = new BitString(newSize);
    int carry = 0;

    for (int i = 0; i < newSize || carry; ++i) {
        if (i >= res->size && i < MAX_SIZE) res->setSize(i + 1);
        if (i >= MAX_SIZE) break;

        unsigned char v1 = (i < size) ? arr[i] : 0;
        unsigned char v2 = (i < b2->size) ? b2->arr[i] : 0;

        int sum = v1 + v2 + carry;
        res->arr[i] = sum % 2;
        carry = sum / 2;
    }
    return res;
}

void BitString::print() const {
    for (int i = size - 1; i >= 0; --i) {
        cout << (int)arr[i];
    }
    cout << endl;
}

BitString BitString::operator~() const {
    BitString res(size);
    for (int i = 0; i < size; ++i) {
        res.arr[i] = arr[i] ? 0 : 1;
    }
    return res;
}

BitString operator&(const BitString& a, const BitString& b) {
    int maxS = max(a.size, b.size);
    BitString res(maxS);
    for (int i = 0; i < maxS; ++i) {
        unsigned char v1 = (i < a.size) ? a.arr[i] : 0;
        unsigned char v2 = (i < b.size) ? b.arr[i] : 0;
        res.arr[i] = v1 & v2;
    }
    return res;
}

BitString operator|(const BitString& a, const BitString& b) {
    int maxS = max(a.size, b.size);
    BitString res(maxS);
    for (int i = 0; i < maxS; ++i) {
        unsigned char v1 = (i < a.size) ? a.arr[i] : 0;
        unsigned char v2 = (i < b.size) ? b.arr[i] : 0;
        res.arr[i] = v1 | v2;
    }
    return res;
}

BitString operator^(const BitString& a, const BitString& b) {
    int maxS = max(a.size, b.size);
    BitString res(maxS);
    for (int i = 0; i < maxS; ++i) {
        unsigned char v1 = (i < a.size) ? a.arr[i] : 0;
        unsigned char v2 = (i < b.size) ? b.arr[i] : 0;
        res.arr[i] = v1 ^ v2;
    }
    return res;
}

BitString operator<<(const BitString& a, int shift) {
    if (shift < 0) return a;
    BitString res(min(a.size + shift, (int)Array::MAX_SIZE));
    for (int i = 0; i < a.size && (i + shift) < res.size; ++i) {
        res.arr[i + shift] = a.arr[i];
    }
    return res;
}

BitString operator>>(const BitString& a, int shift) {
    if (shift < 0) return a;
    if (shift >= a.size) return BitString(0);
    BitString res(a.size - shift);
    for (int i = shift; i < a.size; ++i) {
        res.arr[i - shift] = a.arr[i];
    }
    return res;
}