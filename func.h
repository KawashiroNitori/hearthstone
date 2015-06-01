#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED
#include <vector>
using namespace std;

void setParament();
void generateUniformDistribution(vector<player> &v);
void generateGaussianDistribution(vector<player> &v);
void generateSpecialPlayers(vector<player> &v);
int Randing(int i);
void match(vector<player> &v);
void printSpecialReport(vector<player> &v);
void printRangedDistribution(vector<player> &v);

#endif // FUNC_H_INCLUDED
