#include<bits/stdc++.h>
using namespace std;
int grid[25][25],colour[25][25];
int total,w,h;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
bool isOnGrid(int i, int j)
{
    if((i>=1 &&j>= 1 && i<=h && j<=w))
        return true;
    return false;
}

void bfs(int x, int y)
{
    memset(colour,0,sizeof(colour));
    int i,j;
    queue<pair < int, int > >q;
    pair < int, int > p;
    q.push(make_pair(x,y));
    colour[x][y]=1;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            int tx=p.first+fx[k];
            int ty=p.second+fy[k];
            if(isOnGrid(tx, ty))
            {
                if(grid[tx][ty]==1 && colour[tx][ty]==0)
                {
                    colour[tx][ty]==1;
                    total++;
                    q.push(make_pair(tx,ty));
                }
            }
        }
    }
}
int main()
{
    char p;
    int x,n,i,j,cs=1,w,h,l,r;
    cin>>n;
    for(x=1; x<=n; x++)
    {
        cin>>w>>h;
        for(i=1; i<=h; i++)
        {
            for(j=1; j<=w; j++)
            {
                cin>>p;
                if(p=='.')
                    grid[i][j]=1;
                else if(p=='@')
                {
                    grid[i][j]=1;
                    l=i;
                    r=j;
                }
                else
                    grid[i][j]=0;
            }
        }
        total=0;
        bfs(l,r);
        cout<<"Case "<<x<<": "<<total<<endl;
    }
    return 0;
}
