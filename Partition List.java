class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode lesser = null, greater = null, headOfGreater = null, headOfLesser = null;
        while(head != null){
            if(head.val < x){
                if(lesser == null){
                    lesser = head;
                    headOfLesser = head;
                }
                else{
                    lesser.next = head;
                    lesser = lesser.next;
                }
            }
            else{
                if(greater == null){
                    greater = head;
                    headOfGreater = head;
                }
                else{
                    greater.next = head;
                    greater = greater.next;
                }
            }
            head = head.next;
        }
        if(greater != null){
            greater.next = null;
        }
        if(lesser != null){
            lesser.next = headOfGreater;
        }
        return headOfLesser == null ? headOfGreater : headOfLesser;
    }
}
