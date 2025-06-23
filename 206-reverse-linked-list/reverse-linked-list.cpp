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
    ListNode* reverseList(ListNode* head) {
        ListNode* t = head;
        ListNode* prev = nullptr;
        ListNode* next = head;
        while(t!= nullptr)
        {
            next = t->next;
            t->next = prev;
            prev = t;
            t = next;
        }
        return prev;
    }
};