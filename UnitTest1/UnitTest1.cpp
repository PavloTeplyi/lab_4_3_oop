#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>
#include "../../lab_4_3_oop/lab_4_3_oop.cpp"
#include "../Array.h"
#include "../Money.h"
#include "../BitString.h"
#include "../Array.cpp"
#include "../Money.cpp"
#include "../BitString.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTestProject
{

    TEST_CLASS(ArrayTests)
    {
    public:

        TEST_METHOD(TestArrayGetSize)
        {
            Array arr(5);
            Assert::AreEqual(5, arr.getSize(), L"getSize() має повертати поточний розмір масиву");
        }
    };
}