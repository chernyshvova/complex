// ComplexLib.h
#include <iostream>
#include <cmath>
#pragma once

namespace ComplexLib {

	class Complex
	{
	public:
		Complex();
		Complex(double real);
		Complex(double real, double imaginary);
		Complex(const Complex & lval);
		~Complex();
		Complex& operator = (Complex &lval);
		Complex& operator += (Complex &lval);
		Complex operator + (const Complex &lval);
		Complex operator - (const Complex &lval);
		Complex operator * (const Complex &lval);
		Complex operator / (const Complex &lval);
		operator double();
		double get_module();
	private:
		double m_real, m_imaginary;
	};
}
