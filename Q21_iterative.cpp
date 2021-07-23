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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) 
    {
        ListNode *result=NULL;
        ListNode *ptr;
        if(!a)return b;
        if(!b)return a;
        
        while(a&&b)
        {
            if(a->val<b->val)
            {
                if(!result)
                {
                    result=a;   
                    ptr=result;
                }
                else
                {
                    ptr->next=a;                    
                    ptr=a;
                }
                a=a->next;
            }
            else
            {
                if(!result)
                {
                    result=b;   
                    ptr=result;
                }
                else
                {
                    ptr->next=b;
                    ptr=b;
                }    
                b=b->next;
            }
        }
        if(!a) ptr->next=b;
        if(!b) ptr->next=a;
        return result;
    }
};
