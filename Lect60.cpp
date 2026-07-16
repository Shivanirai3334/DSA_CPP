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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

    ListNode* slow = head;
    ListNode*fast = head;
    while(fast!= NULL && fast->next != NULL){
      slow = slow->next;
      fast = fast->next->next;
      if (slow==fast)
      {
        return true;
      }
      
    }
    return false;
    }};

    // Function to print linked list from any node
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

    // Creating Linked List:
    // 3 -> 2 -> 0 -> -4
    //           ^      |
    //           |______|

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating Cycle
    head->next->next->next->next = head->next;

    Solution obj;

    if (obj.hasCycle(head))
        cout << "Cycle Detected";
    else
        cout << "No Cycle";

    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(1)