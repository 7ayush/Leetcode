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
    ListNode* insertionSortList(ListNode* head) 
    {
        ListNode *ptr=head;
        ListNode *x=head,*n,*a;
        bool found=false;
        while(x&&x->next)
        {
            found=false;
            if(head==NULL)
            {
                return head;
            }
            if(x->next->val<head->val)
            {
                n=x->next;
                x->next=x->next->next;
                n->next=head;
                head=n;                
            }
            else
            {
                ptr=head;
                while(ptr->next&&(x->next->val>=ptr->next->val))
                {                                        
                    if(x==ptr)
                    {
                        found=true;
                        x=x->next;
                        break;
                    }
                    ptr=ptr->next;
                }
                if(!ptr)
                {
                    x=x->next;
                    continue;
                }
                if(!found)
                {
                    n=ptr->next;
                    a=x->next;
                    x->next=x->next->next;
                    a->next=n;
                    ptr->next=a;        
                }
                
                        
            }
        }
        return head;
        
    }
};
