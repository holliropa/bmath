#include "bw/bmath/bint.hpp"
#include "internal/bint_internal.hpp"

namespace bw::bmath {
    void subtract(bint &difference, const bint &minuend, const bint &subtrahend) {
        bint result;
        auto isMinuendBigger = (internal::limbs_compare(minuend.limbs, subtrahend.limbs) >= 0);
        auto &biggerAbsNumber = isMinuendBigger ? minuend : subtrahend;
        auto &smallerAbsNumber = isMinuendBigger ? subtrahend : minuend;

        if (minuend.sign == subtrahend.sign) {
            internal::limbs_subtract(result.limbs, biggerAbsNumber.limbs, smallerAbsNumber.limbs);
            result.sign = !(isMinuendBigger ^ biggerAbsNumber.sign);
        } else {
            internal::limbs_add(result.limbs, minuend.limbs, subtrahend.limbs);
            result.sign = minuend.sign;
        }

        difference = std::move(result);
    }
}