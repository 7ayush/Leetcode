class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        int length=0;
        ListNode *ptr=head;
        while(ptr)
        {
            ptr=ptr->next;
            length++;
        }
        ptr=head;
        for(int i=0;i<length/2-1;i++)
        {
            ptr=ptr->next;
        }
        if(ptr->next)
            ptr->next=ptr->next->next;
        else
            return NULL;
        return head;
    }
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Edge case: return nullptr if there is only one node.
        if (head -> next == NULL)
            return NULL;
        
        // Initialize two pointers, 'slow' and 'fast'.
        ListNode *slow = head, *fast = head -> next -> next;
        
        // Let 'fast' move forward by 2 nodes, 'slow' move forward by 1 node each step.
        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        // When 'fast' reaches the end, remove the next node of 'slow' and return 'head'.
        slow -> next = slow -> next -> next;
        return head;
    }
};
