#include "bw/bmt/bint.hpp"

namespace bw::bmt {
    void negate(bint &number) {
        number.sign = !number.sign;
    }
}