class Solution {
public:
    ListNode *lastNode(ListNode *ptr)
    {
        int x=ptr->val;
        ListNode *temp;
        if(ptr->next&&ptr->next->val==x)
        {
            ptr=ptr->next;
            while(ptr&&ptr->val==x)
            {
                temp=ptr;
                ptr=ptr->next;
            }
            return temp;
        }
        else
        {
            return NULL;
        }
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *ptr=new ListNode(0);
        ptr->next=head;
        ListNode *ans=ptr;        
        ListNode *temp=ptr->next; 
        while(temp)
        {
            ListNode *last=lastNode(temp);
            if(last)
            {
                ptr->next=last->next;
                temp=ptr->next;
            }
            else
            {
                ptr=ptr->next;
                temp=temp->next;              
            }
            
        }
        return ans->next;
    }
};
