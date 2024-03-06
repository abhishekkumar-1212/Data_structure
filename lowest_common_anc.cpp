#include <iostream>
using namespace std;

int a[] = {1, 2, 8, 9, 10, 11, 12};
int n = sizeof(a) / sizeof(int);

class Node {
public:
    int data;
    Node* right;
    Node* left;
    Node(int d) {
        data = d; // corrected the assignment
        right = NULL;
        left = NULL;
    }
};

Node* makeTree(int s, int e) {
    // base case
    if (s > e) {
        return NULL;
    }

    // recursive case
    int mid = (s + e) / 2;
    Node* root = new Node(a[mid]);
    root->left = makeTree(s, mid - 1);
    root->right = makeTree(mid + 1, e);
    return root;
}

// Lowest common ancestor
Node* LCA(Node* root, int x, int y) {
    // base case:
    if (root == NULL)
        return NULL;

    // recursive case
    if (root->data == x || root->data == y) {
        return root;
    }

    Node* left = LCA(root->left, x, y);
    Node* right = LCA(root->right, x, y);

    if (left != NULL && right != NULL) {
        return root;
    }
    if (left != NULL)
        return left;
    else
        return right;
}

int main() {
    Node* root = NULL;
    root = makeTree(0, n - 1);
    Node* ans = LCA(root, 11, 12);

    if (ans != NULL)
        cout << ans->data << endl;
    // preorder(root);
    // cout<<endl;
    return 0;
}
