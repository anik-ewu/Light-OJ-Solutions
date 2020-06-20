///Date     : 20.6.2020
///Approach : Inclusion Exclusion
///Notes    : for years 2,4,6 we will only consider 2, as others are multiple of it ans so on

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll arr[16];
vector < ll > v;

ll LCM(ll a , ll b){
    return (a/__gcd(a,b))*b;
}

int cal(ll n, int m){

    int N=n;
    int len =v.size();

    for(int i=1; i<(1<<len); i++){
        int cnt=0;
        ll lcm=1;
        for(int j=0; j<len; j++){
            if(i&(1<<j)){
                cnt++;
                lcm=LCM(lcm, v[j]);
            }
        }
        if(cnt%2==0)n+=(N/lcm);
        if(cnt%2==1)n-=(N/lcm);
    }
    return n;
}

void process(int m){
    v.clear();
    sort(arr+1,arr+m+1);

    for(int i=1; i<=m; i++){
        if(arr[i]){
            v.push_back(arr[i]);
            for(int j=i+1; j<=m; j++){
                if(arr[j]%arr[i]==0){
                    arr[j]=0;///eliminating the numbers that are multiple of arr[i]
                }
            }
        }
    }
}

int main(){

    ll n,m,i,t,cs=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(i=1; i<=m; i++)cin>>arr[i];
        process(m);
        cout<<"Case "<<cs++<<": "<<cal(n,m)<<endl;
    }

    return 0;
}
