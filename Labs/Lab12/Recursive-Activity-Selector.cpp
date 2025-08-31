#include <iostream>
using namespace std;
int findMax(int* s, int* f, int k, int n) {
    int m = k + 1;

    while (m <= n && s[m] < f[k]) {
        m++;
    }

    if (m <= n) {
        return 1 + findMax(s, f, m, n);
    }

    return 0;
}

int main() {
    int n;
    cin >> n;

    int* s = new int[n + 1]; 
    int* f = new int[n + 1];

    s[0] = 0; 
    f[0] = 0; 

    // 读取输入
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    cout << findMax(s, f, 0, n) << endl;

    delete[] s;
    delete[] f;

    return 0;
}