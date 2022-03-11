class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)return head;
        ListNode *ptr=head;
        int count=1;
        while(ptr&&ptr->next)
        {
            count++;
            ptr=ptr->next;
        }
        k=k%count;
        int x=count-k-1;
        ListNode *temp=head;
        while(x--&&temp)temp=temp->next;
        ptr->next=head;
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};
