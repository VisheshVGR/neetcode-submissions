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
        ListNode *sentinalHead = new ListNode (-1, head);

        ListNode *fast = sentinalHead;
        ListNode *delnext = sentinalHead;

        n -= 1;

        while (fast && n)
        {
            n--;

            fast = fast->next;
        }

        if (!fast || !fast->next)
            return head;

        while (fast->next->next != nullptr)
        {
            delnext = delnext->next;
            fast = fast->next;
        }

        delnext->next = delnext->next->next;

        return sentinalHead->next;
        
    }
};
