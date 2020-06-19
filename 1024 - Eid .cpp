#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector < long long int > v;
    long long int i,j,k, a,b,c, x,y,z,t,n;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>n;
        for(j=1; j<=n; j++)
        {
            cin>>a;
            v.push_back(a);
        }
        for(j=0; j<n; j++)
        {
            if(j==0)
                a=v[j];
            else
            {
                b=a*v[j];
                c=__gcd(a,v[j]);
                b/=c;
                a=b;
            }

        }
        cout<<"Case "<<i<<": "<<a<<endl;
        v.clear();
    }
    return 0;
}
