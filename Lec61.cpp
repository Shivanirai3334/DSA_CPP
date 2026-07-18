// merge twi sorted list

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      if(list1 ==NULL || list2== NULL){
        return list1 == NULL ? list2 : list1;
      }

      if (list1->val <= list2->val){
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
      }else{
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
      }
      
    }
    };

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

    // First Linked List:
    // 1 -> 2 -> 4

    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(4);

    // Second Linked List:
    // 1 -> 3 -> 4

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Solution obj;

    ListNode* merged = obj.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(merged);

    return 0;
}


// Output
// List 1: 1 -> 2 -> 4
// List 2: 1 -> 3 -> 4
// Merged List: 1 -> 1 -> 2 -> 3 -> 4 -> 4
// Dry Run

// Input:

// List1 : 1 -> 2 -> 4
// List2 : 1 -> 3 -> 4