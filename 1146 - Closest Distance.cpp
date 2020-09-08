///Date     : 25.6.2020
///Approach : Ternary Search

#include<bits/stdc++.h>
using namespace std;

#define eps 0.000000001

pair < double , double > arr[5];

double EUCLEDIAN_DISTANCE(pair < double , double > A, pair < double , double > B){
    return sqrt((A.first-B.first)*(A.first-B.first)+((A.second-B.second)*(A.second-B.second)));
}

double solve(){
    double ac=EUCLEDIAN_DISTANCE(arr[1],arr[3]);
    double bd=EUCLEDIAN_DISTANCE(arr[2],arr[4]);

    while(abs(ac-bd)>eps){
        pair < double , double > a, b, c, d;

        a.first=(2.0*arr[1].first+arr[2].first)/3.0;
        a.second=(2.0*arr[1].second+arr[2].second)/3.0;
        b.first=(arr[1].first+2.0*arr[2].first)/3.0;
        b.second=(arr[1].second+2.0*arr[2].second)/3.0;


        c.first=(2.0*arr[3].first+arr[4].first)/3.0;
        c.second=(2.0*arr[3].second+arr[4].second)/3.0;
        d.first=(arr[3].first+2.0*arr[4].first)/3.0;
        d.second=(arr[3].second+2.0*arr[4].second)/3.0;

        ac=EUCLEDIAN_DISTANCE(a,c);
        bd=EUCLEDIAN_DISTANCE(b,d);

        if(ac>bd){
            arr[1]=a;arr[3]=c;
        }
        else{
            arr[2]=b;arr[4]=d;
        }
    }
    printf("%0.8f\n",(ac+bd)/2.0);
}

int main(){

    int t,cs=1;
    double a,b,c,d;
    cin>>t;
    while(t--){
        for(int i=1; i<=4; i++)cin>>arr[i].first>>arr[i].second;

        cout<<"Case "<<cs++<<": ";
        solve();
    }

    return 0;
}
