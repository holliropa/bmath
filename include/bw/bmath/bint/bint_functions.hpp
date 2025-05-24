#pragma once

#include <string>
#include "bint_type.hpp"

namespace bw::bmath {
    void set_ui(bint &number, uint32_t value);

    void set_si(bint &number, int32_t value);

    void add(bint &sum, const bint &addend1, const bint &addend2);

    void subtract(bint &difference, const bint &minuend, const bint &subtrahend);

    void multiply(bint &product, const bint &multiplicand, const bint &multiplier);

    void divide(bint &quotient, const bint &dividend, const bint &divisor, bint &remainder);

    void divide_ui(bint &quotient, const bint &dividend, uint32_t divisor, uint32_t& remainder);

    void negate(bint &number);

    int compare(const bint &left, const bint &right);

    std::string to_string(const bint &number, uint8_t base);

    inline bool operator<(const bint &left, const bint &right) { return compare(left, right) < 0; }

    inline bool operator>(const bint &left, const bint &right) { return compare(left, right) > 0; }

    inline bool operator<=(const bint &left, const bint &right) { return compare(left, right) <= 0; }

    inline bool operator>=(const bint &left, const bint &right) { return compare(left, right) >= 0; }

    inline bool operator==(const bint &left, const bint &right) { return compare(left, right) == 0; }

    inline bool operator!=(const bint &left, const bint &right) { return compare(left, right) != 0; }
}