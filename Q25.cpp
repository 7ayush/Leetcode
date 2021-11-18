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
    ListNode *heads=NULL;
    void splitInOne(ListNode *head,ListNode *last,int k)
    {
        if(!head)return;
        ListNode *curr=head,*prev=NULL,*nxt=NULL;
        ListNode *ptr=head;
        for(int i=0;i<k;i++)
        {
            if(!ptr)return;
            if(ptr)ptr=ptr->next;
        }
        
        while(curr!=ptr)
        {
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        head->next=curr;
        if(last==NULL)heads=prev;
        else
        {
            last->next=prev;
        }
        splitInOne(curr,head,k);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        heads=head;
        splitInOne(head,NULL,k);
        return heads;
    }
};
