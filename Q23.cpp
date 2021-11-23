// Approach 1 in this we are merging lists consecutively in pairs of 2 and then returning the answer
class Solution {
public:
    ListNode *merge(ListNode *a,ListNode *b)
    {
        ListNode *result=NULL;
        if(a&&b)
        {
            if(a->val<b->val)
            {
                result=a;
                result->next=merge(a->next,b);
            }
            else
            {
                result=b;
                result->next=merge(a,b->next);
            }
        }
        else if(a) result=a;
        else result=b;
        return result;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        for(int i=1;i<lists.size();i++)
        {
            lists[0]=merge(lists[0],lists[i]);
        }
        return lists[0];
    }
};

// Divide and conquer
class Solution {
public:
    ListNode* merge(ListNode* a,ListNode *b)
    {
        ListNode *result=NULL;
        if(a&&b)
        {
            if(a->val<b->val)
            {
                result=a;
                result->next=merge(a->next,b);
            }
            else
            {
                result=b;
                result->next=merge(a,b->next);
            }
        }
        else if(a) result=a;
        else result=b;
        return result;
    }
    void divide(vector<ListNode*>&lists,int l,int r)
    {
        if(l>=r)return;
        int mid=(l+r)/2;
        divide(lists,l,mid);
        divide(lists,mid+1,r);
        lists[l]=merge(lists[l],lists[mid+1]);
    
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        divide(lists,0,lists.size()-1);
        return lists[0];
    }
};

// Divide and conquer
class Solution {
    ListNode* SortedMerge(ListNode* a, ListNode* b)
    {
        ListNode* result = NULL;

        if (a == NULL)
            return b;
        else if (b == NULL)
            return a;

        if (a->val <= b->val) {
            result = a;
            result->next = SortedMerge(a->next, b);
        }
        else {
            result = b;
            result->next = SortedMerge(a, b->next);
        }
        return result;
    }
    ListNode* divideAndConquer(vector<ListNode*>& lists, int left, int right) {
        if(left == right) {
            return lists[left];
        }
        int mid = left + (right -left)/2;
        ListNode* leftList = divideAndConquer(lists, left, mid);
        ListNode* rightList = divideAndConquer(lists, mid + 1, right);
        return SortedMerge(leftList, rightList);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        return divideAndConquer(lists, 0, lists.size() - 1);
    }
};
