#include "bint_internal.hpp"

namespace bw::bmt::internal {
    void limbs_add(container_t &sum, const container_t &addend1, const container_t &addend2) {
        auto isLeftLarger = addend1.size() > addend2.size();
        auto &largerLimbs = isLeftLarger ? addend1 : addend2;
        auto &smallerLimbs = isLeftLarger ? addend2 : addend1;

        container_t result(largerLimbs.size());

        limb_double_t carry = 0;

        container_t::size_type i = 0;
        for (; i < smallerLimbs.size(); ++i) {
            limb_double_t limb_sum = static_cast<limb_double_t>(addend1[i])
                                     + static_cast<limb_double_t>(addend2[i])
                                     + carry;

            result[i] = static_cast<limb_t>(limb_sum);
            carry = limb_sum >> BITS_PER_LIMB;
        }

        for (; i < largerLimbs.size(); ++i) {
            limb_double_t limb_sum = static_cast<limb_double_t>(largerLimbs[i]) + carry;

            result[i] = static_cast<limb_t>(limb_sum);
            carry = limb_sum >> BITS_PER_LIMB;
        }

        if (carry > 0) {
            result.push_back(static_cast<limb_t>(carry));
        }

        sum = std::move(result);
    }

    void limbs_subtract(container_t &difference, const container_t &minuend, const container_t &subtrahend) {
        container_t result(minuend.size());

        bool isBorrow = false;

        container_t::size_type i = 0;
        for (; i < subtrahend.size(); ++i) {
            auto limb_minuend = static_cast<limb_double_t>(minuend[i]);
            auto limb_subtrahend = static_cast<limb_double_t>(subtrahend[i]);

            if (isBorrow) {
                if (limb_minuend == 0) {
                    limb_minuend = MAX_LIMB_VALUE;
                } else {
                    limb_minuend -= 1;
                    isBorrow = false;
                }
            }

            if (limb_minuend < limb_subtrahend) {
                isBorrow = true;
                limb_minuend += MAX_LIMB_VALUE;
            }

            result[i] = static_cast<limb_t>(limb_minuend - limb_subtrahend);
        }

        for (; i < minuend.size(); ++i) {
            auto limb_minuend = minuend[i];

            if (isBorrow) {
                if (limb_minuend == 0) {
                    limb_minuend = MAX_LIMB_VALUE;
                } else {
                    limb_minuend -= 1;
                    isBorrow = false;
                }
            }

            result[i] = limb_minuend;
        }

        difference = std::move(result);
    }

    void limbs_multiply(container_t &product, const container_t &multiplicand, const limb_t &multiplier) {
        container_t result(multiplicand.size());

        auto multiplierLimbDouble = static_cast<limb_double_t>(multiplier);
        limb_double_t carry = 0;
        container_t::size_type i = 0;
        for (; i < multiplicand.size(); ++i) {
            limb_double_t partialProduct = static_cast<limb_double_t>(multiplicand[i]) * multiplierLimbDouble;
            partialProduct += carry;

            result[i] = static_cast<limb_t>(partialProduct);
            carry = partialProduct >> BITS_PER_LIMB;
        }

        if (carry > 0) {
            result.push_back(static_cast<limb_t>(carry));
        }

        product = std::move(result);
    }

    void limbs_divide(container_t &quotient,
                      const container_t &dividend,
                      const container_t &divisor,
                      container_t &remainder) {


        quotient.resize(dividend.size());

        for (auto i = dividend.size(); i-- > 0;) {
            remainder.insert(remainder.begin(), dividend[i]);

            limb_t quotient_digit = 0;
            while (internal::limbs_compare(remainder, divisor) >= 0) {
                internal::limbs_subtract(remainder, remainder, divisor);
                ++quotient_digit;
            }

            quotient[i] = quotient_digit;
        }
    }

    void limbs_divide_ui(container_t &quotient, const container_t &dividend, uint32_t divisor, uint32_t &remainder) {
        quotient.resize(dividend.size());

        limb_double_t temp_remainder = 0;
        for (auto i = dividend.size(); i-- > 0;) {
            temp_remainder <<= BITS_PER_LIMB;
            temp_remainder += dividend[i];

            quotient[i] = static_cast<limb_t>(temp_remainder / divisor);

            temp_remainder %= divisor;
        }

        remainder = static_cast<uint32_t>(temp_remainder);
    }

    int limbs_compare(const container_t &left, const container_t &right) {
        auto left_it = left.rbegin();
        while (left_it != left.rend() && *left_it == 0) {
            ++left_it;
        }

        auto right_it = right.rbegin();
        while (right_it != right.rend() && *right_it == 0) {
            ++right_it;
        }

        auto left_normalized_size = left.rend() - left_it;
        auto right_normalized_size = right.rend() - right_it;

        if (left_normalized_size != right_normalized_size) {
            return left_normalized_size > right_normalized_size ? 1 : -1;
        }

        while (left_it != left.rend() && right_it != right.rend()) {
            if (*left_it != *right_it) {
                return (*left_it > *right_it) ? 1 : -1;
            }
            ++left_it;
            ++right_it;
        }

        return 0; // If all limbs are equal
    }

    int limbs_compare_ui(const container_t &left, limb_t right) {
        auto it = left.rbegin();
        while (it != left.rend() && *it == 0) {
            ++it;
        }

        if (it == left.rend()) {
            return right == 0 ? 0 : -1;
        }

        auto normalized_size = std::distance(it, left.rend());
        if (normalized_size == 1) {
            return *it < right ? -1 : (*it > right ? 1 : 0);
        }

        return 1;
    }

    bool limbs_is_zero(const container_t &limbs) {
        auto it = limbs.rbegin();
        while (it != limbs.rend()) {
            if (*it != 0) {
                return false;
            }
            ++it;
        }
        return true;
    }

    void limbs_normalize(container_t &limbs) {
        while (!limbs.empty() && limbs.back() == 0) {
            limbs.pop_back();
        }
    }
}