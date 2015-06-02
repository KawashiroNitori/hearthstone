#include <iostream>
#include <random>
using namespace std;

int randomizer::__offset=0;

void randomizer::__setRandomSeed() : __rd,__e(rd()+(++__offset)) {}

randomizer::randomizer() : __u_int(0,0xffffffff),__u_real(0,1),__nor(0.5,0.1) 
{
	__setRandomSeed();
}

randomizer::randomizer(double aveg,double stddev) : __u_int(0,0xffffffff),__u_real(0,1),__nor(aveg,stddev)
{
	__setRandomSeed();
}

randomizer::randomizer(unsigned Min,unsigned Max) : __u_int(Min,Max),__u_real(0,1),__nor(0.5,0,1)
{
	__setRandomSeed();
}

unsigned randomizer::getUniformInt()
{
	return __u_int(__e);
}

long double randomizer::getUniformReal()
{
	return __u_real(__e);
}

long double randomizer::getNormalReal()
{
	return __nor(__e);
}

int randomizer::getShuffle(int i)
{
	return getUniformInt()%player::getPlayerAmount();
}


