#include <stdexcept>
#include <algorithm>
#include "bw/bmt/bint.hpp"
#include "internal/bint_internal.hpp"

namespace bw::bmt {
    std::string to_string(const bint &number, uint8_t base) {
        if (base < 2 || base > 64)
            throw std::invalid_argument("Base must be in the range [2, 64]");

        if (internal::limbs_is_zero(number.limbs))
            return "0";

        std::string result;
        if (number.sign)
            result += '-';

        container_t limbs = number.limbs;

        const char *digit_map = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz+/";

        uint32_t remainder;
        std::string digits;
        while (!internal::limbs_is_zero(limbs)) {
            internal::limbs_divide_ui(limbs, limbs, base, remainder);
            digits += digit_map[remainder];
        }

        result.insert(result.end(), digits.rbegin(), digits.rend());

        return result;
    }
}

