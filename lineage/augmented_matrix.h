#ifndef __AUGMENTED_MATRIX_H
#define __AUGMENTED_MATRIX_H

#include "matrix.h"

namespace lineage
{
	class augmented_matrix : public matrix
	{
	private:
		size_t m_left_cols = 0;
		size_t m_left_rows = 0;

		size_t m_right_cols = 0;
		size_t m_right_rows = 0;
	public:
		augmented_matrix();
	};

}

#endif // __AUGMENTED_MATRIX_H