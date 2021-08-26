class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        
        stack<int>s;
        s.push(-1);
        int max=-1;
        for(int i=arr.size()-1;i>0;i--)  
        {
            if(arr[i]>max)
            {
                max=arr[i];   
            }
            s.push(max);
        }
        int i=0;
        while(!s.empty())
        {
            arr[i]=s.top();
            s.pop();
            i++;
        }
        return arr;
        
    }
};

//Using no extra space and updating the max in the array itself
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) 
    {
        int maxx=-1;
        for(int i=arr.size()-1;i>=0;i--)  
        {
            int x=arr[i];
            arr[i]=maxx;
            maxx=max(x,maxx);            
        }
        return arr;
        
    }
};
