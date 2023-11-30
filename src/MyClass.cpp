#include "MyClass.h"
#include "math.h"

MyClass::MyClass(double in) : input(in)
{
    test = in *2;
}

double MyClass::pow(int pow)
{
    return powf64(input, (double)pow);
}