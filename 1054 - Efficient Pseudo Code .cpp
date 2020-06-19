#include<bits/stdc++.h>
using namespace std;

#define sz  1000007
#define lld long long

bool mark[sz+5];
vector < long long > prime;
long long mod = 1000000007;

void sieve(){

    int i,j;
    prime.push_back(2);
    for(i=0; i<sz; i++)mark[i]=false;
    for(i=4; i<sz; i+=2)mark[i]=true;

    for(i=3; i*i<sz; i+=2){
        if(mark[i]==false){
            for(j=i*i; j<sz; j+=(i*2))
                mark[j]=true;
        }
    }
    for(i=3; i<sz; i+=2)
        if(mark[i]==false)prime.push_back(i);
}

lld big_mod(lld b, lld p){

    lld r=1;
    while(p>0){
        if(p%2==1){
            r=(r*b)%mod;
        }
        p/=2;
        b=(b*b)%mod;
    }
    return r;
}

lld find_ans(lld n, lld m){

    lld i,cnt,ans=1,p,e;
    for(i=0; i<prime.size() and prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            cnt=0;
            while(n%prime[i]==0){
                cnt++;
                n/=prime[i];
            }
           lld p,e;
           p=prime[i],e=cnt;
           ans = (ans * (big_mod(p, e * m + 1) - 1 + mod)) % mod;
           ans = (ans * big_mod(p - 1, mod - 2)) % mod;
        }
    }
    if(n>1){
           p=n,e=1;
           ans = (ans * (big_mod(p, e * m + 1) - 1 + mod)) % mod;
           ans = (ans * big_mod(p - 1, mod - 2)) % mod;

    }
    return ans;
}

int main(){

    sieve();
    lld i,j,k,t,n,m,ans;
    scanf("%lld",&t);

     for(i=1; i<=t; i++){
        scanf("%lld%lld",&n,&m);
        ans=find_ans(n,m)%mod;
        printf("Case %lld: %lld\n",i,ans);
     }

    return 0;
}

/*
4
1000000007 7
1000000007 1
1000000008 7
1000000006 4
*/
