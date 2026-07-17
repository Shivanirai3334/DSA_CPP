// Q1. iss question me linkedlist cycle detect krna hai

// #include <iostream>
// using namespace std;

// // Definition for singly-linked list.
// class ListNode {
// public:
//     int val;
//     ListNode* next;

//     ListNode(int data) {
//         val = data;
//         next = NULL;
//     }
// };

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {

//     ListNode* slow = head;
//     ListNode*fast = head;
//     while(fast!= NULL && fast->next != NULL){
//       slow = slow->next;
//       fast = fast->next->next;
//       if (slow==fast)
//       {
//         return true;
//       }
      
//     }
//     return false;
//     }};

//     // Function to print linked list from any node
// void printList(ListNode* head) {
//     while (head != NULL) {
//         cout << head->val;
//         if (head->next != NULL)
//             cout << " -> ";
//         head = head->next;
//     }
//     cout << endl;
// }
// int main() {

//     // Creating Linked List:
//     // 3 -> 2 -> 0 -> -4
//     //           ^      |
//     //           |______|

//     ListNode* head = new ListNode(3);
//     head->next = new ListNode(2);
//     head->next->next = new ListNode(0);
//     head->next->next->next = new ListNode(-4);

//     // Creating Cycle
//     head->next->next->next->next = head->next;

//     Solution obj;

//     if (obj.hasCycle(head))
//         cout << "Cycle Detected";
//     else
//         cout << "No Cycle";

//     return 0;
// }


// Time Complexity: O(n)
// Space Complexity: O(1)




// iss question me cycle kis node se start ho rha hai usko detect krna hai..


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
    ListNode *detectCycle(ListNode *head) {
      ListNode*slow = head;
      ListNode*fast = head;
      bool isCycle = false;

      while (fast!=NULL && fast->next != NULL)
      {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
          isCycle = true;
          break;
          
          }
         
        }

        if(!isCycle){
          return NULL;
        }
        slow = head;

        // agar uss cycle ko remove krna hai to ye code run krna chahiye...
    //     ListNode* prev = NULL;
    //     while (slow != fast){
    //       slow = slow->next;
    //       prev = fast;
    //       fast = fast->next;
    //     }
    //    prev->next = NULL;
    //    return slow;
    //   }
    // };




        while (slow != fast)
        {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
        
      }     
};

int main() {

    // Creating Linked List:
    // 3 -> 2 -> 0 -> -4
    //      ^         |
    //      |_________|

    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);

    // Creating Cycle
    head->next->next->next->next = head->next;

    Solution obj;

    ListNode* ans = obj.detectCycle(head);

    if (ans != NULL)
        cout << "Cycle starts at node: " << ans->val << endl;
    else
        cout << "No Cycle Found" << endl;

    return 0;
}