class Solution
{
    public:
    Node* reverse(Node* head)
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
        
        return head;
    }
    void util(int res, Node* &tmp, Node* &head) {
        Node* newNode = new Node(res%10);
        tmp->next = newNode;
        tmp = tmp->next;
        head = head->next;
    }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // reverse the lists
        first = reverse(first);
        second = reverse(second);
        
        Node* ansHead = new Node(0);
        Node *tmp = ansHead;
        int rem = 0;
        
        // If both Nodes present
        while(first && second) {
            int res = first->data + second->data + rem;
            Node* newNode = new Node(res%10);
            rem = res/10;
            tmp->next = newNode;
            tmp = tmp->next;
            
            first = first->next;
            second = second->next;
        }
        
        // Adding Remaining Nodes
        while(first) {
            int res = first->data + rem;
            rem = res/10;
            util(res, tmp, first);
        }
        
        while(second) {
            int res = second->data + rem;
            rem = res/10;
            util(res, tmp, second);
        }

        // If there's remainder remaining
        // Keep adding new nodes until rem = 0
        while(rem > 0) {
            Node* newNode = new Node(rem%10);
            rem = rem/10;
            tmp->next = newNode;
            tmp = tmp->next;
        }
        
        // Reverse the result
        ansHead->next = reverse(ansHead->next);
        
        return ansHead->next;
    }
};