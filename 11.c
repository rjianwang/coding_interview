#include <stdio.h>

int equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < -0.0000001))
		return 1;
	return 0;
}

double powererWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = powererWithUnsignedExponent(base, exponent >> 1);
	result *= result;
	if (exponent & 0x1 == 1)
		result *= base;

	return result;
}

double power(double base, int exponent)
{
	if (equal(base, 0.0))
	{
		return 1.0;
	}

	unsigned int abs_exponent = 
		exponent > 0 ? (unsigned) exponent : (unsigned)(-exponent);
	double result = powererWithUnsignedExponent(base, abs_exponent);
	if (exponent < 0)
		result = 1.0 / result;

	return result;
}

int main(int argc, char* argv[])
{
	printf("0e0: %lf\n", power(0, 0));
	printf("0e-2: %lf\n", power(0, -2));
	printf("1e0: %lf\n", power(1, 0));
	printf("2e0: %lf\n", power(2, 0));
	printf("2e-1: %lf\n", power(2, -1));
	printf("2e32: %lf\n", power(2, 32));
	printf("2e33: %lf\n", power(2, 33));
	printf("0.1e10: %lf\n", power(0.1, 3));
	printf("0.1e-10: %lf\n", power(0.1, -3));

	return 0;
}
