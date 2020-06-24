///Date     : 23.6.2020
///Approach : Inclusion Exclusion + Stars and Bars Method

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 100000007

ll arr[11];
ll brr[11];
ll invfac[22];

int ncr(int n, int k){
    if(n<0)return 0;
    n=(n+k);
    ll ans=1;
    for(int i=0; i<k; i++){
        ans=(ans*(n-i+mod))%mod;
    }
    ans=(ans*invfac[k])%mod;
    return ans;
}

ll power(int b, int p){
    if(p==0)return 1;
    ll res=power(b,p/2)%mod;
    res=(res*res)%mod;
    if(p%2)res=(res*b)%mod;
    return res;
}

void inv(){
    invfac[0]=1;
    for(int i=1; i<=20; i++){
        invfac[i]=(invfac[i-1]*1LL*power(i,mod-2))%mod;
    }
}

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    inv();///calculating inverse factorial
    int n,k,t,i,cs=1;
    cin>>t;
    while(t--){
        cin>>k>>n;
        int total=0;
        int Max=0;
        for(i=0; i<k; i++){
            cin>>arr[i]>>brr[i];
            total+=arr[i];
        }
        ll ans=0;
        for(int mask=0; mask<(1<<k); mask++){
            int temp=total;
            for(int j=0; j<k; j++){
                if(mask &(1<<j)){
                    temp-=arr[j];
                    temp+=brr[j]+1;
                }
            }
        if(__builtin_popcount(mask)%2==1)
            ans=(ans+mod-ncr(n-temp,k-1))%mod;
        else
            ans=(ans+ncr(n-temp,k-1))%mod;
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;

    }
    return 0;
}
