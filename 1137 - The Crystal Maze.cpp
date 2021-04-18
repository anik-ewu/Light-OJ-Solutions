///11-April-2021
///Tags: BFS->Flood fill
///Notes: precaculate for all the result for different component with different id and save them to answer queries

#include<bits/stdc++.h>
using namespace std;

#define read(x)         freopen("in.txt","r",stdin);
#define write(x)        freopen("out.txt","w",stdout);
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";
#define Fast            ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int               N =505;

int n, m;
int res[N*N];
int vis[N][N];
char arr[N][N];

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int bfs(int x , int y, int id){
    queue< pair< int, int > > q;
    q.push({x,y});
    vis[x][y]=id;
    int cnt=0;
    while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        q.pop();

        for(int k=0; k<4; k++){
          int x=r+dx[k];
          int y=c+dy[k];

          if(x>=1 and y>=1 and x<=n and y<=m and arr[x][y]!='#'){
            if(vis[x][y]==0){
                vis[x][y]=id;
                cnt+=(arr[x][y]=='C');
                q.push({x, y});
            }
          }
        }
    }
    res[id]=cnt;
}

int main(){

    Fast;
    //read(x);
    int t, q, x, y;
    cin>>t;
    for(int tc=1; tc<=t; tc++){
        cin>>n>>m>>q;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                cin>>arr[i][j];
            }
        }
        int id=1;
        memset(res, 0, sizeof(res));
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(vis[i][j]==0 and arr[i][j]=='.'){
                    bfs(i, j, id);
                    id++;
                }
            }
        }

        cout<<"Case "<<tc<<":"<<endl;
        while(q--){
            cin>>x>>y;
            id=vis[x][y];
            cout<<res[id]<<endl;
        }
    }



    return 0;
}

