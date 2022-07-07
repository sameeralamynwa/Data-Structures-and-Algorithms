class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        ListNode *previousNode = NULL;
        while(head != NULL){
            ListNode *afterNode = head -> next;
            head -> next = previousNode;
            previousNode = head;
            head = afterNode;
        }
        return previousNode;
    }
};
