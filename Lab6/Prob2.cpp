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
    int data;
    Node* left;
    Node* right;
    int height;
};

int getHeight(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int getBalanceFactor(Node* node) {
    if (node == nullptr)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

void updateHeight(Node* node) {
    if (node == nullptr)
        return;
    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
}

Node* rotateRight(Node* node) {
    Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* rotateLeft(Node* node) {
    Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

Node* balanceTree(Node* node) {
    if (node == nullptr)
        return nullptr;

    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);

    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
        return rotateRight(node);

    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
        return rotateLeft(node);

    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }

    return node;
}

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->height = 1;
    return newNode;
}

Node* insertNode(Node* root, int value) {
    if (root == nullptr)
        return createNode(value);

    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);

    return balanceTree(root);
}

bool searchValue(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;
    else if (value < root->data)
        return searchValue(root->left, value);
    else
        return searchValue(root->right, value);
}

Node* findMinNode(Node* root) {
    if (root == nullptr || root->left == nullptr)
        return root;
    return findMinNode(root->left);
}

Node* deleteNode(Node* root, int value) {
    if (root == nullptr)
        return root;

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        if (root->left == nullptr || root->right == nullptr) {
            Node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
            delete temp;
        } else {
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;

    return balanceTree(root);
}

void inOrderTraversal(Node* root) {
    if (root == nullptr)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    int values[] = {63, 9, 19, 27, 18, 108, 99, 81};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        root = insertNode(root, values[i]);
    }

    cout << "In-order traversal of the AVL tree: ";
    inOrderTraversal(root);
    cout << endl;

    int valueToSearch = 27;
    if (searchValue(root, valueToSearch))
        cout << valueToSearch << " is found in the tree.\n";
    else
        cout << valueToSearch << " is not found in the tree.\n";

    int valueToDelete = 19;
    root = deleteNode(root, valueToDelete);

    cout << "In-order traversal of the AVL tree after deleting " << valueToDelete << ": ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
