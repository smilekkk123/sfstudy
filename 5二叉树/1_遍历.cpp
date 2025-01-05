#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};


/*********************** 递归 *****************************/
void traversalPre(TreeNode* root,vector<int>& res){
    if(root==NULL){
        return;
    }
    res.push_back(root->val);
    traversalPre(root->left,res);
    traversalPre(root->right,res);

}

vector<int> preorderDG(TreeNode* root){
    vector<int> res;
    traversalPre(root,res);
    return res;
}

///

void traversalMid(TreeNode* root,vector<int>& res){
    if(root==NULL){
        return;
    }
    
    traversalMid(root->left,res);
    res.push_back(root->val);
    traversalMid(root->right,res);

}

vector<int> midorderDG(TreeNode* root){
    vector<int> res;
    traversalMid(root,res);
    return res;
}

///

void traversalBac(TreeNode* root,vector<int>& res){
    if(root==NULL){
        return;
    }
    
    traversalBac(root->left,res);
    traversalBac(root->right,res);
    res.push_back(root->val);
}

vector<int> bacorderDG(TreeNode* root){
    vector<int> res;
    traversalBac(root,res);
    return res;
}

/*************************** 迭代 ********************************/

vector<int> preorderDD(TreeNode* root) {
    vector<int> res;
    if(root == NULL) {
        return {};
    }
    stack<TreeNode*> sta;
    sta.push(root);
    while(!sta.empty()) {
        TreeNode* node = sta.top();
        sta.pop();
        res.push_back(node->val);
        if(node->right) sta.push(node->right);  // 中左右
        if(node->left) sta.push(node->left);
    }
    return res;
}

vector<int> midorderDD(TreeNode* root) {
    vector<int> res;
    if(root == NULL) {
        return {};
    }
    stack<TreeNode*> sta;
    TreeNode* cur = root;
    while (cur != NULL || !sta.empty()) {
        if (cur != NULL) { // 指针来访问节点，访问到最底层
            sta.push(cur); // 将访问的节点放进栈
            cur = cur->left;                // 左
        } else {
            cur = sta.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
            sta.pop();
            res.push_back(cur->val);        // 中
            cur = cur->right;               // 右
        }
    }
    return res;
}


vector<int> postorderDD(TreeNode* root) {
    vector<int> res;    
    if(root == NULL) {
        return {};
    }
    stack<TreeNode*> sta;
    sta.push(root);
    while (!sta.empty()) {
        TreeNode* node = sta.top();
        sta.pop();
        res.push_back(node->val);
        if (node->left) sta.push(node->left);  // 中右左
        if (node->right) sta.push(node->right); 
    }
    reverse(res.begin(), res.end()); // 将结果反转 -> 左右中
    return res;
}

/*************************** 层序 *****************************/

vector<vector<int>> levelOrder(TreeNode* root){
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root!=NULL){
        que.push(root);
    }
    while (!que.empty())
    {
        vector<int> childres;
        int size=que.size();  
        for(int i=0;i<size;i++){ // 遍历现在队列中（所处同一层级）所有节点的孩子
            TreeNode* node=que.front();
            que.pop();
            childres.push_back(node->val);
            // 左右孩子入栈
            if(node->left){que.push(node->left);}
            if(node->right){que.push(node->right);}
        }
        res.push_back(childres); // 一层结束
    }
    return res;
    
}


void printRes(vector<int> res){
    for(int n:res){
        cout<<n<<" ";
    }
    cout<<endl;
}







int main(){
    vector<int> tree;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);

/************ 递归遍历 ***************/
    tree=preorderDG(root);
    printRes(tree);

    tree=midorderDG(root);
    printRes(tree);

    tree=bacorderDG(root);
    printRes(tree);


/************ 迭代遍历 ***************/




/************ 层序遍历 ***************/

    vector<vector<int>> ltree;
    ltree=levelOrder(root);
    for(vector<int> childres:ltree){
        printRes(childres);
    }
    


    /*
    int num;
    do{
        cin>>num;
        tree.push_back(num);  // 输入节点
    }while (getchar()!='\n');
    */

    
    



    return 0;
}