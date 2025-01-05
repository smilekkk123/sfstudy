#include <iostream>
using namespace std;
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp;
        ListNode* pre=nullptr;
        ListNode* cur=head;
        while(cur){
            temp=cur->next;

            cur->next=pre; // 反转
            
            // 右移
            pre=cur;
            cur=temp;
        }
        return pre;
    }
};

int main(){

    int n;
    cin>>n;
    ListNode* head=nullptr;
    ListNode* p;
    for (int i = 0; i < n; i++)
    {
        int x1;
        cin>>x1;
        ListNode* newnode=new ListNode(x1);
        if (head==nullptr) // 如果是第一个节点
        {
            head=newnode;
            p=newnode;
        }
        else{
            p->next=newnode;
            p=p->next;
            
        }
        
    }

    Solution sol;
    ListNode* res=nullptr;
    res=sol.reverseList(head);

    while (res!=nullptr)
    {
        std::cout<<res->val<<" ";
        res=res->next;
    }    
    std::cout<<std::endl;
    


    return 0;

}