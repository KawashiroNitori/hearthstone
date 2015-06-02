#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#include <vector>
#include "Randomizer.h"
using namespace std;

void setParament();
int getShuffle(int i);
void generateUniformDistribution(randomizer &Random,vector<player> &v);
void generateGaussianDistribution(randomizer &Random,vector<player> &v);
void generateSpecialPlayer(randomizer &Random,vector<player> &v);
void match(randomizer &Random,vector<player> &v);
void printSpecialReport(vector<player> &v);
void printRangedDistribution(vector<player> &v);

#endif // FUNC_H_INCLUDED
