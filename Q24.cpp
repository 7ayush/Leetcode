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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
        {
            return head;
        }
        
        ListNode*ans=new ListNode(0);
        ListNode*prev=ans;
        ListNode*temp=head;
        while(temp && temp->next)
        {
            prev->next=temp->next;//2
            ListNode *t=temp;
            temp=temp->next->next;
            prev->next->next=t;
            t->next=temp;
            prev=prev->next->next;
        }
        return ans->next;
    }
};

 
