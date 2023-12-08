#ifndef __MATRIX_H
#define __MATRIX_H

#include <functional>
#include <memory>
#include <stdexcept>
#include <vector>

#include "vector.h"

namespace lineage
{
	class matrix
	{
		typedef std::function<double(size_t, size_t)> per_item_generator;
		typedef std::function<vector(size_t)> vector_generator;

	private:
		/**
		 * @brief The data of the matrix, stored as a 1D array of column vectors.
		 *
		 */
		std::unique_ptr<vector[]> m_data = nullptr;
		size_t m_rows = 0;
		size_t m_cols = 0;

	public:
		matrix::matrix(){};
		matrix::matrix(size_t rows, size_t cols);
		matrix::matrix(const lineage::matrix &other);
		matrix::matrix(size_t rows, size_t cols, double value);
		matrix::matrix(size_t rows, size_t cols, double **data);
		matrix::matrix(size_t rows, size_t cols, per_item_generator gen);
		matrix::matrix(size_t rows, size_t cols, bool rowOrColumn, vector_generator gen);
		matrix::matrix(size_t rows, size_t cols, bool rowOrColumn, lineage::vector *data);

		friend void swap(lineage::matrix &first, lineage::matrix &second);
		matrix &operator=(matrix other);
		virtual ~matrix(){};

		static matrix identity(size_t size);
		static matrix zero(size_t rows, size_t cols);

		const vector &operator[](size_t index) const;
		vector &operator[](size_t index);
		const vector &column_vector(size_t index) const;
		vector &column_vector(size_t index);
		const vector &row_vector(size_t index) const;
		vector &row_vector(size_t index);

		const double &at(size_t row, size_t col) const;
		double &at(size_t row, size_t col);

		vector *data() { return m_data.get(); };
		size_t rows() const { return m_rows; };
		size_t cols() const { return m_cols; };

		matrix operator+(const matrix &other) const;
		matrix operator-(const matrix &other) const;
		matrix operator+(double value) const;
		matrix operator-(double value) const;
		matrix operator*(double factor) const;
		matrix operator*(const matrix &other) const;
		vector operator*(const lineage::vector &other) const;
		matrix operator/(double divisor) const;

		matrix &operator+=(const matrix &other);
		matrix &operator+=(double value);
		matrix &operator-=(const matrix &other);
		matrix &operator-=(double value);
		matrix &operator*=(double factor);
		matrix &operator*=(const matrix &other);
		vector &operator*=(const lineage::vector &other) const;
		matrix &operator/=(double divisor);

		matrix &swap_rows(size_t row1, size_t row2);
		matrix &multiply_row(size_t row, double factor);
		matrix &add_rows(size_t row1, size_t row2, double factor);

		matrix transposed() const;
		matrix &transpose();
		matrix normalized() const;
		matrix &normalize();
		matrix orthogonalized() const;
		matrix &orthogonalize();
		matrix orthonormalized() const;
		matrix &orthonormalize();
		matrix inverse() const;
		matrix &invert();
		matrix reduced() const;
		matrix &reduce();

		double determinant() const;
		double trace() const;

		bool is_square() const;
		bool is_symmetric() const;
		bool is_orthogonal() const;
		bool is_orthonormal() const;
		bool is_invertible() const;
		bool is_reduced() const;
		bool is_diagonal() const;
		bool is_identity() const;
		bool is_zero() const;
		bool is_lower_triangular() const;
		bool is_upper_triangular() const;

		std::vector<lineage::vector> null_space() const;
		std::vector<lineage::vector> column_space() const;
		std::vector<lineage::vector> row_space() const;

		int rank() const;
		int nullity() const;

		// TODO: Diagonalization, Eigenvalues, Eigenvectors, etc.
		// I have to find a better algorithm for finding eigenvectors
		matrix *diagonalize();
		std::vector<double> eigenvalues() const;
		std::vector<lineage::vector> eigenvectors() const;
		bool is_defective() const;
		bool lineage::matrix::is_diagonalizable() const;
		bool lineage::matrix::is_eigenvalue(double value) const;
	};
}

#endif // __MATRIX_H