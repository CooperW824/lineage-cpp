#ifndef MY_CLASS
#define MY_CLASS

class MyClass
{
public:
	MyClass(double in);
	double pow(int pow);

	

	double getInput() const
	{
		return input;
	}

private:
	double test;
	const double input;
};

#endif