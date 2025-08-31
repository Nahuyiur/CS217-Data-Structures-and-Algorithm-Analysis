#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int INF = 1e9; 

struct Node {
    int d;    
    int pi;   
    int color; // 节点颜色：0=白色，1=灰色，2=黑色
};

void BFS(int N, vector<vector<int>>& adj, vector<Node>& nodes, int source) {
    queue<int> q; 
    nodes[source].color = 1;
    nodes[source].d = 0;    
    q.push(source);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : adj[u]) {
            if (nodes[v].color == 0) { 
                nodes[v].color = 1;  
                nodes[v].d = nodes[u].d + 1; 
                nodes[v].pi = u;     
                q.push(v);
            }
        }
        nodes[u].color = 2; // 访问结束，标记为黑色
    }
}

void PRINT_PATH(vector<Node>& nodes, int source, int target) {
    if (nodes[target].d == INF) { // 如果距离为INF，说明不存在路径
        cout << -1 << endl;
        return;
    }
    vector<int> path;
    int current = target;

    while (current != -1) {
        path.push_back(current);
        if (current == source) break;
        current = nodes[current].pi;
    }

    if (current == -1) { // 无法到达源点
        cout << -1 << endl;
    } else {
        reverse(path.begin(), path.end()); // 反转路径
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i + 1 < path.size() ? " " : "\n");
        }
    }
}

int main() {
    int N, M, S, vy, vz;
    cin >> N >> M;
    cin >> S; // 源点
    vector<vector<int>> adj(N + 1); // 邻接表，1-based 索引
    vector<Node> nodes(N + 1);      // 每个节点的属性

    for (int i = 1; i <= N; ++i) {
        nodes[i] = {INF, -1, 0}; 
    }

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> vy >> vz;

    BFS(N, adj, nodes, S);

    PRINT_PATH(nodes, S, vy);
    PRINT_PATH(nodes, S, vz);

    return 0;
}