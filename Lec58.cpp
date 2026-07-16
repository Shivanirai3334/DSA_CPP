#include <iostream>
using namespace std;

// Definition for singly-linked list.
class ListNode {
public:
    int val;
    ListNode* next;

    ListNode(int data) {
        val = data;
        next = NULL;
    }
};

 class Solution {
public:
    ListNode* reverseList(ListNode* head) {
      ListNode*prev = NULL;
      ListNode*curr = head;
      ListNode*next=NULL;
      while (curr!= NULL)
      {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
      }
      
        
      return prev;
    }
};

// sc: O(1)
// TC ; O(n)

// Function to print linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}
int main() {
    // Creating Linked List: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;
    head = obj.reverseList(head);

    cout << "Reversed Linked List: ";
    printList(head);

    return 0;
}

// Original Linked List: 1 -> 2 -> 3 -> 4 -> 5
// Reversed Linked List: 5 -> 4 -> 3 -> 2 -> 1