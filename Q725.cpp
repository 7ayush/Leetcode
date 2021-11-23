class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k)     {
        vector<ListNode*>ans;
        ListNode *ptr=head;
        int count=0;
        while(ptr)
        {
            ptr=ptr->next;
            count++;
        }
        if(k>count)
        {
            ptr=head;
            while(ptr&&k--)
            {
                ListNode *temp=ptr->next;
                ptr->next=NULL;
                ans.push_back(ptr);
                ptr=temp;
            }
            while(k--)
            {
                ans.push_back(NULL);
            }
            return ans;
        }
        int gNo=count%k;
        int eNo=k-gNo;
        ptr=head;
        while(gNo--)
        {
            int size=count/k+1;
            ListNode *temp=ptr;
            ListNode *temp1=ptr;
            while(--size)
            {
                temp=temp->next;
            }
            ptr=temp->next;
            temp->next=NULL;
            ans.push_back(temp1);            
        }
        while(eNo--)
        {
            int size=count/k;
            ListNode *temp=ptr;
            ListNode *temp1=ptr;
            while(--size)
            {
                temp=temp->next;
            }
            ptr=temp->next;
            temp->next=NULL;
            ans.push_back(temp1);            
        }
        return ans;
    }
};
