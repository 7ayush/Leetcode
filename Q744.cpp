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
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(int i=0;i<letters.size();i++)
        {
            if(letters[i]>target)return letters[i];
        }
        return letters[0];
    }
};


//Binary Search
class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int mid, l = 0, r = letters.size() - 1;
		while(l < r){
			mid = (l + r) / 2;
			if(letters[mid] <= target){
				l = mid + 1;
			}
			else{
				r = mid;
			}
		}
		if(letters[l] > target){
			return letters[l];
		}
		return letters[0];
	}
};
