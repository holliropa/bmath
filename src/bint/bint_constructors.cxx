#include <stdexcept>
#include <algorithm>
#include "bwd/bmt/detail/type_bint.hpp"

namespace bwd::bmt {
    bint::bint() : m_sign(false) {}

    bint::bint(uint8_t value) : bint(static_cast<uint64_t>(value)) {}

    bint::bint(uint16_t value) : bint(static_cast<uint64_t>(value)) {}

    bint::bint(uint32_t value) : bint(static_cast<uint64_t>(value)) {}

    bint::bint(uint64_t value) : m_sign(false), m_limbs(to_limbs(value)) {}

    bint::bint(int8_t value) : bint(static_cast<int64_t>(value)) {}

    bint::bint(int16_t value) : bint(static_cast<int64_t>(value)) {}

    bint::bint(int32_t value) : bint(static_cast<int64_t>(value)) {}

    bint::bint(int64_t value) : m_sign(value < 0), m_limbs(to_limbs(std::abs(value))) {}

    bint::bint(const std::string &str) : m_sign(false) {
        if (str.empty()) {
            throw std::invalid_argument("Empty string is not a valid number");
        }

        auto strNumberBegin = str.begin();
        auto strNumberEnd = str.end();

        // Handle sign
        if (*strNumberBegin == '-') {
            m_sign = true;
            strNumberBegin++;
        } else if (*strNumberBegin == '+') {
            m_sign = false;
            strNumberBegin++;
        }

        if (strNumberBegin == strNumberEnd) {
            throw std::invalid_argument("Sign without number is not a valid number");
        }

        // Check if all characters are digits
        if (!std::all_of(strNumberBegin, strNumberEnd, ::isdigit)) {
            throw std::invalid_argument("Invalid characters in input string");
        }

        m_limbs = to_limbs(strNumberBegin, strNumberEnd);

        normalize_limbs();
    }
} // namespace bwd::bmt