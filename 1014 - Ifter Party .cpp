#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector <long long int > v;
int main()
{
    long long int i,j,k,a,b,c,l,t,p=0,x=0;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        cin>>p>>l;
        a=p-l;
        if(a<=l)
            cout<<"Case "<<i<<": impossible"<<endl;
        else
        {
            for(j=1; j*j<=a; j++)
            {
                if(a%j==0)
                {
                    if(j>l)
                        v.push_back(j);
                    b=a/j;
                    if(b!=j && b>l)
                        v.push_back(b);
                }
            }
            sort(v.begin(), v.end());
            cout<<"Case "<<i<<": ";
            for(j=0; j<v.size(); j++)
            {
                if(j)
                    cout<<' ';
                cout<<v[j];
            }
            cout<<endl;
            v.clear();
        }
    }
    return 0;
}

