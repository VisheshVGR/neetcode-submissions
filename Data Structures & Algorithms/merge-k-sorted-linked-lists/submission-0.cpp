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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size ();

        if (n == 0)
            return nullptr;

        ListNode *ans = lists[0];


        for (int i = 1; i < n; i++)
        {
            ans = mergeTwoLists (ans, lists[i]);
        }

        return ans;
    }
private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *sentinalHead = new ListNode (-1);

        ListNode *head = sentinalHead;

        ListNode *head1 = list1, *head2 = list2;
        ListNode *next1,*next2;

        while (head1 && head2)
        {
            next1 = head1->next;
            next2 = head2->next;

            if (head1->val <= head2->val)
            {
                head->next = head1;
                head = head->next;

                head1 = next1;
            }
            else
            {
                head->next = head2;
                head = head->next;

                head2 = next2;
            }
        }

        if (!head1)
            head->next = head2;

        if (!head2)
            head->next = head1;

        return sentinalHead->next;
    }
};
