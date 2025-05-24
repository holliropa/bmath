#pragma once

#include <cstdint>
#include <cstddef>
#include <vector>

namespace bw::bmath {
    using limb_t = uint32_t;
    using limb_double_t = uint64_t;
    using container_t = std::vector<limb_t>;

    constexpr int BITS_PER_LIMB = sizeof(limb_t) * 8;
    constexpr limb_t MAX_LIMB_VALUE = 0xFFFFFFFF;
}
