// This is a minheap so minimum element is on the top.
// We are doing a different approach over here. Maxsize of the pq will be k.
// If the pq size increases then we remove minimum element from it because it will definitely not be the answer
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for (auto i : nums)
        {
            pq.push(i);
            if (pq.size() > size)
                pq.pop();
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > size)
                pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
