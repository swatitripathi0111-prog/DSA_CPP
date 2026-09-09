#include<iostream>
#include<unordered_map>
using namespace std;
class Node{
public:
   int data;
   Node* next;
   Node* random;
   Node(int data){
    this->data = data;
    next = random = NULL;
   }
};
class List{
public:
   Node* head;
   Node* tail;
   List(){
    head = tail = NULL;
   }
   void push_front(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
    head = tail = newNode;
    }else{
     newNode->next = head;
     head = newNode; 
    }
   }
   Node* copyRandomList(Node* head){
    if(head == NULL){
        return head;
    }
    unordered_map<Node*,Node*> m;

    Node* newHead = new Node(head->data);
    Node* oldTemp = head->next;
    Node* newTemp = newHead;
    m[head] = newHead;

    while(oldTemp != NULL){
    Node* CopyNode = new Node(oldTemp->data);
    m[oldTemp] = CopyNode;
    newTemp->next = CopyNode;

    oldTemp = oldTemp->next;
    newTemp = newTemp->next;
    }
    while(oldTemp != NULL){
    newTemp->random = m[oldTemp->random];
    oldTemp = oldTemp->next;
    newTemp = newTemp->next;
    }
    return newHead;
   }
};
int main(){
List LL;
LL.push_front(7);
LL.push_front(13);
LL.push_front(11);
LL.push_front(10);
LL.push_front(1);
Node* result = LL.copyRandomList(LL.head);
 return 0;
}