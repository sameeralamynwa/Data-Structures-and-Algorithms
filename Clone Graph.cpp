class Solution {
public:
    Node *cloneGraph(Node *node) {
        if(node == NULL){
            return node;
        }
        queue <Node *> q;
        map <int, Node *> valueToAddress;
        q.push(node);
        Node *start = new Node(node -> val, {});
        valueToAddress[node -> val] = start;
        while(q.empty() == false){
            Node *current = q.front();
            q.pop();
            for(Node *p : current -> neighbors){
                if(valueToAddress.find(p -> val) == valueToAddress.end()){
                    Node *newNode = new Node(p -> val, {});
                    valueToAddress.insert({p -> val, newNode});
                    q.push(p);
                }
                valueToAddress[current -> val] -> neighbors.push_back(valueToAddress[p -> val]);
            }
        }
        return valueToAddress[node -> val];
    }
};
