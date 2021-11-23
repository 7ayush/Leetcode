// Mergesort
class Solution {
public:
    ListNode* sortedMerge(ListNode* a, ListNode* b) 
    { 
        ListNode* result = NULL; 
      
        /* Base cases */
        if (a == NULL) 
            return (b); 
        else if (b == NULL) 
            return (a); 
      
        /* Pick either a or b, and recur */
        if (a->val <= b->val) { 
            result = a; 
            result->next = sortedMerge(a->next, b); 
        } 
        else { 
            result = b; 
            result->next = sortedMerge(a, b->next); 
        } 
        return (result); 
    } 
    void fbsplit(ListNode* source, ListNode** frontRef, ListNode** backRef) 
    { 
        ListNode* fast; 
        ListNode* slow; 
        slow = source; 
        fast = source->next; 
      
        /* Advance 'fast' two nodes, and advance 'slow' one node */
        while (fast != NULL) { 
            fast = fast->next; 
            if (fast != NULL) { 
                slow = slow->next; 
                fast = fast->next; 
            } 
        } 
      
        /* 'slow' is before the midpoint in the list, so split it in two  
        at that point. */
        *frontRef = source; 
        *backRef = slow->next; 
        slow->next = NULL; 
    } 
    void sm(ListNode **head)
    {
        ListNode *h=*head;
        ListNode *a=NULL,*b=NULL;
        
        if(!h||!h->next)
        {
            return;
        }
        fbsplit(h,&a,&b); 
        sm(&a);
        sm(&b);
        *head=sortedMerge(a,b);
    }
    ListNode* sortList(ListNode* head) {
        sm(&head);
        return head;
    }
};
