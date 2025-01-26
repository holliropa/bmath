#include <stdexcept>
#include "bw/bmt/bint.hpp"
#include "internal/bint_internal.hpp"

namespace bw::bmt {
    void divide(bint &quotient, const bint &dividend, const bint &divisor, bint &remainder) {
        if (internal::limbs_is_zero(divisor.limbs))
            throw std::invalid_argument("Division by zero");

        if (internal::limbs_is_zero(dividend.limbs)) {
            quotient = bint::zero;
            remainder = bint::zero;
            return;
        }

        if (divisor == bint::one) {
            quotient = dividend;
            remainder = bint::zero;
        }

        auto difference = internal::limbs_compare(dividend.limbs, divisor.limbs);
        if (difference < 0) {
            quotient = bint::zero;
            remainder = dividend;
        } else if (difference == 0) {
            quotient = bint::one;
            quotient.sign = dividend.sign != divisor.sign;
            quotient = bint::zero;
        } else {
            internal::limbs_divide(quotient.limbs, dividend.limbs, divisor.limbs, remainder.limbs);
            quotient.sign = dividend.sign != divisor.sign;
            remainder.sign = dividend.sign;
        }
    }

    void divide_ui(bint &quotient, const bint &dividend, uint32_t divisor, uint32_t &remainder) {
        if (divisor == 0)
            throw std::invalid_argument("Division by zero");

        if (internal::limbs_is_zero(dividend.limbs)) {
            quotient = bint::zero;
            remainder = 0;
            return;
        }

        if (divisor == 1) {
            quotient = dividend;
            remainder = 0;
            return;
        }

        auto difference = internal::limbs_compare_ui(dividend.limbs, divisor);
        if (difference < 0) {
            quotient = bint::zero;
            remainder = dividend.limbs.front();
        } else if (difference == 0) {
            quotient = bint::one;
            remainder = 0;
        } else {
            internal::limbs_divide_ui(quotient.limbs, dividend.limbs, divisor, remainder);
            quotient.sign = dividend.sign;
        }
    }
}