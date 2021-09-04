class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int carry=0;
        ListNode *l=NULL;
        ListNode *ptr=NULL;
        ListNode *temp=NULL;
        while(l1&&l2)
        {
            temp=new ListNode((l1->val+l2->val+carry)%10);
            carry=(l1->val+l2->val+carry)/10;
            if(!l)
            {
                l=temp;
                ptr=l;
            }
            else
            {
                ptr->next=temp;    
                ptr=temp;
            }
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            temp=new ListNode((l1->val+carry)%10);
            carry=(l1->val+carry)/10;
            if(!l)
            {
                l=temp;
                ptr=l;
            }
            else
            {
                ptr->next=temp;    
                ptr=temp;
            }
            l1=l1->next;
        }
        while(l2)
        {
            temp=new ListNode((l2->val+carry)%10);
            carry=(l2->val+carry)/10;
            if(!l)
            {
                l=temp;
                ptr=l;
            }
            else
            {
                ptr->next=temp;    
                ptr=temp;
            }
            l2=l2->next;
        }
        if(carry>0)
        {
            temp=new ListNode(carry);
            ptr->next=temp;
        }
        return l;
    }
};
