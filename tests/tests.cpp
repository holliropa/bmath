#include <iostream>
#include <fstream>
#include <chrono>
#include "bw/bmath/bint.hpp"

using namespace bw::bmath;

//// Helper function to run a test and print the result
void runTest(const std::string &testName, bool (*testFunc)()) {
    std::cout << "Running " << testName << " ... ";
    if (testFunc()) {
        std::cout << "PASSED\n";
    } else {
        std::cout << "FAILED\n";
    }
}

void initialize_bint(bint &number, bool sign, std::initializer_list<limb_t> limbs) {
    number.sign = sign;
    number.limbs = container_t(limbs);
}

bool testAddition1() {
    bint number1;
    set_ui(number1, 5);

    bint number2;
    set_ui(number2, 5);

    bint expected;
    set_ui(expected, 10);

    bint actual;

    add(actual, number1, number2);

    return actual == expected;
}

bool testAddition2() {
    bint number1;
    set_ui(number1, MAX_LIMB_VALUE);

    bint number2;
    set_ui(number2, 5);

    bint expected;
    initialize_bint(expected, false, {4, 1});

    bint actual;

    add(actual, number1, number2);

    return actual == expected;
}

bool testAddition3() {
    bint number1;
    initialize_bint(number1, false, {MAX_LIMB_VALUE, MAX_LIMB_VALUE});

    bint number2;
    set_ui(number2, 5);

    bint expected;
    initialize_bint(expected, false, {4, 0, 1});

    bint actual;

    add(actual, number1, number2);

    return actual == expected;
}

bool testAddition4() {
    bint number1;
    initialize_bint(number1, false, {500, 250});

    bint number2;
    initialize_bint(number2, false, {200, 250});

    bint expected;
    initialize_bint(expected, false, {700, 500});

    bint actual;

    add(actual, number1, number2);

    return actual == expected;
}

bool testAddition5() {
    bint number1;
    initialize_bint(number1, true, {10});

    bint number2;
    initialize_bint(number2, false, {5});

    bint expected;
    initialize_bint(expected, true, {5});

    bint actual;

    add(actual, number1, number2);

    return actual == expected;
}

bool testAddition6() {
    bint number1;
    initialize_bint(number1, true, {0, 1});

    bint number2;
    initialize_bint(number2, false, {5});

    bint expected;
    initialize_bint(expected, true, {MAX_LIMB_VALUE - 5});

    bint actual;

    add(actual, number1, number2);

    return actual == expected;
}

//// 5 + 3 = 8
bool testAddition7() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, false, {5});
    initialize_bint(addend2, false, {3});
    initialize_bint(expected, false, {8});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// 3 + 5 = 8
bool testAddition8() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, false, {3});
    initialize_bint(addend2, false, {5});
    initialize_bint(expected, false, {8});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// (-5) + 3 = -2
bool testAddition9() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, true, {5});
    initialize_bint(addend2, false, {3});
    initialize_bint(expected, true, {2});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// 3 + (-5) = -2
bool testAddition10() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, false, {3});
    initialize_bint(addend2, true, {5});
    initialize_bint(expected, true, {2});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// 5 + (-3) = 2
bool testAddition11() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, false, {5});
    initialize_bint(addend2, true, {3});
    initialize_bint(expected, false, {2});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// (-3) + 5 = 2
bool testAddition12() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, true, {3});
    initialize_bint(addend2, false, {5});
    initialize_bint(expected, false, {2});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// (-5) + (-3) = -8
bool testAddition13() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, true, {5});
    initialize_bint(addend2, true, {3});
    initialize_bint(expected, true, {8});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// (-3) + (-5) = -8
bool testAddition14() {
    bint addend1, addend2, expected, actual;

    initialize_bint(addend1, true, {3});
    initialize_bint(addend2, true, {5});
    initialize_bint(expected, true, {8});

    add(actual, addend1, addend2);

    return actual == expected;
}

//// 5 - 3 = 2
bool testSubtraction1() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, false, {5});
    initialize_bint(subtrahend, false, {3});
    initialize_bint(expected, false, {2});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// 3 - 5 = -2
bool testSubtraction2() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, false, {3});
    initialize_bint(subtrahend, false, {5});
    initialize_bint(expected, true, {2});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// (-5) - 3 = -8
bool testSubtraction3() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, true, {5});
    initialize_bint(subtrahend, false, {3});
    initialize_bint(expected, true, {8});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// 3 - (-5) = 8
bool testSubtraction4() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, false, {3});
    initialize_bint(subtrahend, true, {5});
    initialize_bint(expected, false, {8});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// 5 - (-3) = 8
bool testSubtraction5() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, false, {5});
    initialize_bint(subtrahend, true, {3});
    initialize_bint(expected, false, {8});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// (-3) - 5 = -8
bool testSubtraction6() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, true, {3});
    initialize_bint(subtrahend, false, {5});
    initialize_bint(expected, true, {8});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// (-5) - (-3) = -2
bool testSubtraction7() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, true, {5});
    initialize_bint(subtrahend, true, {3});
    initialize_bint(expected, true, {2});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// (-3) - (-5) = 2
bool testSubtraction8() {
    bint minuend, subtrahend, expected, actual;

    initialize_bint(minuend, true, {3});
    initialize_bint(subtrahend, true, {5});
    initialize_bint(expected, false, {2});

    subtract(actual, minuend, subtrahend);

    return actual == expected;
}

