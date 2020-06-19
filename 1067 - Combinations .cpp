#include<bits/stdc++.h>
using namespace std;
#define S 1000001
#define M 1000003
long long int arry[S+5];

int modulo_inverse(long long int base, long long int power,int mod)
{
    if(power==0)
        return 1;
    else if(power%2!=0)
    {
        long long int p1=base%mod;
        long long int p2=(modulo_inverse(base,power-1,mod))%mod;
        return (p1*p2)%mod;
    }
    else
    {
        long long int p1=(modulo_inverse(base,power/2,mod))%mod;
        return (p1*p1)%mod;
    }
}


void fill_arry()
{
    int i;
    arry[1]=1;
    for( i=2; i<M; i++)
        arry[i]=((arry[i-1]%M)*(i%M))%M;

}


int main()
{
    long long int ans,b,c,n,r,i,j,k,a;
    fill_arry();
    cin>>k;
    for(i=1; i<=k; i++)
    {
        cin>>n>>r;
        if(n<r)
            ans=0;
        else if(n==r || r==0)
            ans=1;
        else
        {
            a=arry[n]%M;
            b=modulo_inverse(arry[r]*arry[n-r],M-2,M)%M;
            ans=(a*b);
        }
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}
