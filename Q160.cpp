/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* util(ListNode *headA,ListNode *headB,int diff)
    {
        while(diff--)
        {
            headB=headB->next;
        }
        while(headA&&headB)
        {
            if(headA==headB)
                return headA;
            headA=headA->next;
            headB=headB->next;
        }
        return NULL;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1=headA,*ptr2=headB;
        int len1=0,len2=0;
        while(ptr1)
        {
            ptr1=ptr1->next;
            len1++;
        }
        while(ptr2)
        {
            ptr2=ptr2->next;
            len2++;
        }
        if(len1<len2) return util(headA,headB,len2-len1);
        else return util(headB,headA,len1-len2);
    }
};
