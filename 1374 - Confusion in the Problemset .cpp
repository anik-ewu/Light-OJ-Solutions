#include<bits/stdc++.h>
using namespace std ;

int arr[1000006];

int main()
{

    int t,n,a,b,i,j,k,x,y,mx;

    vector < int > v,va;

    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        v.clear();
        scanf("%d",&n);

        mx=0;
        for(j=1; j<=n; j++)
        {
            scanf("%d",&a);
            v.push_back(a);
            mx=max(mx,a);
        }
        bool flag =true;
        memset(arr,0,sizeof(arr));

        if(mx>=n)
            flag=false;
        else
        {
            for(j=0; j<n; j++)
            {
                x=v[j];
                y=n-(v[j]+1);
                if(x>y)
                    swap(x,y);
                ///cout<<x<<' '<<y<<endl;
                if(arr[x] and arr[y])
                {
                    flag=false;
                    break;
                }
                else if(!arr[x])
                    arr[x]=1;
                else
                    arr[y]=1;

            }
            for(j=0; j<n; j++)
            {
                if(!arr[j])
                {
                    flag=false;
                    break;
                }
            }
        }
        if(flag)
            printf("Case %d: yes\n",i);
        else
            printf("Case %d: no\n",i);


    }

    return 0;
}

