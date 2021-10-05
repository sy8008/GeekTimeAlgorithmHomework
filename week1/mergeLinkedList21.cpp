#include<iostream>
#include<vector>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head1 =l1, *head2 = l2;
        ListNode mergedList(-1000);
        ListNode *mergedListhead = &mergedList;
        while (head1 != NULL && head2 != NULL){
            if (head1->val <= head2->val){
                mergedListhead->next = head1;
                head1 = head1 -> next;              
            }
            else {
                mergedListhead->next = head2;
                head2 = head2 -> next;
            }
            mergedListhead = mergedListhead->next;
        }
        while (head1 != NULL) {
            mergedListhead->next = head1;
            head1 = head1 -> next;
            mergedListhead = mergedListhead->next;
        }
        while (head2 != NULL) {
            mergedListhead->next = head2;
            head2 = head2 -> next;
            mergedListhead = mergedListhead->next;
        }

        return mergedList.next;
    }
};