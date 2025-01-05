#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int _val):val(_val),lchild(nullptr),rchild(nullptr){}
};

int findMid(vector<int> inorder,int x){
    int i;
    for(i=0;i<inorder.size();i++){
        if(inorder[i]==x){
            break;
        }
    }
    cout<<i<<endl;
    return i;
}

TreeNode* getTree(vector<int> inorder,vector<int> postorder){
    int len=inorder.size();
    if(len==0){
        return NULL;
    }
    TreeNode* root=new TreeNode(postorder[len-1]); 
    if(len==1){
        return root;
    }
    int mid=findMid(inorder,postorder[len-1]);
    root->lchild=getTree(vector<int>(inorder.begin(),inorder.begin()+mid),vector<int>(postorder.begin(),postorder.begin()+mid));
    root->rchild=getTree(vector<int>(inorder.begin()+mid+1,inorder.end()),vector<int>(postorder.begin()+mid,postorder.end()-1));

    return root;
}

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
        for(int i=0;i<size;i++){
            TreeNode* node=que.front();
            que.pop();
            childres.push_back(node->val);
            if(node->lchild){que.push(node->lchild);}
            if(node->rchild){que.push(node->rchild);}
        }
        res.push_back(childres);
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
    vector<int> inorder={9,3,15,20,7};
    vector<int> postorder={9,15,7,20,3};
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
    TreeNode* res;
    res=getTree(inorder,postorder);

    vector<vector<int>> ltree;
    ltree=levelOrder(res);
    for(vector<int> childres:ltree){
        printRes(childres);
    }
    


    return 0;
}