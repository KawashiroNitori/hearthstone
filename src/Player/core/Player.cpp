#include <vector>
#include <iostream>
#include "../include/Player.h"
using namespace std;

int player::__amount=0;

player::player() : __currcount(0),__winsum(0),__losesum(0),__power(0)
{
    __id=++__amount;
    __special=false;
	__wincount.push_back(0);
	__losecount.push_back(0);
}

player::player(long double power) : __currcount(0),__winsum(0),__losesum(0)
{
    __id=++__amount;
    __power=power;
    __special=false;
	__wincount.push_back(0);
	__losecount.push_back(0);
}

player::player(bool special,long double power) : __currcount(0),__winsum(0),__losesum(0)
{
    __id=++__amount;
    __power=power;
    __special=special;
	__wincount.push_back(0);
	__losecount.push_back(0);
}

void player::Win()
{
    __wincount[__currcount]++;
    __winsum++;
    if (__wincount[__currcount]==12)
        countUpdate();
}

void player::Lose()
{
    __losecount[__currcount]++;
    __losesum++;
    if (__losecount[__currcount]==3)
        countUpdate();
}

int player::getPlayerAmount()
{
    return __amount;
}

int player::getID()
{
    return __id;
}

int player::getGameCount()
{
    if (__wincount[__currcount] || __losecount[__currcount])
        return __currcount+1;
    else
        return __currcount;
}

int player::getWinCount()
{
    return __wincount[__currcount];
}

int player::getLoseCount()
{
    return __losecount[__currcount];
}

int player::getWinCount(unsigned i)
{
    if (i<__wincount.size())
        return __wincount[i];
    else
        return -1;
}

int player::getLoseCount(unsigned i)
{
    if (i<__losecount.size())
        return __losecount[i];
    else
        return -1;
}

int player::getTotalWin()
{
    return __winsum;
}

int player::getTotalLose()
{
    return __losesum;
}

long double player::getPower()
{
    return __power;
}

void player::countUpdate()
{
    ++__currcount;
    __wincount.push_back(0);
    __losecount.push_back(0);
}

void player::printInfo()
{
    //cout<<__id<<' '<<__power<<' '<<__special<<endl;
}

bool player::isSpecial()
{
    return __special;
}

long double player::getWinRate(player& a, player& b)
{
    return a.getPower()*(1-b.getPower())/(a.getPower()+b.getPower()-2*a.getPower()*b.getPower());
}


