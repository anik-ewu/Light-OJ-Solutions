#include<bits/stdc++.h>
using namespace std;
vector< int > v[20005], va;
map < int, int > mi;
int color[20005];
int f,g;
int bfs(int s)
{
    queue< int > q;
    q.push(s);
    color[s]=1;
    f++;
    int u,x;
    while(!q.empty())
    {
        u=q.front();
        q.pop();

        for(int i=0; i<v[u].size(); i++)
        {
            x=v[u][i];

            if(color[x]==0)
            {
                q.push(x);

                if(color[u]==1)
                {
                    color[x]=2;
                    g++;
                }
                else
                {
                    color[x]=1;
                    f++;
                }
            }
        }
    }
    x=max(f,g);
    return x;
}
int main()
{
    int i,j,a,b,n,t,x;
    cin>>t;

    for(i=1; i<=t; i++)
    {
        cin>>n;
        while(n--)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);

            if(mi[a]==0)
            {
                mi[a]=1;
                va.push_back(a);
            }

            if(mi[b]==0)
            {
                mi[b]=1;
                va.push_back(b);
            }
        }

        for(j=1; j<=20005; j++)
            color[j]=0;
        x=0;
        for(j=0; j<va.size(); j++)
        {
            if(color[va[j]]==0)
            {
                f=0;
                g=0;
                //cout<<1<<' ';
                x+=bfs(va[j]);

            }
        }

        cout<<"Case "<<i<<": "<<x<<endl;

        for(j=0; j<20002; j++)
            v[j].clear();
        va.clear();
        mi.clear();
    }
    return 0;
}
