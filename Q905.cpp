//Using comparator function
class Solution {
public:
    static bool compare(int &a,int &b)
    {
        return (a%2==0&&b%2==1);        
    }
    vector<int> sortArrayByParity(vector<int>& nums) {

        sort(nums.begin(),nums.end(),compare);
        return nums;
    }
};

//Using extra space 

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        vector<int>odd;
        vector<int>even;
        for(auto i:nums)
        {
            if(i%2)odd.push_back(i); 
            else even.push_back(i);
        }
        int i=0;        
        for(int j=0 ;j<even.size();j++)
        {
            nums[i++]=even[j];
        }
        for(int j=0 ;j<odd.size();j++)
        {
            nums[i++]=odd[j];
        }
        return nums;
    }
};



//Inplace swap
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n=nums.size();
        int i=0;
        int j=0;
        while(i<n&&j<n)
        {
            j=i+1;   
            if(nums[i]%2==1)
            {
                while(j<n&&nums[j]%2==1){
                    j++;   
                }
                if(j<n)swap(nums[i++],nums[j++]);
            }
            else
            {
                i++;   
            }
            
        }
        return nums;
    }
};



//Two Pointer
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) 
    {
        int n=nums.size();
        int i=0;
        int j=n-1;
        while (i < j) {
            if (nums[i] % 2 > nums[j] % 2) swap(nums[i],nums[j]);
            if (nums[i] % 2 == 0) i++;
            if (nums[j] % 2 == 1) j--;
        }
        return nums;
    }
};


