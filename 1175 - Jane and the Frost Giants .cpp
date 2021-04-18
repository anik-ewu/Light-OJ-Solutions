///11-April-2021
///Tags: BFS/Flood Fill
///Notes: Start bfs with the position of fires(there can be multiple fire) then keep track of the grid location
///that is not already in fire and make moves of Jane on those location.

#include<bits/stdc++.h>
using namespace std;

const int N=205;

int n,m;
char g[N][N];
int cost[N][N];
bool vis[2][N][N];
vector< pair< int, int > > fire;

int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};

bool check(int x , int y){
    return (x>=1 and x<=n and y>=1 and y<=m and g[x][y]!='#'); //. J F
}

string bfs(pair< int, int > jane){

    queue< pair< char ,pair< int ,  int > > >q;
    memset(cost, 0, sizeof(cost));
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<fire.size(); i++){
        q.push({'F', {fire[i].first, fire[i].second}});
        vis[0][fire[i].first][fire[i].second]=1;
    }
    q.push({'J', {jane.first, jane.second}});
    vis[1][jane.first][jane.second]=1;
    cost[jane.first][jane.second]=0;

    while(!q.empty()){
        int ch=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        q.pop();

        if(ch=='J' and (x==1 || y==1 || x==n || y==m)){
            string moves;
            stringstream ss;
            ss<<cost[x][y]+1;
            ss>>moves;
            return moves;
            }

        for(int k=0; k<4; k++){
            int u=x+fx[k];
            int v=y+fy[k];

            if(check(u, v)){
                if(ch=='J'){
                    if(vis[0][u][v]==0 and vis[1][u][v]==0){
                        vis[1][u][v]=1;
                        cost[u][v]=cost[x][y]+1;
                        q.push({'J', {u, v}});
                    }
                }
                else{
                    if(vis[0][u][v]==0){
                        vis[0][u][v]=1;
                        q.push({'F',{u, v}});
                    }
                }
            }
        }
    }
	return "IMPOSSIBLE";

}

int main(){

    freopen("in.txt", "r" ,stdin);

    int t;
    pair< int, int > jane;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>m;
        fire.clear();
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>g[i][j];
                if(g[i][j]=='J')jane={i,j};
                if(g[i][j]=='F')fire.push_back({i,j});
            }
        }
        cout<<"Case "<<tc<<": "<<bfs(jane)<<endl;
    }


    return  0;
}
