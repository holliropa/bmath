#include "bwd/bmt/detail/type_bint.hpp"

namespace bwd::bmt {

    void bint::normalize_limbs() {
        while (m_limbs.size() > 1 && m_limbs.back() == 0) {
            m_limbs.pop_back();
        }
    }

    bint::limb_collection_t bint::to_limbs(uint64_t value) {
        limb_collection_t limbs;
        while (value > 0) {
            auto part = value % kLimbValueRange;
            limbs.push_back(static_cast<limb_t>(part));
            value /= kLimbValueRange;
        }

        return limbs;
    }

    bint::limb_collection_t bint::to_limbs(std::string::const_iterator begin, std::string::const_iterator end) {
        limb_collection_t limbs;
        size_t len = std::distance(begin, end);
        limbs.reserve((len + kDigitsPerLimb - 1) / kDigitsPerLimb); // Preallocate memory for limbs

        uint64_t currentValue = 0;
        uint64_t currentMultiplier = 1;
        int digitCount = 0;

        for (auto it = end; it != begin; --it) {
            char c = *(it - 1);
            currentValue += (c - '0') * currentMultiplier;
            currentMultiplier *= 10;
            ++digitCount;

            if (digitCount == kDigitsPerLimb ||
                it == begin + 1) { // Process limb when reaching the limit or end of string
                limbs.push_back(static_cast<limb_t>(currentValue));
                currentValue = 0;
                currentMultiplier = 1;
                digitCount = 0;
            }
        }

        return limbs;
    }

    bint::limb_collection_t bint::add_limbs(const limb_collection_t &left, const limb_collection_t &right) {
        limb_collection_t result;
        size_t maxSize = std::max(left.size(), right.size());
        result.resize(maxSize);

        uint64_t carry = 0;
        for (size_t i = 0; i < maxSize; ++i) {
            uint64_t leftLimb = (i < left.size()) ? left[i] : 0;
            uint64_t rightLimb = (i < right.size()) ? right[i] : 0;
            uint64_t sum = leftLimb + rightLimb + carry;

            result[i] = static_cast<limb_t>(sum % kLimbValueRange);
            carry = sum / kLimbValueRange;
        }

        if (carry > 0) {
            result.push_back(static_cast<limb_t>(carry));
        }

        return result;
    }

    bint::limb_collection_t bint::subtract_limbs(const limb_collection_t &larger, const limb_collection_t &smaller) {
        limb_collection_t result;
        result.resize(larger.size());

        int64_t borrow = 0;
        for (size_t i = 0; i < larger.size(); ++i) {
            int64_t leftLimb = larger[i];
            int64_t rightLimb = (i < smaller.size()) ? smaller[i] : 0;
            int64_t diff = leftLimb - rightLimb + borrow;

            if (diff < 0) {
                diff += kLimbValueRange;
                borrow = -1;
            } else {
                borrow = 0;
            }

            result[i] = static_cast<limb_t>(diff);
        }

        return result;
    }

    int bint::compare_limbs_magnitude(const limb_collection_t &left, const limb_collection_t &right) {
        if (left.size() != right.size()) {
            return (left.size() > right.size()) ? 1 : -1;
        }

        // Compare each limb from most significant to the least significant
        for (size_t i = left.size(); i-- > 0;) {
            if (left[i] != right[i]) {
                return (left[i] > right[i]) ? 1 : -1;
            }
        }

        return 0; // They are equal
    }
} // namespace bwd::bmt