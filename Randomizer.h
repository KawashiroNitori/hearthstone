#ifndef RANDOMIZER_H_INCLUDED
#define RANDOMIZER_H_INCLUDED

#include <random>

class randomizer
{
private:
	static int __offset;
	random_device __rd;
	uniform_int_distribution<unsigned> __u_int;
	uniform_real_distribution<long double> __u_real;
	normal_distribution<long double> __nor;
	mt19937_64 __e; 
public:

}

#endif 
