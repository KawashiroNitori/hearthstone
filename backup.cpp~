#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

uniform_real_distribution<long double> u(0,1);
uniform_int_distribution<unsigned int> ui(0,100000000);
mt19937_64 e(time(NULL));

int n,m,select_n,se,spec_n,orig_n;
char t;
double stdd,spec_std,spec_aver;
long double power[2000001],p,minlim,maxlim,powersum,psum;
int wincount[2000001],losecount[2000001],winsum[2000001],losesum[2000001],speccount[20];
vector<int> v[12][3];

int Randing(int i)
{
    return ui(e)%i;
}

long double calc(long double a,long double b)
{
    //cout<<"    p="<<a<<','<<b<<','<<a*(1-b)/(a+b-2*a*b)<<endl;
    return a*(1-b)/(a+b-2*a*b);
}

void print()
{
    select_n=0;
    powersum=0;
    psum=0;

    for (int j=1;j<=n;j++)
    {
        p=(long double)winsum[j]/m;
        if (p>=minlim && p<=maxlim)
        {
            select_n++;
            powersum+=power[j];
            psum+=(long double)winsum[j]/(winsum[j]+losesum[j]);
        }
    }
    cout<<"\nP="<<psum/select_n<<"\nPower="<<powersum/select_n<<endl<<endl;
}

void match(int n)
{
    int flag=n;
    while (flag)
    {
        flag=0;
        for (int i=0;i<12;i++)
            for (int j=0;j<3;j++)
                if (v[i][j].size()>1)
                {
                    //random_shuffle(v[i][j].begin(),v[i][j].end());
                    //cout<<"i,j:"<<i<<' '<<j<<endl;
                    int s=(v[i][j].size())/2;
                    //cout<<"size,s:"<<v[i][j].size()<<' '<<s<<endl;
                    for (int k=0;k<s;k++/*,cout<<"k,k+s:"<<k<<' '<<k+s<<endl*/)
                        if (u(e)<calc(power[v[i][j][k]],power[v[i][j][k+s]]))
                        {
                            wincount[v[i][j][k]]++;
                            if (wincount[v[i][j][k]]<12)
                            {
                                flag++;
                                v[i+1][j].push_back(v[i][j][k]);
                            }
                            losecount[v[i][j][k+s]]++;
                            if (losecount[v[i][j][k+s]]<3)
                            {
                                flag++;
                                v[i][j+1].push_back(v[i][j][k+s]);
                            }
                        }
                        else
                        {
                            wincount[v[i][j][k+s]]++;
                            if (wincount[v[i][j][k+s]]<12)
                            {
                                flag++;
                                v[i+1][j].push_back(v[i][j][k+s]);
                            }
                            losecount[v[i][j][k]]++;
                            if (losecount[v[i][j][k]]<3)
                            {
                                flag++;
                                v[i][j+1].push_back(v[i][j][k]);
                            }
                        }
                    if (v[i][j].size()%2)
                    {
                        if (v[i+1][j].size()%2)
                            v[i+1][j].push_back(v[i][j][v[i][j].size()-1]);
                        else
                            v[i][j+1].push_back(v[i][j][v[i][j].size()-1]);
                    }
                    v[i][j].clear();
                }
        //cout<<flag<<endl;
    }
}

int main()
{
    bool flag=false;
    srand(time(NULL));
    int mode;
    cout<<"Input normal amount and repeat times:"<<endl;
    cin>>n>>m;
    orig_n=n;
    /*cout<<"Input the min limit and max limit:"<<endl;
    cin>>maxlim>>minlim;
    if (maxlim<minlim)
    {
        long double t=maxlim;
        maxlim=minlim;
        minlim=t;
    }*/
    cout<<"Input number to choose the distributing mode:\n==================================================\n1:Uniform Distribution\n2:Gaussian Distribution"<<endl;
    cin>>mode;

    switch (mode)
    {
    case 1:
        for (int i=1;i<=n;i++)
            power[i]=u(e);
        break;
    case 2:
        cout<<"Input the standard deviation:"<<endl;
        cin>>stdd;
        flag=true;
        break;
    default:
        cout<<"Error mode."<<endl;
        system("pause");
        return 0;
    };

    normal_distribution<long double> nor(0.5,stdd);
    if (flag)
        for (int i=1;i<=n;i++)
            power[i]=nor(e);

    cout<<"Input the special amount(input 0 to skip):"<<endl;
    cin>>spec_n;
    if (spec_n)
    {
        n+=spec_n;
        cout<<"Input special average and standard deviation:"<<endl;
        cin>>spec_aver>>spec_std;
        normal_distribution<long double> spe(spec_aver,spec_std);
        for (int i=orig_n+1;i<=n;i++)
            power[i]=spe(e);
    }
/*
    cout<<"Set the special judge?(y/n)";
    cin>>t;
    if (t=='y' || t=='Y')
    {
        cout<<"Input the special power:";
        cin>>power[0];
        cout<<endl;
        for (int i=1;i<=n;i++)
            if (u(e)<calc(power[0],power[i]))
                wincount[0]++;
            else
                losecount[0]++;
        cout<<"Special P="<<(double)wincount[0]/(double)(wincount[0]+losecount[0])<<endl<<endl;
        cout<<"Run the normal simulation?(y/n)";
        cin>>t;
        if (t!='y' && t!='Y')
            return 0;
    }*/

    cout<<"\nRunning...";
    //cout<<endl;
    memset(winsum,0,sizeof(winsum));
    memset(losesum,0,sizeof(losesum));
    memset(speccount,0,sizeof(speccount));
    select_n=0;
    powersum=0;
    psum=0;
    random_shuffle(power,power+n+1,Randing);

    for (int i=1;i<=m;i++)
    {
        memset(wincount,0,sizeof(wincount));
        memset(losecount,0,sizeof(losecount));

        for (int j=1;j<=n;j++)
            v[0][0].push_back(j);
        //random_shuffle(v[0][0].begin(),v[0][0].end(),Randing());
        match(n);
        for (int j=1;j<=n;j++)
        {
            winsum[j]+=wincount[j];
            losesum[j]+=losecount[j];
        }

        for (int j=orig_n+1;j<=n;j++)
            speccount[wincount[j]]++;

    }
    se=0;
    cout<<endl<<endl;

    if (spec_n)
    {
        cout<<"Special report:"<<endl;
        for (int i=0;i<=12;i++)
        {
            int j;
            double temp=(double)((double)speccount[i]/(double)(m*spec_n))*100;
            if (i<10)
                cout<<' ';
            cout<<i<<" Wins:|";
            for (j=1;j<=(int)(temp*0.45+0.5);j++)
                cout<<'*';
            for (;j<=45;j++)
                cout<<'-';
            cout<<'|';
            cout<<speccount[i]<<" time,"<<(double)((double)speccount[i]/(double)(m*spec_n))*100<<'%'<<endl;
        }
    }

    cout<<endl;

    while (++se)
    {
        cout<<"Section "<<se<<":Input min limit and max limit(input -1 -1 to quit):"<<endl;
        cin>>minlim>>maxlim;
        if (minlim==-1 && maxlim==-1)
            break;
        print();
    }
    cout<<endl;
    system("pause");
    return 0;
}
