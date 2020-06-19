#include<bits/stdc++.h>
using namespace std;

char grid[201][201];
bool mark_fire[201][201];
bool mark_jane[201][201];
int fire_cost[201][201];
int jane_cost[201][201];
vector < pair < int , int > > vp;

int X[]={1, -1, 0, 0};
int Y[]={0, 0, 1, -1};

bool check_fire(int x, int y, int n, int m){
    if(x>=1 and x<=n and y>=1 and y<=m and grid[x][y]!='#' and mark_fire[x][y]==0)return true;
    return false;
}
bool check_jane(int x, int y, int n, int m){
    if(x>=1 and x<=n and y>=1 and y<=m and grid[x][y]!='#' and mark_jane[x][y]==0)return true;
    return false;
}

void bfs_make_fire(int n, int m){

    int i,x,y;
    queue < pair < int , int > > q;
    for(i=0; i<vp.size(); i++){
        x=vp[i].first;
        y=vp[i].second;
        mark_fire[x][y]=1;
        fire_cost[x][y]=0;
        q.push({x,y});
    }
    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int dx=x+X[i];
            int dy=y+Y[i];
            if(check_fire(dx,dy,n,m)){
                q.push({dx,dy});
                mark_fire[dx][dy]=1;
                fire_cost[dx][dy]=1+fire_cost[x][y];
            }
        }
    }
}


int  bfs_save_jane(int x,int y,int n, int m){

    queue < pair < int , int > > q;
    mark_jane[x][y]=1;
    jane_cost[x][y]=1;
    q.push({x,y});

    while(!q.empty()){
        x=q.front().first;
        y=q.front().second;
        q.pop();
        if(x==1 || y==1 || x==n || y==m)return jane_cost[x][y];
        for(int i=0; i<4; i++){
            int dx=x+X[i];
            int dy=y+Y[i];
            if(check_jane(dx,dy,n,m)&& jane_cost[x][y]+1<=fire_cost[dx][dy]){
                q.push({dx,dy});
                mark_jane[dx][dy]=1;
                jane_cost[dx][dy]=1+jane_cost[x][y];
            }
        }
    }
    return -1;
}

void print(int n,int m){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<jane_cost[i][j]<<' ';
        }
        cout<<endl;
    }

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ///freopen("input.txt","r",stdin);

    int t,tc,i,j,n,m,ans,x,y;
    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n>>m;
        vp.clear();
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                cin>>grid[i][j];
                if(grid[i][j]=='J'){x=i;y=j;}
                if(grid[i][j]=='F')vp.push_back({i,j});
            }
        }
        memset(mark_fire,0,sizeof(mark_fire));
        memset(fire_cost,0,sizeof(fire_cost));
        bfs_make_fire(n,m);

        memset(mark_jane,0,sizeof(mark_jane));
        memset(jane_cost,0,sizeof(jane_cost));
        ans=bfs_save_jane(x,y,n,m);
        //print(n,m);
        if(ans!=-1)
        cout<<"Case "<<tc<<": "<<ans<<endl;
        else
        cout<<"Case "<<tc<<": IMPOSSIBLE"<<endl;

    }
    return 0;
}
