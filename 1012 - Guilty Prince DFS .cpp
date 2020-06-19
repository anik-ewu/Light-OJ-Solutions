#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
string s[50],p;
int r,c,ans=0;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

bool is_on_land(int i, int j)
{

    if(i<0 || j<0 || i>=r || j>=c)
        return false;
    if(s[i][j]=='#')
        return false;
    return true;
}

void DFS(int i, int j)
{
    if(is_on_land(i,j))
    {
        s[i][j]='#';
        ans++;
    }
    else
        return;

    for(int k=0; k<4; k++)
    {
        DFS(i+dx[k],j+dy[k]);
    }
}

int main()
{
    int a,b,t,n,i,j,x,y,start,ends;

    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>c>>r;

        for(j=0; j<r; j++)
            cin>>s[j];

        for(j=0; j<r; j++)
        {
            for(int k=0; k<c; k++)
            {
                if(s[j][k]=='@')
                {
                    x=j;
                    y=k;
                    j=100;
                    break;
                }
            }
        }
        ans=0;
        DFS(x,y);
        cout<<"Case "<<i<<": "<<ans<<endl;
    }
    return 0;
}

