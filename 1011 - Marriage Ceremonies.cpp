#include<bits/stdc++.h>
using namespace std;
int n;
int w[16][16];
int dp[(1<<16)+2];

bool check(int N, int pos){
    return (bool) (N & (1<<pos));
}

int Set(int N, int pos){
    return N=N | (1<<pos);
}


int call(int pos, int mask){

    if(mask==(1<<n)-1)
       return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int ans=0,sum;
    for(int i=0; i<n; i++){

        sum=0;
        if(check(mask,i)==0){
            int temp=mask;
            sum+=w[pos][i]+call(pos+1,Set(temp,i));
        }
        ans=max(ans,sum);
    }
    return dp[mask]=ans;
}

int main(){
    int i,j,k=1, t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>n;
        for(i=0; i<n; i++){
            for(j=0; j<n; j++)
                cin>>w[i][j];
        }
        cout<<"Case "<<k++<<": "<<call(0,0)<<endl;
    }
    return 0;
}
