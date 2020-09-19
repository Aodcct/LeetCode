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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* now = head;
        ListNode* preOfNthFromEnd = head;
        int count = 0;
        while(now != nullptr)
        {
            now = now->next;
            if(count > n)
                preOfNthFromEnd = preOfNthFromEnd->next;
            count++;
        }
        if(count <= n)
            head = head->next;
        else
            preOfNthFromEnd->next = preOfNthFromEnd->next->next;
        return head;
    }
};
