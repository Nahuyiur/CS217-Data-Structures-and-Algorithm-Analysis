#include <iostream>
using namespace std;

// 定义节点结构
struct node {
    node* LeftSon;
    node* RightSon;
    int leftEndPoint;
    int rightEndPoint;
    int sum;

    // 节点构造函数
    node(int l, int r) : LeftSon(nullptr), RightSon(nullptr), leftEndPoint(l), rightEndPoint(r), sum(0) {}
};

// 全局变量
int n, q;
node* root = nullptr;

// 构建 Segment Tree
node* buildTree(int l, int r) {
    node* current = new node(l, r);
    if (l == r) {
        // 叶子节点
        return current;
    }
    int mid = (l + r) / 2;
    current->LeftSon = buildTree(l, mid);
    current->RightSon = buildTree(mid + 1, r);
    return current;
}

// 更新操作
void doUpdate(node* current, int index, int value) {
    if (current->leftEndPoint == current->rightEndPoint) {
        // 找到叶子节点，更新值
        current->sum = value;
        return;
    }

    int mid = (current->leftEndPoint + current->rightEndPoint) / 2;
    if (index <= mid) {
        // 更新左子树
        doUpdate(current->LeftSon, index, value);
    } else {
        // 更新右子树
        doUpdate(current->RightSon, index, value);
    }

    // 向上传播更新
    current->sum = (current->LeftSon ? current->LeftSon->sum : 0) +
                   (current->RightSon ? current->RightSon->sum : 0);
}

// 查询操作
int doQuery(node* current, int l, int r) {
    if (l <= current->leftEndPoint && r >= current->rightEndPoint) {
        return current->sum;
    }

    int mid = (current->leftEndPoint + current->rightEndPoint) / 2;
    int sum = 0;

    if (l <= mid && current->LeftSon != nullptr) {
        sum += doQuery(current->LeftSon, l, min(r, mid));
    }

    if (r > mid && current->RightSon != nullptr) {
        sum += doQuery(current->RightSon, max(l, mid + 1), r);
    }

    return sum;
}

int main() {
    cin >> n >> q;

    // 初始化 Segment Tree
    root = buildTree(1, n);

    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;

        if (op == 1) {
            int x, v;
            cin >> x >> v;
            doUpdate(root, x, v);
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            cout << doQuery(root, l, r) << endl;
        }
    }

    return 0;
}