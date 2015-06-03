#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED

#include <random>
using namespace std;

class randomizer
{
private:
	static int __offset;
	random_device __rd;
	mt19937_64 __e;
	uniform_int_distribution<unsigned> __u_int;
	uniform_real_distribution<long double> __u_real;
	normal_distribution<long double> __nor;

public:
	randomizer();
	randomizer(double aveg,double stddev);
	randomizer(unsigned Min,unsigned Max);
	unsigned getUniformInt();
	long double getUniformReal();
	long double getNormalReal();
};

#endif
