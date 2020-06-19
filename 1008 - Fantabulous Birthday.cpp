#include<bits/stdc++.h>
using namespace std;
#define fl(n)           for(int i=0; i<n; i++)
#define fl1(n)          for(int i=1; i<=n; i++)

#define sf              scanf
#define pf              printf
#define pb              push_back
#define nl              printf("\n")
#define ll              long long int

#define F               first
#define S               second
#define PI              2*acos(0.0)

#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))

#define MOD             1000000007
#define MX              INT_MAX
#define Sz              100005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

int dx4[] = { 0, 0, -1, 1 };
int dy4[] = { 1, -1, 0, 0 };

int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { 1, 0, -1, 1, -1, 1, 0, -1 };

char f,g;
string s,p;
double cc,dd,ee;
int arr[1000],brr[1000],crr[1000];
vector< int > v,va,vb;

int main()
{

    ll a,b,c,d,e, i,j,k, t,n,m,  x=0,y=0,z=0;
    ll row,col;
    sf("%lld",&t);
    fl1(t)
    {
        sf("%lld",&a);

        x=sqrt(a);
        y=x*x;
        if(y!=a)
            x++;
        y=x-1;
        y*=y;
        if(a%2==1)
        {
            b=(x*x)-a;
            b++;
            if(b<=x)
            {
                row=b;
                col=x;
            }
            else
            {
                col=a-y;
                row=x;
            }
        }
        cout<<row<<' '<<col<<endl;

    }
    return 0;
}

