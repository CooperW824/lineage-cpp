#include <algorithm>

#include "complex_number.h"

lineage::complex_number &lineage::complex_number::operator=(lineage::complex_number other)
{
    std::swap(real, other.real);
    std::swap(imaginary, other.imaginary);
    return *this;
}

lineage::complex_number &lineage::complex_number::operator=(double real)
{
    this->real = real;
    this->imaginary = 0.0;
    return *this;
}

lineage::complex_number lineage::complex_number::operator+(const lineage::complex_number &other) const
{
    return complex_number(real + other.real, imaginary + other.imaginary);
}

lineage::complex_number lineage::complex_number::operator+(double value) const
{
    return complex_number(real + value, imaginary);
}

lineage::complex_number lineage::complex_number::operator-(const lineage::complex_number &other) const
{
    return complex_number(real - other.real, imaginary - other.imaginary);
}

lineage::complex_number lineage::complex_number::operator-(double value) const
{
    return complex_number(real - value, imaginary);
}

lineage::complex_number lineage::complex_number::operator*(const lineage::complex_number &other) const
{
    double real = this->real * other.real - this->imaginary * other.imaginary;
    double imaginary = this->real * other.imaginary + this->imaginary * other.real;
    return complex_number(real, imaginary);
}

lineage::complex_number lineage::complex_number::operator*(double factor) const
{
    return complex_number(real * factor, imaginary * factor);
}

lineage::complex_number lineage::complex_number::operator/(const lineage::complex_number &other) const
{
    // (a + bi) / (c + di) = (a + bi)(c - di) / (c + di)(c - di)
    // https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/dividing-complex-numbers-1630595375.png
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    double real = (this->real * other.real + this->imaginary * other.imaginary) / denominator;
    double imaginary = (this->imaginary * other.real - this->real * other.imaginary) / denominator;
    return complex_number(real, imaginary);
}

lineage::complex_number lineage::complex_number::operator/(double divisor) const
{
    return complex_number(real / divisor, imaginary / divisor);
}

lineage::complex_number &lineage::complex_number::operator+=(const lineage::complex_number &other)
{
    this->real += other.real;
    this->imaginary += other.imaginary;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator+=(double value)
{
    this->real += value;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator-=(const lineage::complex_number &other)
{
    this->real -= other.real;
    this->imaginary -= other.imaginary;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator-=(double value)
{
    this->real -= value;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator*=(const lineage::complex_number &other)
{
    // (a + bi)(c + di) = (ac - bd) + (ad + bc)i
    this->real = this->real * other.real - this->imaginary * other.imaginary;
    this->imaginary = this->real * other.imaginary + this->imaginary * other.real;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator*=(double factor)
{
    this->real *= factor;
    this->imaginary *= factor;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator/=(const lineage::complex_number &other)
{
    // (a + bi) / (c + di) = (a + bi)(c - di) / (c + di)(c - di)
    double denominator = other.real * other.real + other.imaginary * other.imaginary;
    this->real = (this->real * other.real + this->imaginary * other.imaginary) / denominator;
    this->imaginary = (this->imaginary * other.real - this->real * other.imaginary) / denominator;
}

lineage::complex_number &lineage::complex_number::operator/=(double divisor)
{
    this->real /= divisor;
    this->imaginary /= divisor;
    return *this;
}

lineage::complex_number &lineage::complex_number::operator-() 
{
    this->real = -this->real;
    this->imaginary = -this->imaginary;
    return *this;
}

bool lineage::complex_number::operator==(const lineage::complex_number &other) const
{
    return real == other.real && imaginary == other.imaginary;
}

bool lineage::complex_number::operator==(double value) const
{
    return real == value && imaginary == 0.0;
}

bool lineage::complex_number::operator!=(const lineage::complex_number &other) const
{
    return real != other.real || imaginary != other.imaginary;
}

bool lineage::complex_number::operator!=(double value) const
{
    return real != value || imaginary != 0.0;
}

bool lineage::complex_number::operator<(const lineage::complex_number &other) const
{
    return real < other.real && imaginary < other.imaginary;
}

bool lineage::complex_number::operator<(double value) const
{
    return real < value && imaginary == 0.0;
}

bool lineage::complex_number::operator<=(const lineage::complex_number &other) const
{
    return real <= other.real && imaginary <= other.imaginary;
}

bool lineage::complex_number::operator<=(double value) const
{
    return real <= value && imaginary == 0.0;
}

bool lineage::complex_number::operator>(const lineage::complex_number &other) const
{
    return real > other.real && imaginary > other.imaginary;
}

bool lineage::complex_number::operator>(double value) const
{
    return real > value && imaginary == 0.0;
}

bool lineage::complex_number::operator>=(const lineage::complex_number &other) const
{
    return real >= other.real && imaginary >= other.imaginary;
}

bool lineage::complex_number::operator>=(double value) const
{
    return real >= value && imaginary == 0.0;
}

lineage::complex_number lineage::complex_number::conjugate() const
{
    return complex_number(real, -imaginary);
}

lineage::complex_number &lineage::complex_number::conjugated()
{
    this->imaginary = -this->imaginary;
    return *this;
}
