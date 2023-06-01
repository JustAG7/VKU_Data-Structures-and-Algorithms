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

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(int data) {
    TreeNode* newNode = new TreeNode();
    if (!newNode) {
        cout << "Memory error!\n";
        return nullptr;
    }
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
        return root;
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void preOrderTraversal(TreeNode* root) {
    if (root) {
        cout << root->data << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void inOrderTraversal(TreeNode* root) {
    if (root) {
        inOrderTraversal(root->left);
        cout << root->data << " ";
        inOrderTraversal(root->right);
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data << " ";
    }
}

int findSmallest(TreeNode* root) {
    if (root->left == nullptr) {
        return root->data;
    } else {
        return findSmallest(root->left);
    }
}

int findLargest(TreeNode* root) {
    if (root->right == nullptr) {
        return root->data;
    } else {
        return findLargest(root->right);
    }
}

bool searchValue(TreeNode* root, int value) {
    if (root == nullptr) {
        return false;
    } else if (root->data == value) {
        return true;
    } else if (value <= root->data) {
        return searchValue(root->left, value);
    } else {
        return searchValue(root->right, value);
    }
}

int countNodes(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int countInternalNodes(TreeNode* root) {
    if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
        return 0;
    } else {
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
    }
}

int findHeight(TreeNode* root) {
    if (root == nullptr) {
        return -1;
    } else {
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

TreeNode* deleteNode(TreeNode* root, int value) {
    if (root == nullptr) {
        return root;
    } else if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
        if (root->left == nullptr) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* minNode = root->right;
        while (minNode->left != nullptr) {
            minNode = minNode->left;
        }
        root->data = minNode->data;
        root->right = deleteNode(root->right, minNode->data);
    }
    return root;
}

int main() {
    TreeNode* root = nullptr;

    root = insertNode(root, 8);
    root = insertNode(root, 3);
    root = insertNode(root, 10);
    root = insertNode(root, 1);
    root = insertNode(root, 6);
    root = insertNode(root, 4);
    root = insertNode(root, 7);
    root = insertNode(root, 9);
    root = insertNode(root, 14);
    root = insertNode(root, 13);

    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    cout << "Smallest element: " << findSmallest(root) << endl;
    cout << "Largest element: " << findLargest(root) << endl;

    int valueToSearch = 6;
    if (searchValue(root, valueToSearch)) {
        cout << valueToSearch << " is found in the tree.\n";
    } else {
        cout << valueToSearch << " is not found in the tree.\n";
    }

    cout << "Number of nodes: " << countNodes(root) << endl;
    cout << "Number of internal nodes: " << countInternalNodes(root) << endl;
    cout << "Height of the tree: " << findHeight(root) << endl;

    int valueToDelete = 6;
    root = deleteNode(root, valueToDelete);
    cout << "After deleting " << valueToDelete << " from the tree, the in-order traversal is: ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
