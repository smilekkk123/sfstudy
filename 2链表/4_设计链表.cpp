#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int _x) : val(_x), next(nullptr) {}
        ListNode(int _x, ListNode* _next) : val(_x), next(_next) {}
    };

    MyLinkedList() {
        dummyNode = new ListNode(0); // 虚拟头结点
        size = 0;
        tail = dummyNode;
    }

    int get(int index) {
        ListNode* p = dummyNode;
        if (index >= size || index < 0) {
            return -1;
        } 
        while (index>=0) {
            p = p->next;
            index--;
        }
        return p->val;
    }

    void addAtHead(int val) {
        ListNode* newHead = new ListNode(val);
        newHead->next = dummyNode->next;
        dummyNode->next = newHead;
        size++;
    }

    void addAtTail(int val) {
        tail->next = new ListNode(val);
        tail = tail->next;
        size++;
    }

    void addAtIndex(int index, int val) {
        ListNode* p = dummyNode;
        if (index == size) {
            addAtTail(val);
        } else if (index < size) {
            while (index > 0) { // 找到前一个节点
                p = p->next;
                index--;
            }
            ListNode* newNode = new ListNode(val);
            newNode->next = p->next;
            p->next = newNode;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        ListNode* p = dummyNode;
        if (index < size) {
            while (index > 0) { // 找到前一个节点
                p = p->next;
                index--;
            }
            ListNode* temp = p->next;
            p->next = p->next->next;
            delete temp;
            size--;
        }

    }

private:
    int size;
    ListNode* dummyNode;
    ListNode* tail;
};

int main(){



    return 0;
}