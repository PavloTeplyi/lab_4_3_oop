#include "Money.h"
#include <iostream>
#include <algorithm>

using namespace std;

Money::Money(int s, unsigned char val) : Array(s, val) {
    for (int i = 0; i < size; ++i) {
        arr[i] = arr[i] % 10;
    }
}

Array* Money::add(const Array* other) const {
    const Money* m2 = dynamic_cast<const Money*>(other);
    if (!m2) return new Money(size);

    int newSize = max(size, m2->size);
    Money* res = new Money(newSize);
    int carry = 0;

    for (int i = 0; i < newSize || carry; ++i) {
        if (i >= res->size && i < MAX_SIZE) res->setSize(i + 1);
        if (i >= MAX_SIZE) break;

        unsigned char v1 = (i < size) ? arr[i] : 0;
        unsigned char v2 = (i < m2->size) ? m2->arr[i] : 0;

        int sum = v1 + v2 + carry;
        res->arr[i] = sum % 10;
        carry = sum / 10;
    }
    return res;
}

void Money::print() const {
    if (size == 0) { cout << "0.00" << endl; return; }
    for (int i = size - 1; i >= 0; --i) {
        cout << (int)arr[i];
        if (i == 2) cout << ".";
    }
    if (size <= 2) {
        if (size == 1) cout << ".0";
        else if (size == 0) cout << "0.00";
    }
    cout << endl;
}