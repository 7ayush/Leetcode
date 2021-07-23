// Check Palindrome O(N) time O(1) space
class Solution {
public:
    
    ListNode *reverse(ListNode *mid,ListNode *head)
    {
       ListNode *prev=mid,*curr=head,*nxt;
        while(curr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast&&fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *l2=reverse(slow,slow->next);
        slow->next=NULL;
        
        ListNode *p1=head,*p2=l2;
        
        while(p1&&p2)
        {
            if(p1->val!=p2->val)return false;
            p1=p1->next;
            p2=p2->next;
        }
        
        return true;
        
//         1->2->3<-3<-2<-1
//               |     
        
    }
};
