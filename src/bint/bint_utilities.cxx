#include "bwd/bmt/detail/type_bint.hpp"

namespace bwd::bmt {
    bool bint::is_zero() const {
        return (m_limbs.size() == 1 && m_limbs[0] == 0) || m_limbs.empty();
    }

    int bint::compare(const bint &left, const bint &right) {
        if (left.m_limbs.size() != right.m_limbs.size()) {
            return left.m_limbs.size() < right.m_limbs.size() ? -1 : 1;
        }

        // Compare each limb from most significant to the least significant
        for (auto i = left.m_limbs.size(); i-- > 0;) {
            if (left.m_limbs[i] != right.m_limbs[i]) {
                return left.m_limbs[i] < right.m_limbs[i] ? -1 : 1;
            }
        }

        return 0; // They are equal
    }

    bint bint::subtract_same_sign(const bint &left, const bint &right) {
        bint result;

        bool resultSign = compare(left, right) < 0;
        result.m_sign = resultSign;

        const limb_collection_t *largeLimbs = &left.m_limbs;
        const limb_collection_t *smallerLimbs = &right.m_limbs;
        if (resultSign)
            std::swap(largeLimbs, smallerLimbs);

        result.m_limbs = subtract_limbs(left.m_limbs, right.m_limbs);
        return result;
    }

    std::string bint::toString() const {
        if (is_zero()) {
            return "0";
        }

        std::string result;
        if (m_sign) {
            result += '-';
        }

        // Add limbs to string representation
        result += std::to_string(m_limbs.back());
        for (auto i = m_limbs.size() - 1; i-- > 0;) {
            result += std::to_string(m_limbs[i] + kLimbValueRange).substr(1);  // Leading zeros
        }

        return result;
    }
} // namespace bwd::bmt