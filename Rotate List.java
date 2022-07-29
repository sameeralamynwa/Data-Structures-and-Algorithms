class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        int size = 0;
        ListNode traverse = head, lastNode = null;
        while(traverse != null){
            lastNode = traverse;
            traverse = traverse.next;
            ++size;
        }
        if(size < 1 || k % size == 0){
            return head;
        }
        k %= size;
        ListNode secondLastNode = null;
        while(k-- > 0){
            traverse = head;
            while(traverse != null){
                secondLastNode = lastNode;
                lastNode = traverse;
                traverse = traverse.next;
            }
            secondLastNode.next = null;
            lastNode.next = head;
            head = lastNode;
        }
        return head;
    }
}
