#include "bw/bmt/bint/bint_functions.hpp"
#include "internal/bint_internal.hpp"

namespace bw::bmt {
    int compare(const bint &left, const bint &right) {
        if (left.sign != right.sign) {
            return left.sign ? -1 : 1;
        }

        auto limbs_compare = internal::limbs_compare(left.limbs, right.limbs);

        if (left.sign)
            return -limbs_compare;

        return limbs_compare;
    }
}