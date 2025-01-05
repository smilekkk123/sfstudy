#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int _x): val(_x),next(nullptr){}
};

ListNode* removeElements(ListNode* head, int val) {
        ListNode* newHead=new ListNode();
        newHead->next=head;
        ListNode* p=newHead;
        while(p->next!=NULL){
            if(p->next->val==val){
                ListNode* temp=p->next;
                p->next=p->next->next;
                delete temp;
            }
            else{
                p=p->next;
            }
        }
        head=newHead->next;
        delete newHead;
        return head;

    }
/*递归*/
/*
ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr){
            return nullptr;
        }
        if(head->val == val){
            return removeElements(head->next,val);
        } else {
            head->next = removeElements(head->next,val);
        }
        return head;
    }
*/
void printList(ListNode* res){
    while (res)
    {
        cout<<res->val<<" ";
        res=res->next;
    }
    
}

int main(){
    ListNode* head=new ListNode();
    ListNode* p=head;
    int num;
    
    do
    {
        cin>>num;
        p->next=new ListNode(num);
        p=p->next;
    }while (getchar()!='\n');

    int target;
    cin>>target;

    ListNode* result=removeElements(head->next,target);

    printList(result);

    return 0;
}