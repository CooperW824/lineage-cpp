#include <stdexcept>

#include "matrix.h"

lineage::matrix::matrix(size_t rows, size_t cols)
{
    m_data = std::make_unique<lineage::vector[]>(cols);
    for(size_t i = 0; i < cols; i++)
    {
        m_data[i] = lineage::vector(rows);
    }
}

lineage::matrix::matrix(const lineage::matrix &other)
{
    m_data = std::make_unique<lineage::vector[]>(other.cols());
    for (size_t i = 0; i < other.cols(); i++)
    {
        m_data[i] = other.m_data[i];
    }
    
}

lineage::matrix::matrix(size_t rows, size_t cols, complex_number value)
{
    m_data = std::make_unique<lineage::vector[]>(cols);
    for (size_t i = 0; i < cols; i++)
    {
        m_data[i] = lineage::vector(rows, value);
    }
}

lineage::matrix::matrix(size_t rows, size_t cols, complex_number **data)
{
    m_data = std::make_unique<lineage::vector[]>(cols);
    for (size_t i = 0; i < cols; i++)
    {
        m_data[i] = lineage::vector(rows, data[i]);
    }
}

lineage::matrix::matrix(size_t rows, size_t cols, per_item_generator gen)
{
    vector::generator gen2 = [gen, cols](size_t index) -> complex_number
    {
        return gen(index / cols, index % cols);
    };
    m_data = std::make_unique<lineage::vector[]>(cols);
    for (size_t i = 0; i < cols; i++)
    {
        m_data[i] = lineage::vector(rows, gen2);
    }
}

lineage::matrix::matrix(size_t rows, size_t cols, bool rowOrColumn, vector_generator gen)
{
}

lineage::matrix::matrix(size_t rows, size_t cols, bool rowOrColumn, lineage::vector *data)
{
}

void lineage::swap(lineage::matrix &first, lineage::matrix &second)
{
}

lineage::matrix &lineage::matrix::operator=(lineage::matrix other)
{
}

static lineage::matrix identity(size_t size)
{
}

static lineage::matrix zero(size_t rows, size_t cols)
{
}

const lineage::vector &lineage::matrix::operator[](size_t index) const
{
}

lineage::vector &lineage::matrix::operator[](size_t index)
{
}

const lineage::vector &lineage::matrix::column_vector(size_t index) const
{
}

lineage::vector &lineage::matrix::column_vector(size_t index)
{
}

const lineage::vector &lineage::matrix::row_vector(size_t index) const
{
}

lineage::vector &lineage::matrix::row_vector(size_t index)
{
}

const lineage::complex_number &lineage::matrix::at(size_t row, size_t col) const
{
}

lineage::complex_number &lineage::matrix::at(size_t row, size_t col)
{
}

lineage::matrix lineage::matrix::operator+(const lineage::matrix &other) const
{
}

lineage::matrix lineage::matrix::operator-(const lineage::matrix &other) const
{
}

lineage::matrix lineage::matrix::operator+(complex_number value) const
{
}

lineage::matrix lineage::matrix::operator-(complex_number value) const
{
}

lineage::matrix lineage::matrix::operator*(complex_number factor) const
{
}

lineage::matrix lineage::matrix::operator*(const lineage::matrix &other) const
{
}

lineage::vector lineage::matrix::operator*(const lineage::vector &other) const
{
}

lineage::matrix lineage::matrix::operator/(complex_number divisor) const
{
}

lineage::matrix &lineage::matrix::operator+=(const lineage::matrix &other)
{
}

lineage::matrix &lineage::matrix::operator+=(complex_number value)
{
}

lineage::matrix &lineage::matrix::operator-=(const lineage::matrix &other)
{
}

lineage::matrix &lineage::matrix::operator-=(complex_number value)
{
}

lineage::matrix &lineage::matrix::operator*=(complex_number factor)
{
}

lineage::matrix &lineage::matrix::operator*=(const lineage::matrix &other)
{
}

lineage::vector &lineage::matrix::operator*=(const lineage::vector &other) const
{
    // TODO: insert return statement here
}

lineage::matrix &lineage::matrix::operator/=(complex_number divisor)
{
}

lineage::matrix &lineage::matrix::swap_rows(size_t row1, size_t row2)
{
}

lineage::matrix &lineage::matrix::multiply_row(size_t row, complex_number factor)
{
}

lineage::matrix &lineage::matrix::add_rows(size_t row1, size_t row2, complex_number factor)
{
}

lineage::matrix lineage::matrix::transposed() const
{
}

lineage::matrix &lineage::matrix::transpose()
{
}

lineage::matrix lineage::matrix::normalized() const
{
}

lineage::matrix &lineage::matrix::normalize()
{
}

lineage::matrix lineage::matrix::orthogonalized() const
{
}

lineage::matrix &lineage::matrix::orthogonalize()
{
}

lineage::matrix lineage::matrix::orthonormalized() const
{
}

lineage::matrix &lineage::matrix::orthonormalize()
{
}

lineage::matrix lineage::matrix::inverse() const
{
}

lineage::matrix &lineage::matrix::invert()
{
}

lineage::matrix lineage::matrix::reduced() const
{
}

lineage::matrix &lineage::matrix::reduce()
{
}

lineage::complex_number lineage::matrix::determinant() const
{
}

lineage::complex_number lineage::matrix::trace() const
{
}

bool lineage::matrix::is_square() const
{
}

bool lineage::matrix::is_symmetric() const
{
}

bool lineage::matrix::is_orthogonal() const
{
}

bool lineage::matrix::is_orthonormal() const
{
}

bool lineage::matrix::is_invertible() const
{
}

bool lineage::matrix::is_reduced() const
{
}

bool lineage::matrix::is_diagonal() const
{
}

bool lineage::matrix::is_identity() const
{
}

bool lineage::matrix::is_zero() const
{
}

bool lineage::matrix::is_lower_triangular() const
{
}

bool lineage::matrix::is_upper_triangular() const
{
}

std::vector<lineage::vector> lineage::matrix::null_space() const
{
}

std::vector<lineage::vector> lineage::matrix::column_space() const
{
}

std::vector<lineage::vector> lineage::matrix::row_space() const
{
}

int lineage::matrix::rank() const
{
}

int lineage::matrix::nullity() const
{
}

// TODO: Diagonalization, Eigenvalues, Eigenvectors, etc.
// I have to find a better algorithm for finding eigenvectors
lineage::matrix *lineage::matrix::diagonalize()
{
    throw std::logic_error("Not implemented");
}

std::vector<lineage::complex_number> lineage::matrix::eigenvalues() const
{
    throw std::logic_error("Not implemented");
}

std::vector<lineage::vector> lineage::matrix::eigenvectors() const
{
    throw std::logic_error("Not implemented");
}

bool lineage::matrix::is_defective() const
{
    throw std::logic_error("Not implemented");
}

bool lineage::matrix::is_diagonalizable() const
{
    throw std::logic_error("Not implemented");
}

bool lineage::matrix::is_eigenvalue(complex_number value) const
{
    throw std::logic_error("Not implemented");
}
