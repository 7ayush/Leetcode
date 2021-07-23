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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(!head)return head;
        ListNode *ptr=head,*temp=head->next;              
        if(!temp)return head;
        while(temp)
        {
            while(temp&&temp->val==ptr->val)
            {
                temp=temp->next;
            }
            ptr->next=temp;
            ptr=temp;
            if(ptr)
            {
                temp=ptr->next;                
            }
            
        }
        return head;
        
    }
};
