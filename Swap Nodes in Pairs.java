class Solution {
    ListNode swapPairs(ListNode head) {
        ListNode previous = null, returnHead = head;
        while(head != null && head.next != null){
            ListNode after = head.next, newHead = head.next.next;
            if(previous != null){
                previous.next = after;
            }
            else{
                returnHead = head.next;
            }
            after.next = head;
            head.next = newHead;
            previous = head;
            head = newHead;
        }
        return returnHead;
    }
}
