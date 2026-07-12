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
    void reorderList(ListNode* head) {
        ListNode* slow= head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;
        ListNode* halfHead = secondHalf;
        ListNode* prev = nullptr;
        while(secondHalf){
            halfHead = halfHead->next;
            secondHalf->next = prev;
            prev = secondHalf;
            secondHalf = halfHead;
        }
        ListNode* temp1 = head;
        ListNode* temp2 = prev;
        while(head != nullptr && prev != nullptr){
            temp1 = head->next;
            head->next = prev;
            head = temp1;
            temp2 = prev->next;
            prev->next = head;
            prev = temp2;
        }
    }
};
