#include<bits/stdc++.h>
using namespace std;
#define mod 1000
typedef long long int ll;
int big_mod(ll base, ll power)
{
    if(power==0)
        return 1;
    else if(power%2!=0)
    {
        ll p1=base%mod;
        ll p2=(big_mod(base,power-1))%mod;
        return (p1*p2)%mod;
    }
    else
    {
        ll p1 =(big_mod(base,power/2))%mod;
        return (p1*p1)%mod;
    }
}

int first_three(ll n, ll k)
{
    long double x, y;
    x=k*log10(double(n));
    y=x-(int)x;
    y=pow(10.0,y);
    y*=100;
    int ans=y;
    return ans;
}

int main()
{
    long long int n,a,b,c,d,i,j;
    int x,y;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a>>b;
        x=first_three(a,b);
        y=big_mod(a,b);
        printf("Case %lld: %d %03d\n",i,x,y);

    }
    return 0;

}
