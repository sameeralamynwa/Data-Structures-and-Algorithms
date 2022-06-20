class Solution {
public:
    Node* flatten(Node *head, Node *previousNode = NULL) {
        if(head == NULL){
            return NULL;
        }
        Node *headNode = head;
        head -> prev = previousNode;
        if(head -> child){
            Node *rightNode = head -> next;
            head -> next = flatten(head -> child, head);
            head -> child = NULL;
            while(head -> next != NULL){
                head = head -> next;
            }
            head -> next = flatten(rightNode, head);
        }
        else if(head -> next){
            head -> next = flatten(head -> next, head);
        }
        return headNode;
    }
};
