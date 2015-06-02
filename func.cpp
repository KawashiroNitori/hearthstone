#include <vector>
#include <random>
#include <iostream>
#include <ctime>
#include <cstring>
#include <algorithm>
#include "Player.h"
#include "Randomizer.h"
using namespace std;

int getShuffle(int i)
{
    static randomizer Random(0,0xffffffff);
    return Random.getUniformInt()%i;
}

void generateUniformDistribution(randomizer &Random,vector<player> &v)
{
	player* tempPlayerPtr=new player(Random.getUniformReal());
	player tempPlayer=*tempPlayerPtr;
	delete(tempPlayerPtr);
	v.push_back(tempPlayer);
}

void generateGaussianDistribution(randomizer &Random,vector<player> &v)
{
	player* tempPlayerPtr=new player(Random.getNormalReal());
	player tempPlayer=*tempPlayerPtr;
	delete(tempPlayerPtr);
	v.push_back(tempPlayer);
}

void generateSpecialPlayer(randomizer &Random,vector<player> &v)
{
	player* tempPlayerPtr=new player(true,Random.getNormalReal());
	player tempPlayer=*tempPlayerPtr;
	delete(tempPlayerPtr);
	v.push_back(tempPlayer);
}

void match(randomizer &Random,vector<player> &v)
{
    int s;
    vector<player> g[13][4];
    //random_shuffle(v.begin(),v.end(),getShuffle);

    g[0][0]=v;
    for (int i=0;i<12;i++)
        for (int j=0;j<3;j++)
        {
            s=g[i][j].size()/2;
            for (int k=0;k<s;k++)
                if (Random.getUniformReal() < player::getWinRate(g[i][j][k],g[i][j][k+s]))
                {
                    g[i][j][k].Win();
                    if (g[i][j][k].getWinCount()<12)
                        g[i+1][j].push_back(g[i][j][k]);
                    g[i][j][k+s].Lose();
                    if (g[i][j][k+s].getLoseCount()<3)
                        g[i][j+1].push_back(g[i][j][k+s]);
                }
                else
                {
                    g[i][j][k+s].Win();
                    if (g[i][j][k+s].getWinCount()<12)
                        g[i+1][j].push_back(g[i][j][k+s]);
                    g[i][j][k].Lose();
                    if (g[i][j][k].getLoseCount()<3)
                        g[i][j+1].push_back(g[i][j][k]);
                }
            if (g[i][j].size()%2)
            {
                if (g[i+1][j].size()%2)
                    g[i+1][j].push_back(g[i][j][g[i][j].size()-1]);
                else
                    g[i][j+1].push_back(g[i][j][g[i][j].size()-1]);
            }
        }
}

void printSpecialReport(vector<player> &v)
{
    const int LENPROGESS=45;

    int spec_n=0,j;
    int speccount[13];
    double percent;

    memset(speccount,0,sizeof(speccount));
    for (unsigned i=0;i<v.size();i++)
        if (v[i].isSpecial())
        {
            spec_n++;
            for (int j=0;j<v[i].getGameCount();j++)
                speccount[v[i].getWinCount(j)]++;
        }

    cout<<"Special report:"<<endl;
    for (int i=0;i<=12;i++)
    {
        percent=(double)((double)speccount[i]/(double)(v.size()*spec_n))*100;
        if (i<10)
            cout<<' ';
        cout<<i<<" Wins:|";
        for (j=1;j<=(int)(percent*((double)LENPROGESS/100)+0.5);j++)
            cout<<'*';
        for (;j<=LENPROGESS;j++)
            cout<<'-';
        cout<<'|';
        cout<<speccount[i]<<" times,"<<percent<<'%'<<endl;
    }
    cout<<endl;
}

void printRangedDistribution(vector<player> &v)
{
    int se=0;
    long double select_n,powersum,psum,p,minlim,maxlim;

    while (++se)
    {
        cout<<"Section "<<se<<":Input min limit and max limit(input \'q\' to quit):"<<endl;
        cin>>minlim;
        if (minlim=='q')
            break;
        cin>>maxlim;

        select_n=0;
        powersum=0;
        psum=0;
        for (unsigned i=0;i<v.size();i++)
        {
            p=(long double)v[i].getTotalWin()/v[i].getGameCount();
            if (p>=minlim && p<=maxlim)
            {
                select_n++;
                powersum+=v[i].getPower();
                psum+=(long double)v[i].getTotalWin()/(v[i].getTotalWin()+v[i].getTotalLose());
            }
        }
        cout<<"\nP="<<psum/select_n<<"\nPower="<<powersum/select_n<<endl<<endl;
    }
    cout<<endl;
}
