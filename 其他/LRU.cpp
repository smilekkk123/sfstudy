#include <iostream>
#include <unordered_map>
using namespace std;

struct Node{
    int key,value;
    Node* pre;
    Node* next;
    Node():key(0),value(0),pre(nullptr),next(nullptr){}
    Node(int _key,int _value):key(_key),value(_value),pre(nullptr),next(nullptr){}
};

class LRUCache {
private:
    unordered_map<int,Node*> cache;
    Node* head;
    Node* tail;
    int size; // 目前的大小
    int capacity; // 容量
public:
    LRUCache(int _capacity):capacity(_capacity),size(0) {
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->pre=head;
    }
    
    int get(int key) {
        if(!cache.count(key)){//是否存在，返回0or1
            return -1;
        }
        // 如果存在
        Node* newnode=cache[key]; //找到key处对应的节点
        removeNode(newnode);
        addToHead(newnode);
        return newnode->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            Node* newnode=new Node(key,value);
            cache[key]=newnode;
            addToHead(newnode);
            size++; //现在cache的长度
            if(size>capacity){
                Node* t_node=tail->pre;
                removeNode(t_node);  // 双链表中删除
                cache.erase(t_node->key);  // map中删除
                delete(t_node);  // 销毁节点
                size--;
            }

        }
        else{
            Node* refreshnode=cache[key];
            refreshnode->value=value;
            removeNode(refreshnode);
            addToHead(refreshnode);
        }

    }

    void removeNode(Node* node){
        node->pre->next=node->next;
        node->next->pre=node->pre;
    }

    void addToHead(Node* node){
        node->pre=head;
        node->next=head->next;
        head->next->pre=node;
        head->next=node;
    }

};

int main(){
    LRUCache cache = LRUCache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // 返回  1
    cache.put(3, 3);    // 该操作会使得密钥 2 作废
    cout<<cache.get(2)<<endl;       // 返回 -1 (未找到)
    cache.put(4, 4);    // 该操作会使得密钥 1 作废
    cout<<cache.get(1)<<endl;       // 返回 -1 (未找到)
    cout<<cache.get(3)<<endl;       // 返回  3
    cout<<cache.get(4)<<endl;       // 返回  4



    return 0;
}

