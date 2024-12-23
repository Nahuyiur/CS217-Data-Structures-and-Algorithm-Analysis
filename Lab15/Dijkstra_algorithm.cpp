#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Edge {
    int to;
    long long weight;
};

struct Node {
    int id;
    long long distance;
};

// Custom Min-Heap implementation
class MinHeap {
private:
    vector<Node> heap;             // Array representing the heap
    unordered_map<int, int> pos;   // Map to store the position of nodes in the heap

    void heapifyUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[idx].distance < heap[parent].distance) {
                swap(heap[idx], heap[parent]);
                pos[heap[idx].id] = idx;
                pos[heap[parent].id] = parent;
                idx = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int idx) {
        int size = heap.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int smallest = idx;

            if (left < size && heap[left].distance < heap[smallest].distance)
                smallest = left;
            if (right < size && heap[right].distance < heap[smallest].distance)
                smallest = right;

            if (smallest != idx) {
                swap(heap[idx], heap[smallest]);
                pos[heap[idx].id] = idx;
                pos[heap[smallest].id] = smallest;
                idx = smallest;
            } else {
                break;
            }
        }
    }

public:
    void push(Node node) {
        heap.push_back(node);
        pos[node.id] = heap.size() - 1;
        heapifyUp(heap.size() - 1);
    }

    Node extractMin() {
        Node minNode = heap[0];
        pos.erase(minNode.id);
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) {
            pos[heap[0].id] = 0;
            heapifyDown(0);
        }
        return minNode;
    }

    void decreaseKey(int id, long long newDist) {
        int idx = pos[id];
        heap[idx].distance = newDist;
        heapifyUp(idx);
    }

    bool empty() const {
        return heap.empty();
    }

    bool contains(int id) const {
        return pos.find(id) != pos.end();
    }
};


void dijkstra(int N, int source, vector<vector<Edge>>& adj, vector<long long>& dist, vector<int>& parent) {
    // Step 1: Initialise d and π in the usual way
    dist.assign(N + 1, LLONG_MAX);
    parent.assign(N + 1, -1);
    dist[source] = 0;

    // Custom Min-Heap priority queue
    MinHeap pq;
    pq.push({source, 0});

    // Step 2: While Q ≠ ∅ do
    while (!pq.empty()) {
        // Step 5: u = Extract-Min(Q)
        Node current = pq.extractMin();
        int u = current.id;

        // Step 7: For each v ∈ Adj[u] do
        for (Edge& edge : adj[u]) {
            int v = edge.to;
            long long weight = edge.weight;

            // Step 8: If v.d > u.d + w(u, v) then
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;      // Update v.d
                parent[v] = u;                  // Update π

                if (pq.contains(v)) {
                    pq.decreaseKey(v, dist[v]); // Decrease-Key(v)
                } else {
                    pq.push({v, dist[v]});
                }
            }
        }
    }
}

// Function to print the shortest path
void printPath(int source, int target, vector<int>& parent) {
    vector<int> path;
    int current = target;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    if (path[0] == source) {
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i + 1 < path.size() ? " " : "\n");
        }
    } else {
        cout << -1 << endl; // If no path exists
    }
}

int main() {
    // Input graph details
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> adj(N + 1);

    // Input edges
    for (int i = 0; i < M; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // Input source node and target nodes for printing paths
    int source, target;
    cin >> source >> target;

    // Storage for distances and parent nodes
    vector<long long> dist;
    vector<int> parent;

    // Run Dijkstra
    dijkstra(N, source, adj, dist, parent);

    // Print path from source to target
    printPath(source, target, parent);

    return 0;
}
