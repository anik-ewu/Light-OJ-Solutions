#include<bits/stdc++.h>
using namespace std;
#define sz 100005
#define mod 1000007
typedef long long ll;
ll arr[sz];

long long GetDiffSum( int n ){

    int i, j;
    long long sum = 0;
    for( i = 0; i < n; i++ )
        for( j = i + 1; j < n; j++ )
            sum += abs( arr[i] - arr[j] ); // abs means absolute value

    long long temp = 0;

    ll cum=0;
    for(i=0; i<n; i++){
        cum+=arr[i];
    }
    for(i=0; i<n;  i++){
        ll x=(arr[i]*1LL*(n-(i+1)));
        temp+=abs(cum-x);
        cum-=arr[i];
    }
    cout<<sum<<' '<<temp<<endl;
    return sum;
}
int main(){

    ll tc, cs=1, n, k, c;
    cin>>tc;
    while(tc--){
        cin>>k>>c>>n>>arr[0];
        for(int i=1; i<n; i++){
            arr[i] = (k * arr[i-1] + c) % mod;
        }
        cout<<"Case "<<cs++<<": "<<GetDiffSum(n)<<endl;
    }
    return 0;
}
