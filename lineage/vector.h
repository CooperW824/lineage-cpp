#ifndef __VECTOR_H
#define __VECTOR_H

#include <memory>
#include <functional>

namespace lineage
{
    class vector
    {
        typedef std::function<double(size_t)> generator;

    private:
        double* m_data;
        size_t m_size;

    public:
        vector();
        vector(size_t size);
        vector(const vector &other);
        vector(size_t size, double value);
        vector(size_t size, double *data);
        vector(size_t size, generator gen);

        friend void swap(lineage::vector &first, lineage::vector &second);
        vector &operator=(vector other);
        ~vector();

        double &operator[](size_t index);
        const double &operator[](size_t index) const;
        double &at(size_t index);
        const double &at(size_t index) const;
        double *data();
        size_t size() const;

        vector operator+(const vector &other) const;
        vector operator-(const vector &other) const;
        vector operator+(double value) const;
        vector operator-(double value) const;
        vector operator*(double factor) const;
        vector operator/(double factor) const;

        vector &operator+=(const vector &other);
        vector &operator+=(double value);
        vector &operator-=(const vector &other);
        vector &operator-=(double value);
        vector &operator*=(double factor);
        vector &operator/=(double factor);

        double dot(const vector &other) const;
        vector cross(const vector &other) const;
        vector &project(const vector &other);
        vector &normalize();
        vector normalized() const;
        double magnitude() const;
        double magnitude_squared() const;

    };
} // namespace lineage

#endif