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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = head;
        for(int i = 0; i < n; i++) fast = fast->next;
        if(fast == nullptr){
            ListNode* prev = head;
            slow->next = nullptr;
            head = head->next;
            prev->next = nullptr;
        }
        else{
            while(fast){
                slow = slow->next;
                fast = fast->next;
            }
            ListNode* before = slow;
            slow = slow->next;
            ListNode* after = slow;
            after = slow->next;
            slow->next = nullptr;
            before->next = after;
        }
        return head;
    }
};
