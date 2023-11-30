#include <iostream>
#include "factorial.h"

long long factorial(uint8_t length)
{
	if (length == 0)
	{
		return 1;
	}
	else
	{
		return length * factorial(length - 1);
	}
}