#include <iostream>
//using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* trainningPlan(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        struct ListNode* pre=NULL;
        if(l1->val<l2->val){
            pre=l1;
            pre->next=trainningPlan(l1->next,l2);
        }
        else{
            pre=l2;
            pre->next=trainningPlan(l1,l2->next);

        }
        return pre;

    }
};

int main(){
    int len1,len2;
    std::cin>>len1;
    std::cin>>len2;

    ListNode* l1 = nullptr;
    ListNode* l1_head = nullptr;
    ListNode* l2 = nullptr;
    ListNode* l2_head = nullptr;

    for (int i = 0; i < len1; i++)
    {
        int x1;
        std::cin>>x1;
        ListNode* newnode=new ListNode(x1);
        if (l1==nullptr)
        {
            l1=newnode;
            l1_head=newnode;
        }
        else{
            l1->next=newnode;
            l1=newnode;
        }
    }
    
    for (int i = 0; i < len2; i++)
    {
        int x2;
        std::cin>>x2;
        ListNode* newnode=new ListNode(x2);
        if (l2==nullptr)
        {
            l2=newnode;
            l2_head=newnode;
        }
        else{
            l2->next=newnode;
            l2=newnode;
        }
    }

    Solution solution;
    
    ListNode* res=solution.trainningPlan(l1_head,l2_head);

    while (res!=nullptr)
    {
        std::cout<<res->val<<" ";
        res=res->next;
    }    
    std::cout<<std::endl;
    
    return 0;
}