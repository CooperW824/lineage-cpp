#ifndef __COMPLEX_NUMBER_H
#define __COMPLEX_NUMBER_H

namespace lineage
{
	typedef struct complex_number
	{
		double real;
		double imaginary;

		complex_number() : real(0.0), imaginary(0.0){};
		complex_number(double real, double imaginary) : real(real), imaginary(imaginary){};
		complex_number(const complex_number &other) : real(other.real), imaginary(other.imaginary){};
		complex_number(double real) : real(real), imaginary(0.0){};

		complex_number &operator=(complex_number other);
		complex_number &operator=(double real);

		complex_number operator+(const complex_number &other) const;
		complex_number operator+(double value) const;
		complex_number operator-(const complex_number &other) const;
		complex_number operator-(double value) const;

		complex_number operator*(const complex_number &other) const;
		complex_number operator*(double factor) const;
		complex_number operator/(const complex_number &other) const;
		complex_number operator/(double divisor) const;

		complex_number &operator+=(const complex_number &other);
		complex_number &operator+=(double value);
		complex_number &operator-=(const complex_number &other);
		complex_number &operator-=(double value);

		complex_number &operator*=(const complex_number &other);
		complex_number &operator*=(double factor);
		complex_number &operator/=(const complex_number &other);
		complex_number &operator/=(double divisor);
		complex_number &operator-() ;

		bool operator==(const complex_number &other) const;
		bool operator==(double value) const;
		bool operator!=(const complex_number &other) const;
		bool operator!=(double value) const;
		bool operator<(const complex_number &other) const;
		bool operator<(double value) const;
		bool operator<=(const complex_number &other) const;
		bool operator<=(double value) const;
		bool operator>(const complex_number &other) const;
		bool operator>(double value) const;
		bool operator>=(const complex_number &other) const;
		bool operator>=(double value) const;


		complex_number conjugate() const;
		complex_number &conjugated();
		
	};
}

#endif // __COMPLEX_NUMBER_H