//// 43 * 76 = 3268
bool testMultiplication1() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, false, {43});
    initialize_bint(multiplier, false, {76});
    initialize_bint(expected, false, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// 43 * (-76) = -3268
bool testMultiplication2() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, false, {43});
    initialize_bint(multiplier, true, {76});
    initialize_bint(expected, true, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// (-43) * 76 = -3268
bool testMultiplication3() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, true, {43});
    initialize_bint(multiplier, false, {76});
    initialize_bint(expected, true, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// (-43) * (-76) = 3268
bool testMultiplication4() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, true, {43});
    initialize_bint(multiplier, true, {76});
    initialize_bint(expected, false, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// 76 * 43 = 3268
bool testMultiplication5() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, false, {76});
    initialize_bint(multiplier, false, {43});
    initialize_bint(expected, false, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// 76 * (-43) = -3268
bool testMultiplication6() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, false, {76});
    initialize_bint(multiplier, true, {43});
    initialize_bint(expected, true, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// (-76) * 43 = -3268
bool testMultiplication7() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, true, {76});
    initialize_bint(multiplier, false, {43});
    initialize_bint(expected, true, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// (-76) * (-43) = 3268
bool testMultiplication8() {
    bint multiplicand, multiplier, expected, actual;

    initialize_bint(multiplicand, true, {76});
    initialize_bint(multiplier, true, {43});
    initialize_bint(expected, false, {3268});

    multiply(actual, multiplicand, multiplier);

    return actual == expected;
}

//// 76 / 15 = 5 & 1
bool testDivision1() {
    bint dividend, divisor, expectedQuotient, expectedRemainder, actualQuotient, actualRemainder;

    initialize_bint(dividend, false, {76});
    initialize_bint(divisor, false, {15});
    initialize_bint(expectedQuotient, false, {5});
    initialize_bint(expectedRemainder, false, {1});

    divide(actualQuotient, dividend, divisor, actualRemainder);

    return actualQuotient == expectedQuotient && actualRemainder == expectedRemainder;
}

//// {76, 12, 46, 14, 28, 78, 86} / 2 = {38, 6, 23, 7, 14, 39, 43}
bool testDivision2() {
    bint dividend, divisor, expectedQuotient, expectedRemainder, actualQuotient, actualRemainder;

    initialize_bint(dividend, false, {76, 12, 46, 14, 28, 78, 86});
    initialize_bint(divisor, false, {2});
    initialize_bint(expectedQuotient, false, {38, 6, 23, 7, 14, 39, 43});
    initialize_bint(expectedRemainder, false, {0});

    divide(actualQuotient, dividend, divisor, actualRemainder);

    return actualQuotient == expectedQuotient && actualRemainder == expectedRemainder;
}

//// bint(45683475) == "45683475"
bool testToString1() {
    std::string expected("45683475");
    bint number;
    initialize_bint(number, false, {45683475});

    auto actual = to_string(number, 10);

    return actual == expected;
}

//// bint(755048668) == "2D0120DC"
bool testToString2() {
    std::string expected("2D0120DC");
    bint number;
    initialize_bint(number, false, {755048668});

    auto actual = to_string(number, 16);

    return actual == expected;
}

int main() {
    std::cout << "Tests for BigMathToolkit\n";
    std::cout << "================================\n";

    //// Run all test cases
    runTest("Addition 1", testAddition1);
    runTest("Addition 2", testAddition2);
    runTest("Addition 3", testAddition3);
    runTest("Addition 4", testAddition4);
    runTest("Addition 5", testAddition5);
    runTest("Addition 6", testAddition6);
    runTest("Addition 7: 5 + 3 = 8", testAddition7);
    runTest("Addition 8: 3 + 5 = 8", testAddition8);
    runTest("Addition 9: (-5) + 3 = -2", testAddition9);
    runTest("Addition 10: 3 + (-5) = -2", testAddition10);
    runTest("Addition 11: 5 + (-3) = 2", testAddition11);
    runTest("Addition 12: (-3) + 5 = 2", testAddition12);
    runTest("Addition 13: (-5) + (-3) = -8", testAddition13);
    runTest("Addition 14: (-3) + (-5) = -8", testAddition14);
    runTest("Subtraction 1: 5 - 3 = 2 ", testSubtraction1);
    runTest("Subtraction 2: 3 - 5 = -2 ", testSubtraction2);
    runTest("Subtraction 3: (-5) - 3 = -8", testSubtraction3);
    runTest("Subtraction 4: 3 - (-5) = 8", testSubtraction4);
    runTest("Subtraction 5: 5 - (-3) = 8", testSubtraction5);
    runTest("Subtraction 6: (-3) - 5 = -8", testSubtraction6);
    runTest("Subtraction 7: (-5) - (-3) = -2", testSubtraction7);
    runTest("Subtraction 8: (-3) - (-5) = 2", testSubtraction8);
    runTest("Multiplication 1: 43 * 76 = 3268", testMultiplication1);
    runTest("Multiplication 2: 43 * (-76) = -3268", testMultiplication2);
    runTest("Multiplication 3: (-43) * 76 = -3268", testMultiplication3);
    runTest("Multiplication 4: (-43) * (-76) = 3268", testMultiplication4);
    runTest("Multiplication 5: 76 * 43 = 3268", testMultiplication5);
    runTest("Multiplication 6: 76 * (-43) = -3268", testMultiplication6);
    runTest("Multiplication 7: (-76) * 43 = -3268", testMultiplication7);
    runTest("Multiplication 8: (-76) * (-43) = 3268", testMultiplication8);
    runTest("Division 1: 76 / 15 = 5 & 1", testDivision1);
    runTest("Division 2: {76, 12, 46, 14, 28, 78, 86} / 2 = {38, 6, 23, 7, 14, 39, 43} & 0", testDivision2);
    runTest("To string 1: bint(45683475) == \"45683475\"", testToString1);
    runTest("To string 2: bint(755048668) == \"2D0120DC\"", testToString2);

    return 0;
}
