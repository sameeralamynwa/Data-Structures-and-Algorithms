class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
            
        middle_node = self.findMiddle(head)
        second_half = middle_node.next
        middle_node.next = None
        
        left_sorted = self.sortList(head)
        right_sorted = self.sortList(second_half)
        
        return self.mergeSortedLists(left_sorted, right_sorted)
    
    def findMiddle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        slow_pointer = head
        fast_pointer = head
        prev_pointer = None
        
        while fast_pointer and fast_pointer.next:
            fast_pointer = fast_pointer.next.next
            prev_pointer = slow_pointer
            slow_pointer = slow_pointer.next
            
        return prev_pointer
    
    def mergeSortedLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        dummy_head = ListNode(0)
        current = dummy_head
        
        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
        
        if list1:
            current.next = list1
        if list2:
            current.next = list2
            
        return dummy_head.next
