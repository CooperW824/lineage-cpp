#ifndef __VECTOR_H
#define __VECTOR_H

#include <memory>
#include <functional>

#include "complex_number.h"

namespace lineage
{
    class vector
    {
        typedef std::function<complex_number(size_t)> generator;

    private:
        std::unique_ptr<complex_number[]> m_data = nullptr;
        size_t m_size = 0;

    public:
        vector(){};
        vector(size_t size);
        vector(const vector &other);
        vector(size_t size, complex_number value);
        vector(size_t size, complex_number *data);
        vector(size_t size, generator gen);

        friend void swap(lineage::vector &first, lineage::vector &second);
        vector &operator=(vector other);
        ~vector(){};

        complex_number &operator[](size_t index);
        const complex_number &operator[](size_t index) const;
        complex_number &at(size_t index);
        const complex_number &at(size_t index) const;
        complex_number *data();
        size_t size() const;

        vector operator+(const vector &other) const;
        vector operator-(const vector &other) const;
        vector operator+(complex_number value) const;
        vector operator-(complex_number value) const;
        vector operator*(complex_number factor) const;
        vector operator/(complex_number divisor) const;

        vector &operator+=(const vector &other);
        vector &operator+=(complex_number value);
        vector &operator-=(const vector &other);
        vector &operator-=(complex_number value);
        vector &operator*=(complex_number factor);
        vector &operator/=(complex_number divisor);

        complex_number dot(const vector &other) const;
        vector cross(const vector &other) const;
        vector &project(const vector &other);
        vector &normalize();
        vector normalized() const;
        double magnitude() const;
        double magnitude_squared() const;

    };
} // namespace lineage

#endif