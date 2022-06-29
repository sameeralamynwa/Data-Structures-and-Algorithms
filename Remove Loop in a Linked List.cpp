class Solution{
public:
    void removeLoop(Node* head){
        Node* slow = head, *fast = head, *previousNode;
        while(slow != NULL and fast != NULL and fast -> next != NULL){
            previousNode = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                while(slow != head){
                    previousNode = slow;
                    slow = slow -> next;
                    head = head -> next;
                }
                previousNode -> next = NULL;
            }
        }
    }
};
