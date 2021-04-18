///11-April-2021
///Tags: BFS->Flood fill

#include<bits/stdc++.h>
using namespace std;
int w,h;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int grid[25][25],vis[25][25];
bool isOnGrid(int i, int j){
    return (i>=1 &&j>= 1 && i<=h && j<=w);
}

int bfs(int x, int y){

    queue<pair < int, int > >q;
    pair < int, int > p;
    q.push({x,y});
    memset(vis,0,sizeof(vis));
    vis[x][y]=1;
    int total=1;
    while(!q.empty()){
        p=q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int tx=p.first+fx[k];
            int ty=p.second+fy[k];
            if(isOnGrid(tx, ty)){
                if(grid[tx][ty]==1 && vis[tx][ty]==0){
                    vis[tx][ty]=1;
                    total++;
                    q.push(make_pair(tx,ty));
                }
            }
        }
    }
    return total;
}
int main(){

    char p;
    int n,i,j,cs=1,l,r;
    cin>>n;
    for(cs=1; cs<=n; cs++){
        cin>>w>>h;
        for(i=1; i<=h; i++){
            for(j=1; j<=w; j++){
                cin>>p;
                if(p=='.')
                    grid[i][j]=1;
                else if(p=='@'){
                    grid[i][j]=1;
                    l=i;    r=j;
                }
                else
                    grid[i][j]=0;
            }
        }
        int total=bfs(l,r);
        cout<<"Case "<<cs<<": "<<total<<endl;
    }
    return 0;
}
