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

const int M=1e9+7;
const int maxn=1e5+5;

int moveX[] = {0, 0, 1, -1};
int moveY[] = {1, -1, 0, 0};

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

int countNodes(TreeNode* root) {
    if (root == nullptr)
        return 0;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}

int countLeaves(TreeNode* root) {
    if (root == nullptr)
        return 0;
    else if (root->left == nullptr && root->right == nullptr)
        return 1;
    else
        return countLeaves(root->left) + countLeaves(root->right);
}

int findHeight(TreeNode* root) {
    if (root == nullptr)
        return -1;
    else
        return max(findHeight(root->left), findHeight(root->right)) + 1;
}

int main() {
    indef();
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int numNodes = countNodes(root);
    cout << "Number of nodes in the tree: " << numNodes << endl;

    int numLeaves = countLeaves(root);
    cout << "Number of leaves in the tree: " << numLeaves << endl;

    int height = findHeight(root);
    cout << "Height of the tree: " << height << endl;

    return 0;
}
