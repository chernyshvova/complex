// This is the main DLL file.

#include "stdafx.h"

#include "ComplexLib.h"

namespace ComplexLib
{
	Complex::Complex() {}
	Complex::Complex(double r) :m_real(r), m_imaginary(0) {}
	Complex::Complex(double r, double i) : m_real(r), m_imaginary(i) {}
	Complex::Complex(const Complex & val): m_real(val.m_real), m_imaginary(val.m_imaginary) {}
	Complex::~Complex() {}

	Complex& ComplexLib::Complex::operator =(Complex &lval)
	{
		if (lval.m_real != this->m_real)
		{
			m_real = lval.m_real;
		}
		if (lval.m_imaginary != this->m_imaginary)
		{
			m_imaginary = lval.m_imaginary;
		}
		
		return (*this);
	}
	Complex& Complex::operator += (Complex &lval)
	{
		m_real += lval.m_real;
		m_imaginary += lval.m_imaginary;
		return *this;
	}
	Complex Complex::operator + (const Complex &lval)
	{
		return Complex(m_real + lval.m_real, m_imaginary + lval.m_imaginary);
	}
	Complex Complex::operator - (const Complex &lval)
	{
		return Complex(m_real - lval.m_real, m_imaginary - lval.m_imaginary);
	}
	Complex Complex::operator * (const Complex &lval)
	{
		return Complex(m_real * lval.m_real - m_imaginary * lval.m_imaginary, m_real * lval.m_imaginary + m_imaginary * lval.m_real);
	}
	Complex Complex::operator/(const Complex &lval)
	{
		Complex temp;

		double r = lval.m_real * lval.m_real + lval.m_imaginary * lval.m_imaginary;
		temp.m_real = (m_real * lval.m_real + m_imaginary * lval.m_imaginary) / r;
		temp.m_imaginary = (m_imaginary * lval.m_real - m_real * lval.m_imaginary) / r;

		return temp;
	}

	Complex::operator double()
	{
		return this->get_module();
	}

	double Complex::get_module()
	{
		return sqrt(m_real * m_real + m_imaginary * m_imaginary);
	}


}

