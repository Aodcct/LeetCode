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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l3 = new ListNode(0);
        ListNode* now = l3;
        int carry = 0, remainder = 0, addend = 0, augend = 0;
        bool first = true;
        while( (l1 != nullptr && l2 != nullptr) || carry != 0)
        {
            if(l1 == nullptr) addend = 0;
            else addend = l1->val;
            if(l2 == nullptr) augend = 0;
            else augend = l2->val;
            int temp = addend + augend + carry;
            carry = temp / 10;
            remainder = temp % 10;
            if(first) first = false;
            else
            {
                now->next = new ListNode(0);
                now = now->next;
            }
            now->val = remainder;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            // printf("%d\n", now->val);
        }
        return l3;
    }
};