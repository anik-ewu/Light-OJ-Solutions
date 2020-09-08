///Date     : 6.6.2020
///Approach : Matrix Exponentiation

#include<bits/stdc++.h>
using namespace std;

#define mod 10007

int a, b, c;

void multiply(int A[4][4], int B[4][4]){

    int res[4][4];
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            res[i][j]=0;
            for(int k=0; k<4; k++){
                long long int val=(A[i][k]*1LL*B[k][j])%mod;
                res[i][j]=(res[i][j]+val)%mod;
            }
        }
    }
    memcpy(A, res, sizeof(res));

}

int power(int n){

    int F[4][4]={{a,0,b,1}, {1,0,0,0}, {0,1,0,0}, {0,0,0,1}};
    int I[4][4]={{1,0,0,0}, {0,1,0,0}, {0,0,1,0}, {0,0,0,1}};

    while(n){
        if(n%2)
            multiply(I,F), n--;
        else
            multiply(F,F), n/=2;
    }
    return(I[0][3]*1LL*c)%mod;

}

int matrix_expo(int n){
    if(n<=2)return 0;
    return power(n-2);
}


int main(){

    int t,n, cs=1;
    cin>>t;
    while(t--){
        cin>>n>>a>>b>>c;
        cout<<"Case "<<cs++<<": "<<matrix_expo(n)<<endl;
    }

    return 0;
}
