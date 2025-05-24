#pragma once

#include "bw/bmath/bint.hpp"

namespace bw::bmath::internal {
    void limbs_add(container_t &sum, const container_t &addend1, const container_t &addend2);

    void limbs_subtract(container_t &difference, const container_t &minuend, const container_t &subtrahend);

    void limbs_multiply(container_t &product, const container_t &multiplicand, const limb_t &multiplier);

    void limbs_divide(container_t &quotient, const container_t &dividend, const container_t &divisor, container_t &remainder);

    void limbs_divide_ui(container_t &quotient, const container_t &dividend, uint32_t divisor, uint32_t &remainder);

    int limbs_compare(const container_t &left, const container_t &right);

    int limbs_compare_ui(const container_t &left, limb_t right);

    bool limbs_is_zero(const container_t &limbs);

    void limbs_normalize(container_t &limbs);
}