class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(slow != NULL and fast != NULL and fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                while(slow != head){
                    slow = slow -> next;
                    head = head -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
