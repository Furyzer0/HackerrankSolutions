/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* fast, Node* slow) {
    if(fast == NULL || fast -> next == NULL) return false;
    
    if(fast == slow) return true;
    
    return has_cycle(fast -> next -> next, slow -> next);
}

bool has_cycle(Node* head) {
    if(head == NULL) return false;
    
    return has_cycle(head -> next, head );
}
