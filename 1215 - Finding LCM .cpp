#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
int arr[100005],brr[100005];
//scanf("%d",&a);
//printf("%d",a);
int main()
{
    ll a,b,c,  n,m,t, l,r, i,j,k,  x,y,z;

    scanf("%lld",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%lld%lld%lld",&a,&b,&l);

        x=__gcd(a,b);
        y=(a*b)/x;
        if(l%y==0)
        {
            c=l/y;
            printf("Case %lld: %lld\n",i,c);
        }
        else
        {
            printf("Case %lld: impossible\n",i);
        }
    }
    return 0;
}

