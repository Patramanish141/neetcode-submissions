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
    ListNode* reverse(ListNode* head){
        if(!head) return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        //check if less then k nodes are present or not
        ListNode* groupEnd = head;
        for(int i=0; i<k-1; i++){
            if(!groupEnd) return head;
            groupEnd = groupEnd->next;
        }

        if(!groupEnd) return head; // still fewer than k

        ListNode* nextHead = groupEnd->next;
        groupEnd->next = nullptr;

        ListNode* newHead = reverse(head);
        head->next = reverseKGroup(nextHead, k);

        return newHead;
    }
};
