#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
int arr[100005],brr[100005];

int zeros(ll n, int m)
{
    int x=0;
    while(n>0)
    {
        x+=n/m;
        n/=m;
    }
    return x;
}
int zeros2(ll n, int m)
{
    int x=0;
    while(n%m==0)
    {
        x++;
        n/=m;
    }
    return x;
}

int main()
{
    int a,b,c,  n,m,t, l,r, i,j,k,  x,y,z,x2,y2,z2;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d%d%d",&n,&r,&a,&b);

        x=zeros(n,5);
        y=zeros(r,5);
        z=zeros(n-r,5);
        x-=y;
        x-=z;
        z=x;

        x=zeros(n,2);
        y=zeros(r,2);
        z2=zeros(n-r,2);
        x-=y;
        x-=z2;
        z2=x;


        x=zeros2(a,5);
        y=x*b;
        z+=y;


        x=zeros2(a,2);
        y=x*b;
        z2+=y;
        z=min(z,z2);

        printf("Case %d: %d\n",i,z);

    }

    return 0;
}
