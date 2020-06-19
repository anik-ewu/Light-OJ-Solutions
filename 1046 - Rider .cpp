#include<bits/stdc++.h>
using namespace std;

int vis[11][11];
int sum[11][11];
int cnt[11][11];
int aux[11][11];
char mat[11][11];

int X[]={1,  1, 2,  2, -1, -1, -2, -2};
int Y[]={2, -2, 1, -1,  2, -2,  1, -1};

bool check(int x, int y, int n, int m){
    if(x>=1 and y>=1 and x<=n and y<=m)return true;
    return false;
}

void bfs(int a, int b, int mov, int n, int m){

    queue< pair < int , pair < int, int > > > q;
    q.push({a,{b,0}});
    cnt[a][b]++;

    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second.first;
        int c=q.front().second.second;
        vis[a][b]=1;
        q.pop();
        for(int i=0; i<8; i++){
            int dx=a+X[i];
            int dy=b+Y[i];
            if(check(dx,dy,n,m)){
               if(vis[dx][dy]==0){
               q.push({dx,{dy,c+1}});
               aux[dx][dy]=c+1;
               vis[dx][dy]=1;
               cnt[dx][dy]++;
               }
               else if(aux[dx][dy]>c+1){
                aux[dx][dy]=c+1;
               }
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(aux[i][j]%mov!=0)sum[i][j]++;
            aux[i][j]/=mov;
            sum[i][j]+=aux[i][j];
        }
    }
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t,tc,i,j,k,l,m,n,ans,knight;
    cin>>t;
    for(tc=1; tc<=t; tc++){
        cin>>n>>m;
        knight=0;
        memset(sum,0,sizeof(sum));
        memset(cnt,0,sizeof(cnt));
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                cin>>mat[i][j];
            }
        }
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(mat[i][j]!='.'){
                  knight++;
                  memset(vis,0,sizeof(vis));
                  memset(aux,0,sizeof(vis));
                  bfs(i,j,mat[i][j]-'0',n,m);
                }
            }
        }
        ans=INT_MAX;
        for(i=1; i<=n; i++){
            for(j=1; j<=m; j++){
                if(cnt[i][j]==knight)
                ans=min(ans,sum[i][j]);
            }
        }
        if(ans==INT_MAX)ans=-1;
        printf("Case %d: %d\n",tc,ans);
    }

    return 0;
}
