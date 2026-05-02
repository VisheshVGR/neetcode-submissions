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

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *sentinalhead = new ListNode(-1, head);

        ListNode *newhead = helper(sentinalhead);

        head->next = nullptr;

        return newhead;
    }

private:
    ListNode *helper(ListNode *head)
    {
        ListNode *prev = head;       // is sentinal head
        ListNode *curr = head->next; // guranteed to exist
        ListNode *next;

        while (curr)
        {
            next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};