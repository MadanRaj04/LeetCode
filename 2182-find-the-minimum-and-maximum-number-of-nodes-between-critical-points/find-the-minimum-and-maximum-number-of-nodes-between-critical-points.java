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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        int count=0;
        ListNode tvar = head;
        while(tvar!=null)
        {
            tvar=tvar.next;
            count+=1;
        }
        if(count<=2)
        {
            return new int[] {-1,-1};
        }
        ListNode prev = head;
        ListNode cur = head.next;
        ListNode next = cur.next;
        int c=1;
        ArrayList<Integer> tlst = new ArrayList<>();
        while(cur!=null && cur.next!=null)
        {
           // System.out.printf("%d %d %d\n",prev.val,cur.val,next.val);
            if((cur.val > prev.val && cur.val > next.val) || (cur.val < prev.val && cur.val < next.val))
            {
                tlst.add(c);
            }
            prev = cur;
            cur=next;
            next = cur.next;
            c+=1;
        }
        int tlen = tlst.size();
        int min=999999;
        int max = (tlen>=2)?tlst.get(tlen-1)-tlst.get(0):-1;

        for(int i=1;i<tlen;i++)
        {
            if(tlst.get(i)-tlst.get(i-1) < min)
            {
                min = tlst.get(i)-tlst.get(i-1);
            }
        } 
        if(min==999999)
        {
            min = -1;
        }
        return new int[] {min,max};
    }

}