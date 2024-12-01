#include<iostream>
using namespace std;
int[] doCal(int n,int[] &p,int[] &r){
    int q=0;
    if(r[n]>=0)return {r[n],s[n]};
    if(n==0){
        q=0;s[n]=0;
    }else{
        q=-1;
        s=0;
        for(int i=1;i<=n;i++){
            if(q<p[i]+doCal())
        }
    }
}
int main(){
    int n;
    cin>>n;
    int p[n+1];
    int r[n+1];
    int s[n+1];
    for(int i=1;i<=n;i++){
        cin>>p[i];
        r[i]=-1;
    }

    
    for(int i=1;i<=n;i++){
        r[i]=doCal(n,p,r); 
    }
    return 0;
}