#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

vector<int> rightSideView(TreeNode *root)
{
    queue<TreeNode*> que;
    vector<int> res;
    if(root!=NULL) {
        que.push(root);
    }
    while(!que.empty()){
        int size=que.size();
        for(int i=0;i<size;i++) {
            TreeNode* node = que.front();
            que.pop();
            if(i==size-1) {
                res.push_back(node->val);
            }
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }
    return res;
}

int main()
{
    vector<int> tree;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    return 0;
}