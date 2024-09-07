#include "bwd/bmt/detail/type_bint.hpp"

namespace bwd::bmt {

    bint bint::operator+(const bwd::bmt::bint &other) const {
        bint result;
        if (m_sign == other.m_sign) {
            result.m_limbs = add_limbs(m_limbs, other.m_limbs);
            result.m_sign = m_sign;
        } else {
            // Handle addition with different signs
            if (compare_limbs_magnitude(m_limbs, other.m_limbs) >= 0) {
                result.m_limbs = subtract_limbs(m_limbs, other.m_limbs);
                result.m_sign = m_sign;  // Result takes the sign of the larger magnitude
            } else {
                result.m_limbs = subtract_limbs(other.m_limbs, m_limbs);
                result.m_sign = other.m_sign;  // Result takes the sign of the larger magnitude
            }
        }

        result.normalize_limbs();

        return result;
    }

    bint bint::operator-(const bwd::bmt::bint &other) const {
        bint result;

        if (m_sign == other.m_sign) {
            // Subtraction with the same sign
            if (m_sign) {
                // Both negative: (-a) - (-b) = b - a
                return subtract_same_sign(other, *this);
            } else {
                // Both positive: a - b
                return subtract_same_sign(*this, other);
            }
        } else {
            // Different signs: a - (-b) = a + b or (-a) - b = -(a + b)
            result.m_limbs = add_limbs(this->m_limbs, other.m_limbs);
            result.m_sign = m_sign;  // Keep the sign of the original number
        }

        result.normalize_limbs();

        return result;
    }
}