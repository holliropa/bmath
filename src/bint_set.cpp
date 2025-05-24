#include "bw/bmath/bint.hpp"

namespace bw::bmath {
    void set_ui(bint &number, uint32_t value) {
        number.limbs = container_t(1, static_cast<limb_t>(value));
    }

    void set_si(bint &number, int32_t value) {
        number.sign = (value < 0);
        number.limbs = container_t(1, static_cast<limb_t>(std::abs(value)));
    }
}

