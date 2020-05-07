#include <iostream>
#include <complex>
#include <math.h>
#include "solver.hpp"
using namespace std;
namespace solver
{

double solve(const RealVariable& x)
{
    if (x.a==0){
        if(x.b==0)
          throw string{"unable to solve"};
        return double(-x.c/x.b);
    }
    else{
        if(double(pow(x.b,2)-double(double(4 * x.a) * x.c)) < 0)
          throw string{"discriminant<0"};
        return double((-x.b +sqrt(double(pow(x.b,2)-double(double(4*x.a)*x.c))))) /double(2*x.a);
    }
}

complex<double> solve(const ComplexVariable& x)
{

      if (real(x.a)== 0 && imag(x.a)==0){
      if(imag(x.b)==0&&real(x.b)==0)
        throw string{"unable to solve"};
        return (-x.c/x.b);
      }
    else{
        return complex<double>(-x.b +sqrt(complex<double>(pow(x.b,2)-complex<double>((complex<double>(x.a))*4.0*x.c)))) /complex<double>(2.0*x.a);
    }
}


	//RealPart//
  RealVariable operator==(const RealVariable &n1, const RealVariable &n2)
	{
		return n1-n2;
	}

	RealVariable operator+(const RealVariable &n1, const RealVariable &n2)
	{
		return RealVariable(n1.a+n2.a , n1.b+n2.b , n1.c+n2.c);
	}

	RealVariable operator-(const RealVariable &n1, const RealVariable &n2)
	{
		return RealVariable(n1.a-n2.a , n1.b-n2.b , n1.c-n2.c);
	}

	RealVariable operator*(const RealVariable &n1, const RealVariable &n2)
	{

		return RealVariable(n1.a * n2.c + n1.b * n2.b + n1.c * n2.a
                      , n1.b * n2.c + n1.c * n2.b
                      , n1.c * n2.c);
	}

	RealVariable operator/(const RealVariable &n1, double n2)
	{
		if(n2 == 0){
			throw runtime_error("can't divide by 0");
		}
		return RealVariable(n1.a/n2 , n1.b/n2 , n1.c/n2);
	}

	RealVariable operator^(const RealVariable &n1, int n2)
	{
		if (n2 == 0)
			return RealVariable(1);

		if (n2 == 1)
			return n1;

		if (n2 == 2)
			return n1*n1;
	}

  //ComplexPart//

	ComplexVariable operator+(const ComplexVariable& n1, const ComplexVariable& n2)
	{
		return ComplexVariable(n1.a+n2.a , n1.b+n2.b , n1.c+n2.c);
	}

	ComplexVariable operator-(const ComplexVariable& n1, const ComplexVariable& n2)
	{
		return ComplexVariable(n1.a-n2.a , n1.b-n2.b , n1.c-n2.c);
	}

	ComplexVariable operator*(const ComplexVariable& n1, const ComplexVariable& n2)
	{

		return ComplexVariable(n1.a * n2.c + n1.b * n2.b + n1.c * n2.a
                          ,n1.b * n2.c + n1.c * n2.b
                          ,n1.c * n2.c);
	}

	ComplexVariable operator/(const ComplexVariable& n1, double n2)
	{
		if(n2 == (0,0)){
			throw runtime_error("can't divide by 0");
		}
		return ComplexVariable(n1.a/n2 , n1.b/n2 , n1.c/n2);
	}


	ComplexVariable operator==(const ComplexVariable& n1, const ComplexVariable& n2)
	{
		return n1-n2;
	}

	ComplexVariable operator^(const ComplexVariable& n1, int n2)
	{
		if (n2 == 0)
			return ComplexVariable(1);

		if (n2 == 1)
			return n1;

		if (n2 == 2)
			return n1*n1;
	}

}
