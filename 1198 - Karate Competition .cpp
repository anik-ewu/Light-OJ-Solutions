#include<bits/stdc++.h>
using namespace std ;

int main()
{

    int t,n,a,b,i,j,k,x,y;

    vector < int > v,va;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        v.clear();
        scanf("%d",&n);
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            v.push_back(a);
        }
        va.clear();
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            va.push_back(a);
        }
        sort(v.begin(),v.end());
        ///reverse(v.begin(),v.end());
        sort(va.begin(),va.end());
        reverse(va.begin(),va.end());

        int point =0;
        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                if(v[j]>va[k] and va[k])
                {
                    v[j]=0;
                    va[k]=0;
                    point+=2;
                    break;
                }
            }
        }

        for(j=0; j<n; j++)
        {
            for(k=0; k<n; k++)
            {
                if(v[j] and v[j]==va[k])
                {
                    v[j]=0;
                    va[k]=0;
                    point+=1;
                    break;
                }
            }
        }

        printf("Case %d: %d\n",i,point);
    }

    return 0;
}
