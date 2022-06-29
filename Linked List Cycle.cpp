class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while(slow != NULL and fast != NULL and fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
