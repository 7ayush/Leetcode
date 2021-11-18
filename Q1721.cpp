/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode *ptr=head;
        int count=0;
        while(ptr)
        {
            ptr=ptr->next;
            count++;
        }
        if(count-k==k-1)return head;
        if(count==k||k==1)
        {
            ptr=head;
            while(ptr&&ptr->next&&ptr->next->next)
            {
                ptr=ptr->next;
            }
            //If list has only 2 elements            
            if(ptr==head)
            {
                ptr=ptr->next;
                ptr->next=head;
                head->next=NULL;
                head=ptr;
                return head;
            }
            ListNode *x=ptr->next;
            x->next=head->next;
            ptr->next=head;
            head->next=NULL;
            head=x;
            return head;
        }
        ListNode *temp=head,*temp1=head;
        int x=k-2;
        while(x--)
        {
            temp=temp->next;
        }
        int y=count-k-1;
        while(y--)
        {
            temp1=temp1->next;
        }
        ListNode *op=temp,*o=temp->next,*on=temp->next->next;
        ListNode *tp=temp1,*t=temp1->next,*tn=temp1->next->next;
        // If t and o are next to each other self loops could be created
        if(t->next==o)
        {
            tp->next=o;
            o->next=t;
            t->next=on;
            
        }
        else if(o->next==t)
        {
            op->next=t;
            t->next=o;
            o->next=tn;
        }
        else
        {
            op->next=t;
            t->next=on;
            tp->next=o;
            o->next=tn;    
        }
        
        return head;
    }
};
