#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
#define S 5000050
ll phi[S];
int mark[S];

void phii()
{
    int i,j;

    for(i=2; i<=S; i++)
        phi[i]=i,mark[i]=0;

    for(i=2; i<=S; i++)
    {
        if(!mark[i])
        {
            for(j=i; j<=S; j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
    ll sum=0;
    for(i=2; i<=S; i++)
    {
        sum+=phi[i]*phi[i];
        phi[i]=sum;
    }
}

int main()
{
    phii();
    ll i,a,b,c,t;

    scanf("%llu",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%llu%llu",&a,&b);
        c=phi[b]-phi[a-1];
        printf("Case %llu: %llu\n",i,c);
    }

    return 0;
}



