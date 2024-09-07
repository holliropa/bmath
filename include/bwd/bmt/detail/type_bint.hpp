#pragma once

#include <cstdint>
#include <vector>
#include <string>

namespace bwd::bmt {
    class bint {
    public:
        typedef uint32_t limb_t;
        typedef std::vector<limb_t> limb_collection_t;

        // Constants
        static constexpr const limb_t kLimbMaxValue = 0x3B9AC9FF; // 999999999 in hexadecimal
        static constexpr const limb_t kLimbValueRange = 0x3B9ACA00; // 1000000000 in hexadecimal
        static constexpr const limb_t kDigitsPerLimb = 0x9;       // 9 in hexadecimal

        static const bint zero;
        static const bint one;
        // ----- Constants

        // Construction/Destruction
        bint();

        explicit bint(int8_t value);

        explicit bint(int16_t value);

        explicit bint(int32_t value);

        explicit bint(int64_t value);

        explicit bint(uint8_t value);

        explicit bint(uint16_t value);

        explicit bint(uint32_t value);

        explicit bint(uint64_t value);

        explicit bint(const std::string &str);

        bint(bint &&other) noexcept = default;

        bint(const bint &other) = default;

        ~bint() = default;
        // ----- Construction/Destruction


        // Operators: Assignment
        bint &operator=(const bint &other) = default;

        bint &operator=(bint &&other) noexcept = default;
        // ----- Operators: Assignment


        // Operators: Addition
        bint operator+(const bint &other) const;

        bint &operator+=(const bint &other) {
            *this = *this + other;
            return *this;
        }

        bint operator+(int8_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(int8_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(int16_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(int16_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(int32_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(int32_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(int64_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(int64_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(uint8_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(uint8_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(uint16_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(uint16_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(uint32_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(uint32_t value) {
            *this = *this + bint(value);
            return *this;
        }

        bint operator+(uint64_t value) const {
            return *this + bint(value);
        }

        bint &operator+=(uint64_t value) {
            *this = *this + bint(value);
            return *this;
        }
        // ----- Operators: Addition


        // Operators: Subtraction
        bint operator-(const bint &other) const;

        bint &operator-=(const bint &other) {
            *this = *this - other;
            return *this;
        }

        bint operator-(int8_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(int8_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(int16_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(int16_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(int32_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(int32_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(int64_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(int64_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(uint8_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(uint8_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(uint16_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(uint16_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(uint32_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(uint32_t value) {
            *this = *this - bint(value);
            return *this;
        }

        bint operator-(uint64_t value) const {
            return *this - bint(value);
        }

        bint &operator-=(uint64_t value) {
            *this = *this - bint(value);
            return *this;
        }
        // ----- Operators: Subtraction


        // Operators: Comparison
        bool operator==(const bint &other) const;

        bool operator<(const bint &other) const;

        bool operator!=(const bint &other) const {
            return !(*this == other);
        }

        bool operator>(const bint &other) const {
            return other < *this;
        }

        bool operator<=(const bint &other) const {
            return !(other < *this);
        }

        bool operator>=(const bint &other) const {
            return !(*this < other);
        }

        bool operator==(const int8_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const int8_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const int8_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const int8_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const int8_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const int8_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const int16_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const int16_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const int16_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const int16_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const int16_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const int16_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const int32_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const int32_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const int32_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const int32_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const int32_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const int32_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const int64_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const int64_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const int64_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const int64_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const int64_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const int64_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const uint8_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const uint8_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const uint8_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const uint8_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const uint8_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const uint8_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const uint16_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const uint16_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const uint16_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const uint16_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const uint16_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const uint16_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const uint32_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const uint32_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const uint32_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const uint32_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const uint32_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const uint32_t &other) const {
            return !(*this < bint(other));
        }

        bool operator==(const uint64_t &other) const {
            return *this == bint(other);
        }

        bool operator!=(const uint64_t &other) const {
            return *this != bint(other);
        }

        bool operator<(const uint64_t &other) const {
            return *this < bint(other);
        }

        bool operator>(const uint64_t &other) const {
            return *this > bint(other);
        }

        bool operator<=(const uint64_t &other) const {
            return !(bint(other) < *this);
        }

        bool operator>=(const uint64_t &other) const {
            return !(*this < bint(other));
        }
        // ----- Operators: Comparison

        // Operators: Increment
        bint &operator++() {
            *this += one;
            return *this;
        }

        bint operator++(int) {
            bint temp = *this;
            ++(*this);
            return temp;
        }
        // ----- Operators: Increment

        // Operators: Decrement
        bint &operator--() {
            *this -= one;
            return *this;
        }

        bint operator--(int) {
            bint temp = *this;
            --(*this);
            return temp;
        }
        // ----- Operators: Decrement

        friend std::ostream &operator<<(std::ostream &os, const bint &bigInt) {
            os << bigInt.toString();
            return os;
        }

        [[nodiscard]] std::string toString() const;

    private:
        [[nodiscard]] bool is_zero() const;

        void normalize_limbs();

    private:

        static int compare(const bint &left, const bint &right);

        static bint subtract_same_sign(const bint &left, const bint &right);

        static limb_collection_t to_limbs(uint64_t value);

        static limb_collection_t to_limbs(std::string::const_iterator begin, std::string::const_iterator end);

        static limb_collection_t add_limbs(const limb_collection_t &left, const limb_collection_t &right);

        static limb_collection_t subtract_limbs(const limb_collection_t &larger, const limb_collection_t &smaller);

        static int compare_limbs_magnitude(const limb_collection_t &left, const limb_collection_t &right);

    private:
        limb_collection_t m_limbs;
        bool m_sign;
    };

} // namespace bwd::bmt