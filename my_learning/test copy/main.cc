#include <cmath>
#include <vector>
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    int size; // 存储以当前节点为根的子树的大小
};

const double ALPHA = 0.75;

Node* createNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    node->size = 1;  // 新节点的大小为1
    return node;
}

int getSize(Node* node) {
    return node ? node->size : 0;
}

void updateSize(Node* node) {
    if (node) {
        node->size = 1 + getSize(node->left) + getSize(node->right);
    }
}

// 检查并返回是否需要重建这个节点
bool needsRebuilding(Node* node) {
    if (!node) return false;
    int leftSize = getSize(node->left);
    int rightSize = getSize(node->right);
    return leftSize > ALPHA * (leftSize + rightSize + 1) || rightSize > ALPHA * (leftSize + rightSize + 1);
}

Node* insert(Node* root, int data, Node*& scapegoat) {
    if (!root) return createNode(data);

    if (data < root->data) {
        root->left = insert(root->left, data, scapegoat);
    } else {
        root->right = insert(root->right, data, scapegoat);
    }
    updateSize(root);

    // 如果这个节点需要重建，将其标记为替罪羊
    if (needsRebuilding(root)) {
        scapegoat = root;
    }

    return root;
}

std::vector<Node*> nodes;

void flatten(Node* root) {
    if (!root) return;
    flatten(root->left);
    nodes.push_back(root);
    flatten(root->right);
}

Node* buildBalanced(int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* root = nodes[mid];
    root->left = buildBalanced(start, mid - 1);
    root->right = buildBalanced(mid + 1, end);
    updateSize(root);
    return root;
}

Node* rebuild(Node* root) {
    nodes.clear();
    flatten(root);
    return buildBalanced(0, nodes.size() - 1);
}

Node* insertAndRebuildIfNeeded(Node* root, int data) {
    Node* scapegoat = nullptr;
    root = insert(root, data, scapegoat);
    if (scapegoat) {
        if (scapegoat == root) {
            // 如果根节点是替罪羊，重建整棵树
            root = rebuild(root);
        } else {
            // 找到替罪羊的父节点，并对替罪羊的子树进行重建
            Node* parent = root;
            while (parent->left != scapegoat && parent->right != scapegoat) {
                parent = data < parent->data ? parent->left : parent->right;
            }
            if (parent->left == scapegoat) {
                parent->left = rebuild(scapegoat);
            } else {
                parent->right = rebuild(scapegoat);
            }
        }
    }
    return root;
}

int main() {
    Node* root = nullptr;
    root = insertAndRebuildIfNeeded(root, 3);
    root = insertAndRebuildIfNeeded(root, 1);
    root = insertAndRebuildIfNeeded(root, 2);
    return 0;
}
