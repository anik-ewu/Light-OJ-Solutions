#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q,n,t,i,j,k,a,b;
    vector< int > arry;
    cin>>t;
    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&n,&q);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            arry.push_back(a);
        }
        while(q--)
        {
            scanf("%d%d",&a,&b);
            vector<int>::iterator low,up;
            low=lower_bound(arry.begin(),arry.end(),a);
            up=upper_bound(arry.begin(),arry.end(),b);
            int l=low-arry.begin();
            int u=up-arry.begin();
            int ans=u-l;
            cout<<l<<u<<endl;
            //printf("%d\n",ans);


        }
    }
    return 0;
}
