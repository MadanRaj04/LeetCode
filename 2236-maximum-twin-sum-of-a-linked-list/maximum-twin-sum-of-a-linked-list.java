/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    private ListNode reverseLinkedList(ListNode head)
    {
        ListNode prev = null;
        ListNode cur = head;
        ListNode next = null;
        while(cur!=null)
        {
            next = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    public int pairSum(ListNode head) {
        if(head.next.next == null)
        {
            return head.val + head.next.val;
        }
        ListNode slow = head;
        ListNode fast = head.next;
        while(fast != null && fast.next != null)
        {
            slow= slow.next;
            fast = fast.next.next;
        }
        ListNode second = reverseLinkedList(slow.next);
        ListNode first = head;
        int maxSum=0;
        while(second!=null)
        {
            maxSum = Math.max(maxSum,first.val+second.val);
            first=first.next;
            second=second.next;
        }
        return maxSum;
    }
}