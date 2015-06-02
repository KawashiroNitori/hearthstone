#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Player.h"
#include "func.h"
#include "Randomizer.h"
using namespace std;

int main()
{
    int n,m,mode,spec_n;
    double stddev,spec_aver,spec_std;
    vector<player*> v;
    cout<<"Input normal amount and repeat times:"<<endl;
    cin>>n>>m;
    cout<<"Input number to choose the distributing mode:\n==================================================\n1:Uniform Distribution\n2:Gaussian Distribution"<<endl;
    cin>>mode;
    switch (mode)
    {
    case 1:
        break;
    case 2:
        cout<<"Input the standard deviation:"<<endl;
        cin>>stddev;
        break;
    default:
        cout<<"Error mode."<<endl;
        system("pause");
        return 0;
    };
    randomizer Random(0.5,stddev);
    switch (mode)
    {
    case 1:
        for (int i=1;i<=n;i++)
            generateUniformDistribution(Random,v);
        break;
    case 2:
        for (int i=1;i<=n;i++)
            generateGaussianDistribution(Random,v);
        break;
    }

    cout<<"Input the special amount(input 0 to skip):"<<endl;
    cin>>spec_n;
    if (spec_n)
    {
        cout<<"Input special average and standard deviation:"<<endl;
        cin>>spec_aver>>spec_std;
        randomizer SpecRandom(spec_aver,spec_std);
        for (int i=1;i<=spec_n;i++)
            generateSpecialPlayer(SpecRandom,v);
    }

    cout<<endl<<"Running...";

    while (m--)
        match(Random,v);

    cout<<endl;
    if (spec_n)
        printSpecialReport(v);

    printRangedDistribution(v);

    system("pause");

    return 0;
}
