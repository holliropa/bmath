#include "bw/bmath/bint.hpp"

namespace bw::bmath {
    void negate(bint &number) {
        number.sign = !number.sign;
    }
}