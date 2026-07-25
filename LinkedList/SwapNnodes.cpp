#include<iostream>
using namespace std;
class Node{
public:
  int data;
  Node* next;
  Node(int val){
    data = val;
    next = NULL;
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
  void printLL(){
   Node* temp = head;
   while(temp != NULL){
    cout<<temp->data<<"->";
    temp = temp->next;
   }
   cout<<"NULL\n";
  }
  Node* SwapNodesInLL(Node* head,int x,int y){
    if(x == y){
     return head;
    }
    Node* temp = head;
    Node* prev = NULL;

    Node* CurrX = NULL;
    Node* prevX = NULL;
    Node* CurrY = NULL;
    Node* prevY = NULL;

    while(temp != NULL){
    if(temp->data == x){
    CurrX = temp;
    prevX = prev;
    }
    if(temp->data == y){
    CurrY = temp;
    prevY = prev;
    }
    prev = temp;
    temp = temp->next;
    }
    //If either x or y are not present
    if(CurrX == NULL || CurrY == NULL){
    return head;
    }
    //Adjacent case : x before y
    if(CurrX->next == CurrY){
     Node* nextX = CurrY->next;
     if(prevX == NULL){
        head = CurrY;
     }else{
        prevX->next = CurrY;
     }
     CurrY->next = CurrX;
     CurrX->next = nextX;
     return head;
    }
    //Adjacent case : y before x
    if(CurrY->next == CurrX){
     Node* nextY = CurrX->next;
     if(prevY == NULL){
        head = CurrX;
     }else{
        prevY->next = CurrX;
     }
     CurrX->next = CurrY;
     CurrY->next = nextY;
     return head;
    }
    //normal case
    Node* nextX = CurrX->next;
    Node* nextY = CurrY->next;
    if(prevX == NULL){
    head = CurrY;
    }else{
    prevX->next = CurrY;
    }
    if(prevY == NULL){
    head = CurrX;
    }else{
    prevY->next = CurrX;
    }
    CurrY->next = nextX;
    CurrX->next = nextY;
    return head;
  }
};
int main(){
List LL;
LL.push_front(4);
LL.push_front(3);
LL.push_front(2);
LL.push_front(1);
LL.printLL();
LL.SwapNodesInLL(LL.head,2,4);
LL.printLL();
 return 0;
}