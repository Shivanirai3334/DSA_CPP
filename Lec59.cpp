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
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while (fast != NULL && fast->next != NULL)
        {
          slow = slow->next;
          fast = fast->next->next;
        }
        return slow;
    }
};

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
    // 1 -> 2 -> 3 -> 4 -> 5

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution obj;

    
    cout << "Middle Node onwards: ";

    ListNode* middle = obj.middleNode(head);
    cout<<middle->val<<endl;
    return 0;
}

// Original Linked List:
// 1 -> 2 -> 3 -> 4 -> 5

// Middle Node onwards:
// 3 -> 4 -> 5


// TC: o(n)
// SC:o(1)