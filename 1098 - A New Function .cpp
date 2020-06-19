#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
int arr[100005],brr[100005];
ll solve(ll  n)
{
    ll i,j,x,y,ans=0;
    for(i=2; i*i<=n; i++)
    {

        x=n/i;
        y=(x*(x+1))/2;
        x=i-1;
        x=(x*(x+1))/2;
        y-=x;
        ans+=y;
        x=n/i;
        y=i*(x-i);
        ans+=y;
    }
    return ans;
}
int main()
{
    ll  a,b,c,  n,m, l,r, i,j,k,  x,y,z;

    cin>>n;
    for(i=1; i<=n; i++)
    {
        scanf("%lld",&a);
        printf("Case %lld: %lld\n",i,solve(a));
    }
    return 0;
}
