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
    Node* temp = head;
    if(head == NULL){
      cout<<"LL is empty\n";
      return;
    }else{
      while(temp->next != tail){ // agar tail nhi diya hua ho question me to use krenege(temp->next->next == NULL)

        temp = temp->next;
      }
      temp->next = NULL;
      delete tail;
      tail = temp;
    }

  }

  // Insertion at any index of linkedlist

  void Insert(int val, int pos){
    if(pos<0){
      cout<<"Invalid Position "<<endl;
      return;
    }
    if(pos==0){
      push_front(val);
      return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 0; i < pos-1; i++)
    {
      temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    
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

ll.pop_back();
ll.pop_back();
ll.Insert(10, 3);
ll.print_ll();


return 0;
}