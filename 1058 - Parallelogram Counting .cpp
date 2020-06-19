#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


map < ll , ll > mp;
ll arr[1001],brr[1001];

ll cal(int i  , int j){
    ll x1,y1,x2,y2;
    x1=arr[i];y1=brr[i];
    x2=arr[j];y2=brr[j];
    return (sqrt((abs(x1-x2)*2)+(abs(y1-y2)*2)))/2;
}


ll ncr(ll n, ll k){
    ll res = 1;
    if (k>n-k)k = n - k;
    for (ll i = 0; i < k; ++i){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int main(){

    int t, n,i,j,x,y,cs=1;

    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=1; i<=n; i++){
            scanf("%d%d",&arr[i],&brr[i]);
        }

        for(i=1; i<=n; i++){
            for(j=i+1; j<=n; j++){
                ll midpoint=cal(i,j);
                cout<<midpoint<<endl;
                mp[midpoint]++;
            }
        }

        ///map < ll, ll > ::iterator it;
        for(auto it: mp){
            cout<<it.first<<' '<<it.second<<endl;
        }
       mp.clear();
    }

    return 0;
}
