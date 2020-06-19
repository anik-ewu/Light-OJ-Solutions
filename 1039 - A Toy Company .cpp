#include<bits/stdc++.h>
using namespace std ;
#define sz              27
#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);

bool flag;
int T[sz][sz][sz];
int vis[sz][sz][sz];
string start,last,s1,s2,s3;

int X[] = {0, 0, 1, 0, 0, -1};
int Y[] = {0, 1, 0, 0, -1, 0};
int Z[] = {1, 0, 0, -1, 0, 0};

struct point{
    int x;
    int y;
    int z;
    point(){};
    point(int x, int y, int z){this->x=x; this->y=y; this->z=z;}
};

int bfs(){
    if(vis[start[0]-'a'][start[1]-'a'][start[2]-'a']==false){
        return -1;///start node is forbidden
    }

    int a,b,c;
    queue<point> q;
    point p;
    q.push(point(start[0]-'a',start[1]-'a',start[2]-'a'));
    T[start[0]-'a'][start[1]-'a'][start[2]-'a']=0;

    while(!q.empty()){
        p=q.front();
        q.pop();
        if(p.x==last[0]-'a' && p.y==last[1]-'a' && p.z==last[2]-'a'){
            return T[p.x][p.y][p.z];
        }
        for(int i=0; i<6; i++){
           a=(p.x+X[i])%26;
           b=(p.y+Y[i])%26;
           c=(p.z+Z[i])%26;

           if(a<0)a+=26;
           if(b<0)b+=26;
           if(c<0)c+=26;

           if(vis[a][b][c]!=false){
            vis[a][b][c]=false;
            q.push(point(a,b,c));
            T[a][b][c]=T[p.x][p.y][p.z]+1;
           }
        }
    }
    return -1;
}

int main(){

      FastRead;
      int  ans=0,sum=0,temp;
      int  a,b,c, ic,i,j,k, n,m,l,r, t,q, id,mn,mx;

      cin>>t;
      for(ic=1; ic<=t; ic++){
        cin>>start>>last;
        cin>>n;
        memset(vis,true,sizeof(vis));
        for(m=1; m<=n; m++){
            cin>>s1>>s2>>s3;
            for(i=0; i<s1.size(); i++){
                for(j=0; j<s2.size(); j++){
                    for(k=0; k<s3.size(); k++){
                        vis[s1[i]-'a'][s2[j]-'a'][s3[k]-'a']=false;
                    }
                }
            }
        }
        printf("Case %d: %d\n",ic,bfs());
      }
     return 0;
}
