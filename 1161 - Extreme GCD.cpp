///Date     : 20.6.2020
///Approach : Inclusion Exclusion
///Notes    : find all possible ways then eliminate those combinations which has GCD>1
///           relevant: 2,3,6,30 | irrelevant: 12, 18 ( they're included on 6 ans 3)

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sz      10001
#define i64     unsigned long long
#define fast    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int arr[sz];
int brr[sz];
int multi[sz];
bool mark[sz];
i64 dp[10001][5];
vector < int > Prime;
vector < int > distinct;

///calculating nCr
i64 nCr(int n, int r){
    if(n==r) return dp[n][r] = 1;
    if(r==0) return dp[n][r] = 1;
    if(r==1) return dp[n][r] = (i64)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

///calculating Primes
void sieve(){
    memset(mark,0,sizeof(mark));
    for(int i=4; i<sz; i+=2)mark[i]=1;
    for(int i=3; i*i<=sz; i+=2){
        if(mark[i]==0){
            for(int j=i*i; j<=sz; j+=(i*2)){
                mark[j]=1;
            }
        }
    }
    Prime.push_back(2);
    for(int i=3; i<sz; i+=2){
        if(mark[i]==0){
            Prime.push_back(i);
        }
    }
}

///return types of factor in N
int factor(int n){
    int cnt=0;
    for(int i=0; Prime[i]*Prime[i]<=n; i++){
        if(n%Prime[i]==0){
            cnt++;
            n/=Prime[i];
        }
    }
    if(n>1)cnt++;
    return cnt;
}

/// check N is relevant or not
bool distinct_factor(int n){
    for(int i=0; Prime[i]*Prime[i]<=n; i++){
        int cnt=0;
        if(n%Prime[i]==0){
            while(n%Prime[i]==0)cnt++,n/=Prime[i];
        }
        if(cnt>1)return false;
    }
    return true;
}

/// marking the divisors of n
void divisor(int n){
    for(int i=1; i*i<=n; i++){
        if(n%i==0){
            multi[i]++;
            if(n/i!=i)multi[n/i]++;

        }
    }
}


int main(){

    ///freopen("in.txt","w",stdout);

    fast;
    sieve();
    nCr(10000,4);
    i64 t,n,i,ans,cs=1;
    for(i=2; i<sz; i++){
        if(distinct_factor(i)){
            brr[i]=factor(i);
            distinct.push_back(i);
        }
    }
    cin>>t;
    while(t--){
        cin>>n;
        for(i=1; i<=n; i++){
            cin>>arr[i];
        }
        memset(multi,0,sizeof(multi));
        for(i=1; i<=n; i++){
            divisor(arr[i]);
        }
        ans=dp[n][4];///all possible ways
        for(i=0; i<distinct.size(); i++){
            int val=distinct[i];
            int tot=multi[val];
            if(brr[val]%2==1)ans-=dp[tot][4];
            if(brr[val]%2==0)ans+=dp[tot][4];
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;
    }
   return 0;
}

