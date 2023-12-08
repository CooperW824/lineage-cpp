#include "matrix.h"

lineage::matrix::matrix(size_t rows, size_t cols)
{
	
}

lineage::matrix::matrix(const lineage::matrix &other)
{

}

lineage::matrix::matrix(size_t rows, size_t cols, double value)
{

}

lineage::matrix::matrix(size_t rows, size_t cols, double **data)
{

}

lineage::matrix::matrix(size_t rows, size_t cols, per_item_generator gen)
{

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


const double &lineage::matrix::at(size_t row, size_t col) const
{

}

double &lineage::matrix::at(size_t row, size_t col)
{

}


lineage::matrix lineage::matrix::operator+(const lineage::matrix &other) const
{

}

lineage::matrix lineage::matrix::operator-(const lineage::matrix &other) const
{

}

lineage::matrix lineage::matrix::operator+(double value) const
{

}

lineage::matrix lineage::matrix::operator-(double value) const
{

}

lineage::matrix lineage::matrix::operator*(double factor) const
{

}

lineage::matrix lineage::matrix::operator*(const lineage::matrix &other) const
{

}

lineage::vector lineage::matrix::operator*(const lineage::vector &other) const
{

}

lineage::matrix lineage::matrix::operator/(double divisor) const
{

}


lineage::matrix &lineage::matrix::operator+=(const lineage::matrix &other)
{

}

lineage::matrix &lineage::matrix::operator+=(double value)
{

}

lineage::matrix &lineage::matrix::operator-=(const lineage::matrix &other)
{

}

lineage::matrix &lineage::matrix::operator-=(double value)
{

}

lineage::matrix &lineage::matrix::operator*=(double factor)
{

}

lineage::matrix &lineage::matrix::operator*=(const lineage::matrix &other)
{

}

lineage::vector &lineage::matrix::operator*=(const lineage::vector &other) const
{
	// TODO: insert return statement here
}

lineage::matrix &lineage::matrix::operator/=(double divisor)
{

}


lineage::matrix &lineage::matrix::swap_rows(size_t row1, size_t row2)
{

}

lineage::matrix &lineage::matrix::multiply_row(size_t row, double factor)
{

}

lineage::matrix &lineage::matrix::add_rows(size_t row1, size_t row2, double factor)
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


double lineage::matrix::determinant() const
{

}

double lineage::matrix::trace() const
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

}

std::vector<double> lineage::matrix::eigenvalues() const
{

}

std::vector<lineage::vector> lineage::matrix::eigenvectors() const
{

}
