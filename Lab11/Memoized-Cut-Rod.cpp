#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int doCal(int* p,int n,int* r,int* s){
    int q=-1;
    if (n < 0) return 0;  // 防止非法递归调用
    if(r[n]>0)return r[n];
    if(n==0){
        q=0;s[n]=0;
    }else{
        q=-1;
        s[n]=0;
        for(int i=1;i<=n;i++){
            int temp = doCal(p, n - i, r, s);
            if (q < p[i] + temp) {
                q = p[i] + temp;
                s[n] = i;
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

    p[0]=0,r[0]=0,s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        r[i]=-1;
        s[i]=0;
    }

    
    doCal(p,n,r,s);

    cout<<r[n]<<endl;

    vector<int> vec;
    while(n>0){
        vec.push_back(s[n]);
        n-=s[n];
    }

    cout<<vec.size()<<endl;

    std::sort(vec.begin(), vec.end());
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    cout<<endl;
    return 0;
}