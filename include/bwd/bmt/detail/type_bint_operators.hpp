#pragma once

#include "bwd/bmt/bint.hpp"

namespace bwd::bmt {

    inline bool operator==(const int8_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const int8_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const int8_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const int8_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const int8_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const int8_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const int16_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const int16_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const int16_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const int16_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const int16_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const int16_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const int32_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const int32_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const int32_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const int32_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const int32_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const int32_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const int64_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const int64_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const int64_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const int64_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const int64_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const int64_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const uint8_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const uint8_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const uint8_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const uint8_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const uint8_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const uint8_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const uint16_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const uint16_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const uint16_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const uint16_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const uint16_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const uint16_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const uint32_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const uint32_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const uint32_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const uint32_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const uint32_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const uint32_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }

    inline bool operator==(const uint64_t &lhs, const bint &rhs) {
        return rhs == lhs;
    }

    inline bool operator!=(const uint64_t &lhs, const bint &rhs) {
        return rhs != lhs;
    }

    inline bool operator<(const uint64_t &lhs, const bint &rhs) {
        return rhs > lhs;
    }

    inline bool operator>(const uint64_t &lhs, const bint &rhs) {
        return rhs < lhs;
    }

    inline bool operator<=(const uint64_t &lhs, const bint &rhs) {
        return rhs >= lhs;
    }

    inline bool operator>=(const uint64_t &lhs, const bint &rhs) {
        return rhs <= lhs;
    }
}