public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode originalHeadA = headA, originalHeadB = headB;
        
        while(headA != null && headB != null){
            headA = headA.next;
            headB = headB.next;
        }
        
        int difference = 0;
        if(headB != null){
            while(headB != null){
                headB = headB.next;
                difference++;
            }
            
            while(difference-- > 0){
                originalHeadB = originalHeadB.next;
            }
            
            while(originalHeadA != originalHeadB){
                originalHeadA = originalHeadA.next;
                originalHeadB = originalHeadB.next;
            }
            
        }
        
        else{
            while(headA != null){
                headA = headA.next;
                difference++;
            }
            
            while(difference-- > 0){
                originalHeadA = originalHeadA.next;
            }
            
            while(originalHeadA != originalHeadB){
                originalHeadA = originalHeadA.next;
                originalHeadB = originalHeadB.next;
            }
        }
        return originalHeadA;
    }
}
