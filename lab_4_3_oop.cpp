#include <iostream>
#include <typeinfo>
#include "Money.h"
#include "BitString.h"

using namespace std;

int main() {
    cout << "--- Тестування Money ---" << endl;
    Money m1(3); m1[0] = 0; m1[1] = 5; m1[2] = 1;
    Money m2(3); m2[0] = 5; m2[1] = 6; m2[2] = 2;

    cout << "Money 1: "; m1.print();
    cout << "Money 2: "; m2.print();

    Array* pm1 = &m1;
    Array* pm2 = &m2;
    Array* sumMoney = pm1->add(pm2);

    cout << "Справжній тип суми Money: " << typeid(*sumMoney).name() << endl;
    cout << "Сума: "; sumMoney->print();
    delete sumMoney;

    cout << "\n--- Тестування BitString ---" << endl;
    BitString b1(4); b1[0] = 1; b1[1] = 0; b1[2] = 1; b1[3] = 1;
    BitString b2(4); b2[0] = 1; b2[1] = 1; b2[2] = 0; b2[3] = 0;

    cout << "BitString 1: "; b1.print();
    cout << "BitString 2: "; b2.print();

    Array* pb1 = &b1;
    Array* pb2 = &b2;
    Array* sumBit = pb1->add(pb2);

    cout << "Справжній тип суми BitString: " << typeid(*sumBit).name() << endl;
    cout << "Сума: "; sumBit->print();
    delete sumBit;

    BitString bNot = ~b1;
    cout << "NOT b1: "; bNot.print();

    BitString bAnd = b1 & b2;
    cout << "b1 AND b2: "; bAnd.print();

    BitString bShiftL = b1 << 2;
    cout << "b1 << 2: "; bShiftL.print();

    try {
        cout << "\nСпроба доступу до b1[10]: ";
        b1[10] = 1;
    }
    catch (const exception& e) {
        cout << "Виняток спіймано: " << e.what() << endl;
    }

    return 0;
}