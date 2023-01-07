#include "complexnumber.h"
#include <cmath>

complexnumber& complexnumber::operator=(const complexnumber& rhs)
{
	real = rhs.real;
	imaginary = rhs.imaginary;
	return *this;
}

complexnumber& complexnumber::operator+=(const complexnumber& rhs) {
	real += rhs.real;
	imaginary += rhs.imaginary;
	return *this;
}

complexnumber& complexnumber::operator-=(const complexnumber& rhs) {
	real -= rhs.real;
	imaginary -= rhs.imaginary;
	return *this;
}

complexnumber& complexnumber::operator*=(const complexnumber& rhs) {
	real = real * rhs.real - imaginary * rhs.imaginary;
	imaginary = real * rhs.imaginary + imaginary * rhs.real;
	return *this;
}

complexnumber& complexnumber::operator/=(const complexnumber& rhs) {
	double denominator = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
	real = (real * rhs.real + imaginary * rhs.imaginary) / denominator;
	imaginary = (imaginary * rhs.real - real * rhs.imaginary) / denominator;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const complexnumber& rhs) {
	os << rhs.real << ((rhs.imaginary >= 0) ? "+" : "-") << fabs(rhs.imaginary) << "i";
	return os;
}

std::istream& operator>>(std::istream& is, complexnumber& rhs) {
	is >> rhs.real >> rhs.imaginary;
	return is;
}

complexnumber operator+(const complexnumber& lhs, const complexnumber& rhs) {
	complexnumber temp = lhs;
	temp += rhs;
	return temp;
}

complexnumber operator-(const complexnumber& lhs, const complexnumber& rhs) {
	complexnumber temp = lhs;
	temp -= rhs;
	return temp;
}

complexnumber operator*(const complexnumber& lhs, const complexnumber& rhs) {
	complexnumber temp = lhs;
	temp *= rhs;
	return temp;
}

complexnumber operator/(const complexnumber& lhs, const complexnumber& rhs) {
	complexnumber temp = lhs;
	temp /= rhs;
	return temp;
}