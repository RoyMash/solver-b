#include <iostream>
#include <complex>
#include <cmath>
using namespace std;

namespace solver
{
	class RealVariable
	{
		public:

		double a;
		double b;
		double c;

		RealVariable(): a(0), b(1), c(0) {}
		RealVariable(double a, double b, double c) : a(a) , b(b) , c(c){}
		RealVariable(double value): a(0), b(0), c(value){}
		RealVariable(const RealVariable & value){
			a = value.a;
			b = value.b;
			c = value.c;
		}

		friend RealVariable operator+(const RealVariable&, const RealVariable&);
		friend RealVariable operator-(const RealVariable&, const RealVariable&);
		friend RealVariable operator*(const RealVariable&, const RealVariable&);
		friend RealVariable operator/(const RealVariable&, double);
		friend RealVariable operator==(const RealVariable&, const RealVariable&);
		friend RealVariable operator^(const RealVariable&, int);
	};

	class ComplexVariable
	{
		public:
		complex<double> a;
		complex<double> b;
		complex<double> c;

		ComplexVariable(): a(0), b(1), c(0) {}
		ComplexVariable(const complex<double> value): a(0), b(0), c(value) {}
		ComplexVariable(double value): a(0), b(0), c(value) {}
		ComplexVariable(complex<double> a, complex<double> b, complex<double> c) : a(a) , b(b) , c(c){}
		ComplexVariable(const ComplexVariable &value)
		{
			a = value.a;
			b = value.b;
			c = value.c;
		}

		friend ComplexVariable operator==(const ComplexVariable&, const ComplexVariable&);
		friend ComplexVariable operator+(const ComplexVariable&, const ComplexVariable&);
		friend ComplexVariable operator-(const ComplexVariable&, const ComplexVariable&);
		friend ComplexVariable operator*(const ComplexVariable&, const ComplexVariable&);
		friend ComplexVariable operator/(const ComplexVariable&, double);
		friend ComplexVariable operator^(const ComplexVariable&, int);

	};

	double solve(const RealVariable&);
	complex<double> solve(const ComplexVariable&);

}
