#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "../../Player/include/Player.h"
#include "../../func/include/func.h"
#include "../../Randomizer/include/Randomizer.h"
using namespace std;

int main()
{
    int n,m,mode,spec_n;
    double stdaver,stddev,spec_aver,spec_std;
    vector<player*> v;
    cout<<"Input normal amount and repeat times:"<<endl;
    cin>>n>>m;
    cout<<"Input number to choose the distributing mode:\n==================================================\n1:Uniform Distribution\n2:Gaussian Distribution"<<endl;
    cin>>mode;
    switch (mode)
    {
    case 1:
        stdaver=0.5;
        break;
    case 2:
        cout<<"Input the average and standard deviation:"<<endl;
        cin>>stdaver>>stddev;
        break;
    default:
        cout<<"Error mode."<<endl;
        system("pause");
        return 0;
    };
    randomizer Random(stdaver,stddev);
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
		cout<<"Input number to choose the generate mode:\n==================================================\n1:Insert new special players\n2:choose from existed players"<<endl;
		cin>>mode;
		switch (mode)
		{
			case 1:
			{
				cout<<"Input the average and standard deviation:"<<endl;
				cin>>spec_aver>>spec_std;
				randomizer specRandom(spec_aver,spec_std);
				for (int i=1;i<=spec_n;i++)
					generateSpecialPlayer(specRandom,v);
				break;
			}
			case 2:
			{
				cout<<"Input the average:"<<endl;
				cin>>spec_aver;
				chooseSpecialPlayer(spec_n,spec_aver,v);
			}
		}
    }

    cout<<endl<<"Running..."<<endl;

    while (m--)
        match(Random,v);

    sort(v.begin(),v.end(),sortByDown);
    cout<<endl;

    if (spec_n)
        printSpecialReport(v);

    printRangedDistribution(v);

    printRankedWinCount(v);

    for (unsigned i=0;i<v.size();i++)
        delete(v[i]);

    return 0;
}
