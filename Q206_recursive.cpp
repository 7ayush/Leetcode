// Recursive solution reversing a linked list
// O(N) time O(N) stack space
class Solution {
public:
    void recursive(ListNode** head,ListNode* prev,ListNode* curr)
    {
        if(!curr)
        {
            *head=prev;
            return;
        }
        ListNode* nxt=curr->next;
        curr->next=prev;
        recursive(head,curr,nxt);
        
    }
    ListNode* reverseList(ListNode* head) 
    {
        if(!head||!head->next)return head;
        recursive(&head,NULL,head);
        return head;
    }
};
