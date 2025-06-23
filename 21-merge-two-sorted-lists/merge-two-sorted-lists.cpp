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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dlist = new ListNode();
        ListNode* cur = dlist;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                dlist->next = list1;
                dlist = dlist->next;
                list1 = list1->next;

            }
            else
            {
                dlist->next = list2;
                dlist = dlist->next;
                list2 = list2->next;

            }
        }   

        while(list1 != nullptr)
        {
            dlist->next = list1;
            dlist = dlist->next;
            list1 = list1->next;
        }

        while(list2 != nullptr)
        {
            dlist->next = list2;
            dlist = dlist->next;
            list2 = list2->next;
        }
        return cur->next;
    }
};