#ifndef GUARD_complexnumber_h
#define GUARD_complexnumber_h
#include <iostream>

class complexnumber {
public:
	complexnumber() : real(0), imaginary(0) {}
	complexnumber(double re) : real(re), imaginary(0) {}
	complexnumber(double re, double im) : real(re), imaginary(im) {}
	complexnumber(const complexnumber& rhs) : real(rhs.real), imaginary(rhs.imaginary) {}
	complexnumber& operator=(const complexnumber& rhs);
	complexnumber& operator+=(const complexnumber& rhs);
	complexnumber& operator-=(const complexnumber& rhs);
	complexnumber& operator*=(const complexnumber& rhs);
	complexnumber& operator/=(const complexnumber& rhs);
	friend std::istream& operator>>(std::istream& is, complexnumber& rhs);
	friend std::ostream& operator<<(std::ostream& os, const complexnumber& rhs);
private:
	double real;
	double imaginary;
};

complexnumber operator+(const complexnumber& lhs, const complexnumber& rhs);
complexnumber operator-(const complexnumber& lhs, const complexnumber& rhs);
complexnumber operator*(const complexnumber& lhs, const complexnumber& rhs);
complexnumber operator/(const complexnumber& lhs, const complexnumber& rhs);

#endif
