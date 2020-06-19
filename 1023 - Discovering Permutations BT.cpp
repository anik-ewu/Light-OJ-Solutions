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
#define inf             1/0.0
#define PI              2*acos(0.0)
#define fin             freopen("input.txt", "r", stdin)
#define fout            freopen("output.txt", "w", stdout)


#define gcd(x,y)        __gcd(x,y)
#define lcm(a,b)        (a*(b/gcd(a,b)))

#define PS              system("pause")
#define MOD             1000000007
#define MX              INT_MAX
#define Sz              100005
#define FastIO          { ios_base::sync_with_stdio(false); cin.tie(0); }

char f,g;
string p;
double cc,dd,ee;
char arr[Sz],brr[Sz];
vector< int > v,va,vb;

map < int, int > mp;
int k;
void back_track(int n, int m, string s)
{
    if(k==0)
        return;
    if(n==0 && k>0)
    {
        if(s==p)
        {
            k=0;
            return;
        }
        if(p.size()==0)
            p=s;
        cout<<s<<endl;
        k--;
        return;
    }
    for(char i='A'; i<'A'+m; i++)
    {
        if(mp[i]==0)
        {
            mp[i]=1;
            back_track(n-1,m,s+i);
            mp[i]=0;
        }
    }
}

int main()
{
    int a,b,c,d,e, i,j, m,n,t,  x=0,y=0,z=0;
    FastIO;
    cin>>t;
    fl(t)
    {

        cin>>n>>k;
        p="";
        cout<<"Case "<<i+1<<':'<<endl;

        back_track(n,n,"\0");

        mp.clear();
    }

    return 0;
}
