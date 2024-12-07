#include <iostream>
using namespace std;

int findMaxIterative(int* s, int* f, int n) {
    int count = 0;
    int lastFinishTime = 0; 

    for (int i = 0; i < n; i++) {
        if (s[i] >= lastFinishTime) { 
            count++;
            lastFinishTime = f[i]; 
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    int* s = new int[n];
    int* f = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    cout << findMaxIterative(s, f, n) << endl;

    delete[] s;
    delete[] f;
    return 0;
}