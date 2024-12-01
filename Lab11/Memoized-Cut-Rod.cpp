#include<iostream>
#include <vector>
using namespace std;
int doCal(int[] &p,int n,int[] &r,int[] &s){
    int q=0;
    if(r[n]>=0)return r[n];
    if(n==0){
        q=0;s[n]=0;
    }else{
        q=-1;
        s=0;
        for(int i=1;i<=n;i++){
            if(q<p[i]+doCal(p,n-i,r,s)){
                q=p[i]+doCal(p,n-i,r,s);
                s[n]=i;
            }
        }
    }
    r[n]=q;
    return r[n];
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
        s[i]=0;
    }

    
    for(int i=1;i<=n;i++){
        r[i]=doCal(p,n,r,s); 
    }

    cout<<r[n]<<endl;

    vector<int> vec;
    while(n!=0){
        vec.push_back(s[n]);
        n-=s[n];
    }
    cout<<vec.size()<<endl;

    std::sort(vec.begin(), vec.end());
    for (int n : vec) std::cout << n << " ";
    cout<<endl;
    return 0;
}