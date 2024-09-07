#include <cassert>
#include <iostream>
#include "bwd/bmt/bint.hpp"

using bint = bwd::bmt::bint;

void test_constructor_invalid_string() {
    try {
        bint invalid_bint("abc123");
        assert(false && "Expected exception not thrown");
    } catch (const std::invalid_argument &e) {
        // Exception is expected
    } catch (...) {
        assert(false && "Unexpected exception type thrown");
    }
}

void test_constructor_string_strange_numbers() {
    // Leading zeros with positive sign
    bint bint_leading_zeros_positive("+000000012345");
    assert(bint_leading_zeros_positive.toString() == "12345");

    // Leading zeros with negative sign
    bint bint_leading_zeros_negative("-000000012345");
    assert(bint_leading_zeros_negative.toString() == "-12345");

    // Leading zeros without sign
    bint bint_leading_zeros_no_sign("000000012345");
    assert(bint_leading_zeros_no_sign.toString() == "12345");

    // Single digit with leading zeros
    bint bint_single_digit_leading_zeros("+0000000005");
    assert(bint_single_digit_leading_zeros.toString() == "5");

    bint bint_single_digit_leading_zeros_negative("-0000000005");
    assert(bint_single_digit_leading_zeros_negative.toString() == "-5");

    // Zero with various signs and leading zeros
    bint bint_zeros("+0000000");
    assert(bint_zeros.toString() == "0");

    bint bint_zeros_negative("-0000000");
    assert(bint_zeros_negative.toString() == "0");

    bint bint_zeros_no_sign("0000000");
    assert(bint_zeros_no_sign.toString() == "0");

    // Large number with leading zeros
    bint bint_large_leading_zeros("00000123456789012345678901234567890");
    assert(bint_large_leading_zeros.toString() == "123456789012345678901234567890");

    // Negative large number with leading zeros
    bint bint_large_leading_zeros_negative("-00000123456789012345678901234567890");
    assert(bint_large_leading_zeros_negative.toString() == "-123456789012345678901234567890");
}

void test_constructor_string() {

    //Default
    bint def_bint;
    assert(def_bint.toString() == "0");

    //Strings
    bint str_bint1("123456789");
    assert(str_bint1.toString() == "123456789");

    bint str_bint2("1234567890123456789012345678901234567890");
    assert(str_bint2.toString() == "1234567890123456789012345678901234567890");

    bint str_bint3("-123456789");
    assert(str_bint3.toString() == "-123456789");

    bint str_bint4("-1234567890123456789012345678901234567890");
    assert(str_bint4.toString() == "-1234567890123456789012345678901234567890");

    bint str_bint5("+123456789");
    assert(str_bint5.toString() == "123456789");

    bint str_bint6("+1234567890123456789012345678901234567890");
    assert(str_bint6.toString() == "1234567890123456789012345678901234567890");

    test_constructor_invalid_string();
    test_constructor_string_strange_numbers();

    //int8_t
    int8_t int8_positive{87};
    bint bint_int8_positive(int8_positive);
    assert(bint_int8_positive.toString() == "87");

    int8_t int8_negative{-87};
    bint bint_int8_negative(int8_negative);
    assert(bint_int8_negative.toString() == "-87");

    //int32_t
    int32_t int32_positive{987345097};
    bint bint_int32_positive(int32_positive);
    assert(bint_int32_positive.toString() == "987345097");

    int32_t int32_negative{-987345097};
    bint bint_int32_negative(int32_negative);
    assert(bint_int32_negative.toString() == "-987345097");

    //int64_t
    int64_t int64_positive{939842749297010757};
    bint bint_int64_positive(int64_positive);
    assert(bint_int64_positive.toString() == "939842749297010757");

    int64_t int64_negative{-1939842749297010757};
    bint bint_int64_negative(int64_negative);
    assert(bint_int64_negative.toString() == "-1939842749297010757");

    //uint8_t
    uint8_t uint8_positive{253};
    bint bint_uint8_positive(uint8_positive);
    assert(bint_uint8_positive.toString() == "253");

    //uint16_t
    uint16_t uint16_positive{49816};
    bint bint_uint16_positive(uint16_positive);
    assert(bint_uint16_positive.toString() == "49816");

    //uint32_t
    uint32_t uint32_positive{3998776513};
    bint bint_uint32_positive(uint32_positive);
    assert(bint_uint32_positive.toString() == "3998776513");

    //uint64_t
    uint64_t uint64_positive{17987897786465132168ULL};
    bint bint_uint64_positive(uint64_positive);
    assert(bint_uint64_positive.toString() == "17987897786465132168");
}

void run_constructor_tests() {
    test_constructor_string();
    std::cout << "[bint] Construction tests passed\n";
}