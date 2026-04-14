#include "Array.h"
#include <algorithm>

using namespace std;

bool Array::rangeCheck(int index) const {
    return index >= 0 && index < size;
}

void Array::setSize(int s) {
    if (s < 0) size = 0;
    else if (s > MAX_SIZE) size = MAX_SIZE;
    else size = s;
}

void Array::setInitialValue(unsigned char val) {
    for (int i = 0; i < size; ++i) {
        arr[i] = val;
    }
    for (int i = size; i < MAX_SIZE; ++i) {
        arr[i] = 0;
    }
}

Array::Array(int s, unsigned char val) {
    setSize(s);
    setInitialValue(val);
}

Array::~Array() {}

unsigned char& Array::operator[](int index) {
    if (!rangeCheck(index)) throw out_of_range("Індекс поза межами масиву");
    return arr[index];
}

const unsigned char& Array::operator[](int index) const {
    if (!rangeCheck(index)) throw out_of_range("Індекс поза межами масиву");
    return arr[index];
}

int Array::getSize() const { return size; }

Array* Array::add(const Array* other) const {
    Array* res = new Array(max(size, other->size));
    for (int i = 0; i < res->size; ++i) {
        unsigned char v1 = (i < size) ? arr[i] : 0;
        unsigned char v2 = (i < other->size) ? other->arr[i] : 0;
        res->arr[i] = v1 + v2;
    }
    return res;
}

void Array::print() const {
    for (int i = size - 1; i >= 0; --i) {
        cout << (int)arr[i] << " ";
    }
    cout << endl;
}