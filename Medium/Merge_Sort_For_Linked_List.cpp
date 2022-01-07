class Solution{
  public:
    //
    // Dividing a linked list in TWO
    vector<Node*> halfNodes(Node* head) {
        Node *slow = head, *fast = head, *prev = NULL;
        
        while(fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Breaking the Linked List in half
        prev->next = NULL;
        
        // Push the two halves of Linked List
        vector<Node*> ans;
        ans.push_back(head);
        ans.push_back(slow);
        
        return ans;
    }
    //
    // Link two sorted linked list
    Node* merge(Node* first, Node* second)
    {
        // If there is 1 or more lists empty
        if(!first)	return second;
        if(!second)	return first;
        
        Node *ans = new Node(0);
        Node *a = first, *b = second;
        Node* tmp = ans;
    
        // Merge two lists while sorting
        while(a && b) {
            if(a->data < b->data) {
                tmp->next = a;
                a = a->next;
            }
            else {
                tmp->next = b;
                b = b->next;
            }
            tmp = tmp->next;
        }
        
        // Link remaining nodes from linked list
        while(a) {
            tmp->next = a;
            a = a->next;
            tmp = tmp->next;
        }
        
        while(b) {
            tmp->next = b;
            b = b->next;
            tmp = tmp->next;
        }
        tmp->next = NULL;
        
        return ans->next;
    }
    //
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // If there're 0 or 1 node in linked list
        if(!head || !head->next) {
            return head;
        }
        
        // Divide the list in two
        vector<Node*> twoHalf = halfNodes(head);
        Node* first  = twoHalf[0];
        Node* second = twoHalf[1];
        
        first  = mergeSort(first);
        second = mergeSort(second);
        Node* ans = merge(first, second);
        
        return ans;
    }
};