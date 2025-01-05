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

int findMid(vector<int> inorder, int x)
{
    int i;
    for (i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == x)
        {
            break;
        }
    }
    return i;
}
TreeNode *buildTree(vector<int> preorder, vector<int> inorder) {
    int len = preorder.size();
    if (len == 0) {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[0]);
    if (len == 1) {
        return root;
    }
    
    int mid = findMid(inorder, preorder[0]);
    root->left = buildTree(vector<int>(preorder.begin() + 1, preorder.begin() + mid + 1), vector<int>(inorder.begin(), inorder.begin() + mid));
    root->right = buildTree(vector<int>(preorder.begin() + mid + 1, preorder.end()), vector<int>(inorder.begin() + mid + 1, inorder.end()));

    return root;
}

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    queue<TreeNode *> que;
    if (root != NULL)
    {
        que.push(root);
    }
    while (!que.empty())
    {
        vector<int> childres;
        int size = que.size();
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = que.front();
            que.pop();
            childres.push_back(node->val);
            if (node->left)
            {
                que.push(node->left);
            }
            if (node->right)
            {
                que.push(node->right);
            }
        }
        res.push_back(childres);
    }
    return res;
}

void printRes(vector<int> res)
{
    for (int n : res)
    {
        cout << n << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    int x;
    /*
        do{
            cin>>x;
            inorder.push_back(x);
        }while (getchar()!='\n');

        do
        {
            cin>>x;
            postorder.push_back(x);
        } while (getchar()!='\n');
    */
    TreeNode *res;
    res = buildTree(preorder, inorder);

    vector<vector<int>> ltree;
    ltree = levelOrder(res);
    for (vector<int> childres : ltree)
    {
        printRes(childres);
    }

    return 0;
}