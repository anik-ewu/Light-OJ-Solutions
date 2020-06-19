#include<bits/stdc++.h>
using namespace std;
#define sz 21
bool vis[21][21];
char grid[21][21];
int cost[21][21];
vector <pair < int , int > > src,des;
int dx[]={1, -1, 0,  0};
int dy[]={0,  0, 1, -1};

bool check(int x, int y, int n, int m){
    if(x>=1 and x<=n and y>=1 and y<=m and grid[x][y]!='#')return true;
    return false;
}

int bfs(int x, int y, int n, int m){

    queue < pair <int , int > >q;
    q.push({x,y});
    vis[x][y]=1;
    cost[x][y]=0;

    while(!q.empty()){

        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(check(xx,yy,n,m) and vis[xx][yy]==0){
                q.push({xx,yy});
                vis[xx][yy]=1;
                cost[xx][yy]=1+cost[x][y];
            }
        }
    }
}

int main(){

    int tc,t,n,m,i,j,ans;

    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n>>m;
        src.clear();
        des.clear();

        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                cin>>grid[i][j];
                if(grid[i][j]=='m')grid[i][j]='#';
                if(grid[i][j]=='a' || grid[i][j]=='b' || grid[i][j]=='c'){
                    src.push_back({i,j});
                }
                else if(grid[i][j]=='h')
                   des.push_back({i,j});
            }
        }
        memset(vis,0,sizeof(vis));
        memset(cost,0,sizeof(cost));
        bfs(des[0].first,des[0].second,n,m);
        ans=-1;
        for(i=0; i<3; i++){
            ans=max(ans,cost[src[i].first][src[i].second]);
        }
        cout<<"Case "<<tc<<": "<<ans<<endl;
    }



   return 0;

}
