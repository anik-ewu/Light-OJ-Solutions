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
int arr[3000];
int brr[Sz];
vector< int > v[1200];
int d[1200],vis[1200];
int m,k;


void bfs(int s)
{
    queue< int > q;
    q.push(s);
    d[s]=0;
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int vv=v[u][i];
            if(vis[vv]==0)
            {
                vis[vv]=1;
                d[vv]=d[u]+1;
                q.push(vv);
            }
        }
    }
}
void all_clear(int n)
{
    for(int i=0; i<=n; i++)
    {
        d[i]=INT_MAX;
        vis[i]=0;
    }
}

int main()
{

    int a,b,c,e, i,j,t,n,h,  x=0,y=0,z=0;
    sf("%d",&t);
    fl1(t)
    {
        sf("%d%d%d",&k,&n,&m);
        for(j=1; j<=k; j++)
            cin>>arr[j];
        for(j=1; j<=m; j++)
        {
            cin>>a>>b;
            v[a].push_back(b);
        }
        for(j=1; j<=k; j++)
        {
            all_clear(n);
            bfs(arr[j]);
            for(int h=1; h<=n; h++)
                if(d[h]<INT_MAX)
                    brr[h]++;
        }
        x=0;
        for(j=1; j<=n; j++)
            if(brr[j]>=k)
                x++;
        pf("Case %d: %d\n",i,x);
        for(j=1; j<=n; j++)
        {
            v[j].clear();
            brr[j]=0;
        }
    }
    return 0;
}


