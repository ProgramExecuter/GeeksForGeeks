void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // If only 1 Node
    if(head->next == head) {
        head->next = NULL;
        *head1_ref = head;
        *head2_ref = NULL;
        return;
    }
    
    
    Node *slow = head, *fast = head;
    
    // Reach middle of list
    while(fast->next != head  &&  fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reach last Node of second half of linked list
    // And make its next = slow->next
    Node* tmp = slow->next;
    while(tmp->next != head) {
        tmp = tmp->next;
    }
    tmp->next = slow->next;
    
    // Second Half List's head
    *head2_ref = slow->next;
    
    // Reach last Node of first half of linked list
    // And make its next = head
    slow->next = head;
    
    // First Half List's head
    *head1_ref = head;
}