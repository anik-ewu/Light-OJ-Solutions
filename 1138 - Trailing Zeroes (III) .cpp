#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
int arr[100005],brr[100005];
ll zeros(ll n)
{
    ll x=0;
    while(n>0)
    {
        x+=n/5;
        n/=5;
    }
    return x;
}

int main()
{
    ll a,b,c,  n,m,t, l,r, i,j,k,  x=0,y,z;

    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a);

        x=a/5;
        y=x*5;

        z=a*5;
        z-=y;
        c=0;
        for(j=0; j<=1000; j+=5)
        {
            x=zeros(z+j);
            if(x==a)
            {
                printf("Case %lld: %lld\n",i,z+j);
                c=1;
                break;
            }
            if(x>a)
                break;
        }
        if(c==0)
            printf("Case %lld: impossible\n",i);
    }

    return 0;
}

