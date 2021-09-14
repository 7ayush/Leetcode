// First running fast pointer from 0-n and for the remaining time running the slow pointer and fast pointer till the fast pointer is not NULL
class Solution {
public:
    
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode *slow=head;
        ListNode *fast=head;
        for(int i=1;i<=n;i++){
            if(fast)
                fast=fast->next;       
            
        }
        
        if(fast==NULL)return head->next;
        
        while(fast->next)
        {
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;            
        return head;
    }
};
