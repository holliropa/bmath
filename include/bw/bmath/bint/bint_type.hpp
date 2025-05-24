#pragma once

#include "common.hpp"

namespace bw::bmath {
    struct bint {
        static const bint zero;
        static const bint one;

        container_t limbs;
        bool sign = false;
    };

} // namespace bw::bmt