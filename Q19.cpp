// Counting the number of elements and then on deleting the node by iterating once again
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        int count=0;
        ListNode *ptr=head;
        while(ptr)
        {
            count++;
            ptr=ptr->next;
        }
        if(n==count){
            head=head->next;
            return head;
        }
        int x=count-n-1;
        ptr=head;
        while(x--)
        {
            ptr=ptr->next;
        }
        if(ptr->next)
        {
            ptr->next=ptr->next->next;
        }
        return head;
        
    }
};
