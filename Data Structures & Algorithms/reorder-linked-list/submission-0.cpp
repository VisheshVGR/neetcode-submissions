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
    void reorderList(ListNode *head)
    {
        /*
        we use slow fast pointer to find mid of the list
        we break list into two
        we reverse second list
        we merge both lists
        */

        // Base case
        if (!head || !head->next || !head->next->next)
            return;

        ListNode *midMinusOneNode = findMidMinusOneNode(head);

        ListNode *firstlist = head;
        ListNode *secondlist = midMinusOneNode->next;

        // Break link
        midMinusOneNode->next = nullptr;

        // Reverse second list

        secondlist = ReverseList(secondlist);

        // Merge both list
        head = MergeList(firstlist, secondlist);
    }

private:
    ListNode *findMidMinusOneNode(ListNode *root)
    {
        ListNode *slow = root, *fast = root;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode *ReverseList(ListNode *root)
    {
        ListNode *prev = root;
        ListNode *curr = root->next;

        // Breaking the link as this will be reversed
        prev->next = nullptr;
        
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

    ListNode *MergeList(ListNode *firstlist, ListNode *secondlist)
    {
        ListNode *sentinalHead = new ListNode(-1);

        ListNode *head = sentinalHead;

        ListNode *l1 = firstlist, *l1n;
        ListNode *l2 = secondlist, *l2n;

        while (l1 && l2)
        {
            l1n = l1->next;
            l2n = l2->next;

            head->next = l1;
            head->next->next = l2;

            head = head->next->next;

            l1 = l1n;
            l2 = l2n;
        }

        if (l1n)
            head->next = l1n;

        head = sentinalHead->next;

        delete sentinalHead;

        return head;
    }
};