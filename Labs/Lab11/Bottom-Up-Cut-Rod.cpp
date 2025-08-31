#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p[n+1];
    int r[n+1];
    int s[n+1];

    p[0]=0,r[0]=0,s[0]=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        r[i]=0;
        s[i]=0;
    }

    int q=-1;
    for(int j=1;j<=n;j++){
        q=-1;
        for(int i=1;i<=j;i++){
            int temp=p[i]+r[j-i];
            if(q<temp){
                q=temp;
                s[j]=i;
            }
        }
        r[j]=q;
    }

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