#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pf push_front
#define db double
#define X first
#define Y second
#define fast ios_base::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define nl '\n'

void indef(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* createNode(int key) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int key) {
    if (root == nullptr) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != nullptr) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

int main() {
    Node* root = nullptr;

    root = insertNode(root, 42);
    root = insertNode(root, 12);
    root = insertNode(root, 53);
    root = insertNode(root, 8);
    root = insertNode(root, 16);
    root = insertNode(root, 2);
    root = insertNode(root, 22);
    root = insertNode(root, 19);
    root = insertNode(root, 60);
    root = insertNode(root, 57);
    root = insertNode(root, 65);

    root = insertNode(root, 9);

    root = deleteNode(root, 12);

    root = deleteNode(root, 53);

    return 0;
}
