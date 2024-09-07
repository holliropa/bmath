#include "bwd/bmt/detail/type_bint.hpp"

namespace bwd::bmt {
    bool bint::operator==(const bwd::bmt::bint &other) const {
        if (is_zero() && other.is_zero()) {
            return true;
        }
        return m_sign == other.m_sign && m_limbs == other.m_limbs;
    }

    bool bint::operator<(const bwd::bmt::bint &other) const {
        if (m_sign != other.m_sign) {
            return m_sign;  // Negative numbers are less than positive numbers
        }

        // Compare magnitudes based on the sign
        return m_sign ? compare(*this, other) > 0 : compare(*this, other) < 0;
    }
}