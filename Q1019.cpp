//O(N^2) time and O(1) space
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>ans;
        ListNode *ptr=head;
        while(ptr)
        {
            ListNode *ptr1=ptr->next;
            while(ptr1)
            {
                if(ptr1&&ptr1->val>ptr->val)
                {
                    ans.push_back(ptr1->val);
                    break;
                }
                ptr1=ptr1->next;
            }
            if(!ptr1)ans.push_back(0);
            ptr=ptr->next;
        }
        return ans;
    }
};
