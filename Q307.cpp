class NumArray {
    vector<int>binaryIndexedTree;
    vector<int>nums;
    int n = 0;
    int getNext(int index){
        return index + (index & -index);
    }
    int getParent(int index){
        return index - (index & -index);
    }
    // index in array first convert to Binary Indexed Tree
    int getSum(int index){
        index+=1;
        int sum = 0;
        while(index > 0){
            sum += binaryIndexedTree[index];
            index = getParent(index);
        }
        return sum;
    }
    // index in array first convert to Binary Indexed Tree
    void updateBinaryIndexedTree(int val, int index){
        index+=1;
        while(index <= n){
            binaryIndexedTree[index] += val;
            index = getNext(index);
        }
    }
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        binaryIndexedTree.resize(n+1, 0);
        for(int i=1; i <= n; i++){
            updateBinaryIndexedTree(nums[i-1], i -1);
        }
    }
    
    void update(int index, int val) {
        updateBinaryIndexedTree(val - nums[index], index);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int one = getSum(right);
        if(left == 0) {
            return one;
        }
        int two = getSum(left - 1);
        return one - two;
    }
};

