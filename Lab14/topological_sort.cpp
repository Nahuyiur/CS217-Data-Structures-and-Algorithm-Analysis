#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


const int WHITE = 0; // 未访问
const int GRAY = 1;  // 正在访问
const int BLACK = 2; // 访问完成

struct Node {
    int d;    
    int f;
    int pi;   
    int color; // 节点颜色：0=白色，1=灰色，2=黑色
};

void dfs_visit(int u,vector<vector<int>>& adj,vector<Node>& nodes,stack<int>& result,bool& hasCycle,int& time){
    nodes[u].color=GRAY;
    nodes[u].d=++time;

    for(int v:adj[u]){
        if(nodes[v].color==WHITE){
            nodes[v].pi=u;
            dfs_visit(v,adj,nodes,result,hasCycle,time);
        }else if(nodes[v].color==GRAY){
            hasCycle=true;
            return;
        }
    }

    nodes[u].color=BLACK;
    nodes[u].f=++time;
    result.push(u);
}

vector<int> topological_sort(int N,vector<vector<int>>& adj,vector<Node>& nodes){
    stack<int> result;
    bool hasCycle=false;
    int time=0;

    for(int u=1;u<=N;u++){
        if(nodes[u].color==WHITE){
            dfs_visit(u,adj,nodes,result,hasCycle,time);
            if(hasCycle)return{-1};
        }
    }

    vector<int> sorted;
    while(!result.empty()){
        sorted.push_back(result.top());
        result.pop();
    }
    return sorted;
}
int main() {
    int N,M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1);
    vector<Node> nodes(N+1);

    for(int i=1;i<=N;i++){
        nodes[i]={0,0,-1,WHITE};
    }

    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    vector<int> result=topological_sort(N,adj,nodes);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}