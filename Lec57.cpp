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
  Node* head;
  Node* tail;
  public:
  List(){
    head = tail = NULL;
  }

  void push_front(int val){
Node* newNode = new Node(val);
if(head == NULL){
  head = tail = newNode;
  return;
}else{
  newNode->next = head;
  head = newNode;
}
  }

  void push_back(int val){
    Node* newNode = new Node(val);
    if(head == NULL){
head = tail= newNode;
return;
    }else{
      tail->next = newNode;
   tail = newNode;
    }
  }

  void pop_front(){
    Node* temp = head;
    if(head == NULL){
      return;
    }else{
      
      head = temp->next;
      temp->next = NULL;
      delete temp;

    }
  }

  void pop_back(){
    
  }
  void print_ll(){
    Node* temp;
    temp = head;
    while(temp != NULL){
      cout<<temp->data<<"->";
      temp = temp->next;
    }
  }
};
int main(){
List ll;
ll.push_front(4);
ll.push_front(3);
ll.push_front(2);
ll.push_back(5);
ll.push_back(6);
ll.push_back(7);
ll.print_ll();


return 0;
}