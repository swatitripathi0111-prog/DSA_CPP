#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
public:
    int key,val;
    Node* prev ;
    Node* next;
    Node(int k,int v){
    key = k;
    val = v;
    next = prev = NULL;
    }
};
   class LRUCache{
   public:
   Node* head = new Node(-1,-1);
   Node* tail = new Node(-1,-1);
   unordered_map<int,Node*> m;

   void AddNode(Node* newNode){
    Node* oldNext = head->next;
    head->next = newNode;
    oldNext->prev = newNode;

    newNode->next = oldNext;
    newNode->prev = head;
   }
   void DelNode(Node* oldNode){
    Node* oldPrev = oldNode->prev;
    Node* oldNext = oldNode->next;
    oldPrev->next = oldNext;
    oldNext->prev = oldPrev;
   }
   int limit;
    LRUCache(int capacity) {
       limit = capacity;
       head->next = tail;
       tail->prev = head; 
    }
    int get(int key) {
    if(m.find(key) == m.end()){
        return -1;
    }
    Node* ansNode = m[key];
    int ans = ansNode->val;

    m.erase(key);
    DelNode(ansNode);

    AddNode(ansNode);
    m[key] = ansNode;

    return ans;
    }
    void put(int key, int value) {
    if(m.find(key) != m.end()){
    Node* oldNode = m[key];
    DelNode(oldNode);
    m.erase(key);
     }
     if(m.size() == limit){
       m.erase(tail->prev->key);
       DelNode(tail->prev);
     }
       Node* newNode = new Node(key,value);
       AddNode(newNode);
       m[key] = newNode;
     }
};
int main(){
LRUCache LRU(2);
LRU.put(1,1);
LRU.put(2,2);
cout<<LRU.get(1)<<endl;
LRU.put(3,3);
cout<<LRU.get(2)<<endl;
LRU.put(4,4);
cout<<LRU.get(1)<<endl;
cout<<LRU.get(3)<<endl;
cout<<LRU.get(4)<<endl;
return 0;
}