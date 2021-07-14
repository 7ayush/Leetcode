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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
        ListNode *ans=NULL,*p1=l1,*p2=l2,*p,*temp=NULL;
        while(p1&&p2)
        {
            if(p1->val<p2->val)
            {
                temp=new ListNode(p1->val);
                p1=p1->next;
            }
            else
            {
                temp=new ListNode(p2->val);
                p2=p2->next;                
            }
            if(!ans)
            {
                ans=temp;
                p=temp;
            }
            else
            {
                p->next=temp;
                p=temp;
            }
        }
        if(p1)
        {
            if(ans==NULL)
            {
                ans=p1;    
            }
            else
            {
                p->next=p1;   
            }
            
        }
        if(p2)
        {
            if(ans==NULL)
            {
                ans=p2;    
            }
            else
            {
                p->next=p2;   
            }            
        }
        return ans;        
    }
};