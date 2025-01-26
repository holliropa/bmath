#include "bw/bmt/bint.hpp"
#include "internal/bint_internal.hpp"

namespace bw::bmt {
    void multiply(bint &product, const bint &multiplicand, const bint &multiplier) {
        if (internal::limbs_is_zero(multiplicand.limbs) || internal::limbs_is_zero(multiplier.limbs)) {
            product = bint::zero;
            return;
        }

        bint result;
        result.sign = multiplicand.sign ^ multiplier.sign;

        for (container_t::size_type i = 0; i < multiplier.limbs.size(); ++i) {
            if (multiplier.limbs[i] == 0)
                continue;

            container_t partialProductLimbs;
            internal::limbs_multiply(partialProductLimbs, multiplicand.limbs, multiplier.limbs[i]);

            auto leadingZerosCount = i;
            while (leadingZerosCount > 0) {
                partialProductLimbs.insert(partialProductLimbs.begin(), 0);
                leadingZerosCount--;
            }

            internal::limbs_add(result.limbs, result.limbs, partialProductLimbs);
        }

        product = std::move(result);
    }
}