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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode sum(0);
        ListNode* curr = &sum;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while(temp1 || temp2){
            int val1 = (temp1 != nullptr) ? temp1->val : 0;
            int val2 = (temp2 != nullptr) ? temp2->val : 0;
            int add =  val1 + val2 + carry;
            carry = add / 10;
            int res = add % 10;
            curr->next = new ListNode(res);
            curr = curr->next;
            if(temp1 != nullptr) temp1 = temp1->next;
            if(temp2 != nullptr) temp2 = temp2->next;
        }
        if(carry > 0) curr->next = new ListNode(carry);
        return sum.next;
    }
};
