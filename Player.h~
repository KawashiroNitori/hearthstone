#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <vector>
using namespace std;

class player
{
private:
    static int __amount;
    bool __special;
    int __id;
    int __currcount;
    vector<int> __wincount;
    vector<int> __losecount;
    int __winsum;
    int __losesum;
    long double __power;
public:
    player();
    player(long double power);
    player(bool special,long double power);
    void Win();
    void Lose();
    static int getPlayerAmount();
    int getID();
    int getGameCount();
    int getWinCount();
    int getLoseCount();
    int getWinCount(unsigned i);
    int getLoseCount(unsigned i);
    int getTotalWin();
    int getTotalLose();
    long double getPower();
    void countUpdate();
    bool isSpecial();
    static long double getWinRate(player& a,player& b);
};

#endif // PLAYER_H_INCLUDED
