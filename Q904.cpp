class Solution {
public:
    /**
     * @param head: the first Node
     * @return: the answer after plus one
     */
    ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;
 
        /* reverse the rest list and put
          the first element at the end */
        ListNode* rest = reverse(head->next);
        head->next->next = head;
 
        /* tricky step -- see the diagram */
        head->next = NULL;
 
        /* fix the head pointer */
        return rest;
    }
    ListNode * plusOne(ListNode * head) {
        // Write your code here
        if(!head)
        {
            ListNode *ptr=new ListNode(1);
            return ptr;
        }
        head=reverse(head);
        int carry=1;
        ListNode* ptr=head;
        ListNode *last=NULL;
        while(ptr&&carry==1)
        {
            if(!ptr->next)last=ptr;
            ptr->val=ptr->val+carry;
            carry=ptr->val/10;
            ptr->val=ptr->val%10;
            ptr=ptr->next;
        }
        if(carry==1)
        {
            last->next=new ListNode(1);
        }
        head=reverse(head);
    }
};
