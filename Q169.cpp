// Using hashmap O(N) time O(N) space

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int size=a.size();
        map<int,int>m;
        for(int i=0;i<size;i++)m[a[i]]++;
        for(auto x:m)if(x.second>size/2)return x.first;
        return -1;
    }
};

//Using voting algorithm O(N) time O(1) space

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int count = 0;
        int candidate = 0;

        for (int num : a) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
    }
};
