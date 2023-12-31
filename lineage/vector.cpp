#include "vector.h"
#include <cmath>
#include <exception>
#include <stdexcept>


lineage::vector::vector(size_t size)
{
    m_data = std::make_unique<lineage::complex_number[]>(size);
    m_size = size;
}

lineage::vector::vector(const vector &other)
{   
    m_data = std::make_unique<lineage::complex_number[]>(other.m_size);
    for(int i = 0; i < other.m_size; i++)
    {
        m_data[i] = other.m_data[i];
    }
}

lineage::vector::vector(size_t size, lineage::complex_number value)
{
    m_data = std::make_unique<lineage::complex_number[]>(size);
    m_size = size;
    for(int i = 0; i < size; i++)
    {
        m_data[i] = value;
    }
}

lineage::vector::vector(size_t size, lineage::complex_number *data)
{
    m_data = std::make_unique<lineage::complex_number[]>(size);
    m_size = size;
    for(int i = 0; i < size; i++)
    {
        m_data[i] = data[i];
    }
}

lineage::vector::vector(size_t size, generator gen)
{
    m_data = std::make_unique<lineage::complex_number[]>(size);
    m_size = size;
    for(int i = 0; i < size; i++)
    {
        m_data[i] = gen(i);
    }
}

void lineage::swap(lineage::vector &first, lineage::vector &second)
{
    std::swap(first.m_data, second.m_data);
    std::swap(first.m_size, second.m_size);
}

lineage::vector &lineage::vector::operator=(lineage::vector other)
{
    swap(*this, other);
    return *this;
}

lineage::complex_number &lineage::vector::operator[](size_t index)
{
    if(index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

const lineage::complex_number &lineage::vector::operator[](size_t index) const
{
    if(index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

lineage::complex_number &lineage::vector::at(size_t index)
{
    if(index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

const lineage::complex_number &lineage::vector::at(size_t index) const
{
    if(index >= m_size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

lineage::complex_number *lineage::vector::data()
{
    return m_data.get();
}

size_t lineage::vector::size() const
{
    return m_size;
}

lineage::vector lineage::vector::operator+(const lineage::vector &other) const
{
    if(m_size != other.m_size)
        throw std::invalid_argument("Vectors must be the same size");
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] + other.m_data[i];
    }
    return result;
}

lineage::vector lineage::vector::operator-(const lineage::vector &other) const
{
    if(m_size != other.m_size)
        throw std::invalid_argument("Vectors must be the same size");
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] - other.m_data[i];
    }
    return result;
}

lineage::vector lineage::vector::operator+(lineage::complex_number value) const
{
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] + value;
    }
    return result;
}

lineage::vector lineage::vector::operator-(lineage::complex_number value) const
{
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] - value;
    }
    return result;
}

lineage::vector lineage::vector::operator*(lineage::complex_number factor) const
{
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] * factor;
    }
    return result;
}

lineage::vector lineage::vector::operator/(lineage::complex_number divisor) const
{
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] / divisor;
    }
    return result;
}

lineage::vector &lineage::vector::operator+=(const lineage::vector &other)
{
    if(m_size != other.m_size)
        throw std::invalid_argument("Vectors must be the same size");
    for(int i = 0; i < m_size; i++){
        m_data[i] += other.m_data[i];
    }
    return *this;
}

lineage::vector &lineage::vector::operator+=(lineage::complex_number value)
{
    for(int i = 0; i < m_size; i++){
        m_data[i] += value;
    }
    return *this;
}

lineage::vector &lineage::vector::operator-=(const lineage::vector &other)
{
    if(m_size != other.m_size)
        throw std::invalid_argument("Vectors must be the same size");
    for(int i = 0; i < m_size; i++){
        m_data[i] -= other.m_data[i];
    }
    return *this;
}

lineage::vector &lineage::vector::operator-=(lineage::complex_number value)
{
    for(int i = 0; i < m_size; i++){
        m_data[i] -= value;
    }
    return *this;
}

lineage::vector &lineage::vector::operator*=(lineage::complex_number factor)
{
    for(int i = 0; i < m_size; i++){
        m_data[i] *= factor;
    }
    return *this;
}

lineage::vector &lineage::vector::operator/=(lineage::complex_number divisor)
{
    for(int i = 0; i < m_size; i++){
        m_data[i] /= divisor;
    }
    return *this;
}

lineage::complex_number lineage::vector::dot(const lineage::vector &other) const
{
    lineage::complex_number product = 0;
    for(int i = 0; i < m_size; i++)
    {
        product += m_data[i] * other.m_data[i];
    }
}

lineage::vector lineage::vector::cross(const lineage::vector &other) const
{

    if (m_size == 2 && other.m_size == 2)
    {
        lineage::vector result(3, 0.0);
        result[2] = m_data[0] * other.m_data[1] - m_data[1] * other.m_data[0];
        return result;
    }
    else if (m_size != 3 || other.m_size != 3)
    {
        throw std::invalid_argument("Vectors must be 2 or 3 dimensional");
    }
    lineage::vector result(3);
    result[0] = m_data[1] * other.m_data[2] - m_data[2] * other.m_data[1];
    result[1] = m_data[2] * other.m_data[0] - m_data[0] * other.m_data[2];
    result[2] = m_data[0] * other.m_data[1] - m_data[1] * other.m_data[0];
    return result;
}

lineage::vector &lineage::vector::project(const lineage::vector &other)
{
    if(m_size != other.m_size)
        throw std::invalid_argument("Vectors must be the same size");
    lineage::complex_number factor = dot(other) / other.magnitude_squared();
    for(int i = 0; i < m_size; i++)
    {
        m_data[i] = other.m_data[i] * factor;
    }
    return *this;
}

lineage::vector &lineage::vector::normalize()
{
    lineage::complex_number mag = magnitude();
    for(int i = 0; i < m_size; i++)
    {
        m_data[i] /= mag;
    }
    return *this;
}

lineage::vector lineage::vector::normalized() const
{
    lineage::complex_number mag = magnitude();
    lineage::vector result(m_size);
    for(int i = 0; i < m_size; i++)
    {
        result[i] = m_data[i] / mag;
    }
    return result;
}

double lineage::vector::magnitude() const
{
    double sum = 0;
    for(size_t i = 0; i < m_size; i++)
    {
        sum += m_data[i].magnitude_squared();
    }
    return sqrt(sum);
}

double lineage::vector::magnitude_squared() const
{
    double sum = 0;
    for(int i = 0; i < m_size; i++)
    {
        sum += m_data[i].magnitude_squared();
    }
    return sum;
}

