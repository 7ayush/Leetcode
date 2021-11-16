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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {        
        ListNode *ptr=head;
        int count=1;
        ListNode *x=NULL,*y=NULL,*start=NULL,*end=NULL;
        while(ptr)
        {                       
            if(count==left-1)x=ptr;
            if(count==right)end=ptr;
            count++;
            ptr=ptr->next;
        }
        if(x)start=x->next;
        else
            start=head;
        y=end->next;
        
        ListNode *prev=NULL,*curr=start,*nxt;
        while(curr!=y)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        if(left==1)
        {
            head=prev;
        }
        else
        {
            x->next=prev;
        }
        start->next=y;
        return head;
    }
    
    
};
