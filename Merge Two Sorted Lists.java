class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode traverse = null, header = list1 != null ? list2 != null ? list1.val < list2.val ? list1 : list2 : list1 : list2;
        while(list1 != null && list2 != null){
            if(list1.val < list2.val){
                if(traverse == null){
                    traverse = list1;
                }
                else{
                    traverse.next = list1;
                    traverse = traverse.next;
                }
                list1 = list1.next;
            }
            else{
                if(traverse == null){
                    traverse = list2;
                }
                else{
                    traverse.next = list2;
                    traverse = traverse.next;
                }
                list2 = list2.next;
            }
        }
        
        while(list1 != null){
            if(traverse == null){
                traverse = list1;
            }
            else{
                traverse.next = list1;
                traverse = traverse.next;
            }
            list1 = list1.next;
        }
        
        while(list2 != null){
            if(traverse == null){
                traverse = list2;
            }
            else{
                traverse.next = list2;
                traverse = traverse.next;
            }
            list2 = list2.next;
        }
        
        return header;
    }
}
