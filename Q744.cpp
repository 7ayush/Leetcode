class Solution {
public:
    int binarySearch(vector<char>& letters, char target)
    {
        int start=0,end=letters.size()-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(letters[mid]>target)
            {
                if(mid-1<start||letters[mid-1]<=target)
                    return mid;
                else
                    end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        return -1;
    }
    char nextGreatestLetter(vector<char>& letters, char target) {
        int x=binarySearch(letters,target);
        if(x==-1)
        {
            return letters[0];
        }
        return letters[x];
    }
};
