#include "bw/bmt/bint.hpp"
#include "internal/bint_internal.hpp"

namespace bw::bmt {
    void add(bint &sum, const bint &addend1, const bint &addend2) {
        if (addend1.sign == addend2.sign) {
            //// If both numbers have the same sign:
            //// 1. Perform addition of the limb arrays of `addend1` and `addend2`.
            ////    - Traverse through the limbs of both numbers.
            ////    - Add corresponding limbs and handle carry propagation.
            //// 2. Set the `sum.sign` to the common sign of `addend1` and `addend2`.
            internal::limbs_add(sum.limbs, addend1.limbs, addend2.limbs);
            sum.sign = addend1.sign;
        } else {
            //// If numbers have opposite signs:
            //// 1. Determine which number has a greater absolute value.
            //// 2  Perform subtraction of the smaller absolute value from the larger absolute value.
            ////    - Traverse through the limbs of both numbers.
            ////    - Subtract corresponding limbs, ensuring proper borrow handling.
            //// 3  Set the `sum.sign` to the sign of the number with the greater absolute value.
            if (internal::limbs_compare(addend1.limbs, addend2.limbs) >= 0) {
                internal::limbs_subtract(sum.limbs, addend1.limbs, addend2.limbs);
                sum.sign = addend1.sign;
            }else{
                internal::limbs_subtract(sum.limbs, addend2.limbs, addend1.limbs);
                sum.sign = addend2.sign;
            }
        }

        //// Finalize the result:
        //// 1. Normalize the `sum` (e.g., remove leading zero limbs).
        //// 2. Ensure correct handling for edge cases like zero result (set sign appropriately).
        internal::limbs_normalize(sum.limbs);
    }
}
