#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
char f,g;
string s,p;
map< int, int > mi;
map< string, int > ms;
vector < int > v,va;
int arr[100005],brr[100005];

long long H( int n )
{
    long long res = 0;
    for( int i = 1; i <= n; i++ )
    {
        res=0;
        for(int j=1; j<=i; j++)
        {
            res = res + i/ j;

        }
         arr[i]=res;
        //cout<<res<<' ';
    }
    return res;
}

int main()
{
    ll a,b,c,  n,m,t, l,r, i,j,k,  x,y,z;
    H(100);
    for(i=1; i<=100; i++)
    {
        cout<<arr[i]<<' ';
    }


    //cin>>t;
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        printf("Case %lld: ",i);

    }
    return 0;

}


