class Solution {
public:
    int isValid(vector<string> v,int i)
    {
        if(v[i]!="#"&&i+1<v.size()&&v[i+1]!="#")
        {
            int right=isValid(v,i+1);            
            if(right==v.size()||right==0)return right;
            return isValid(v,right);
                
        }
        if(v[i]!="#"&&i+2<v.size()&&v[i+1]=="#"&&v[i+2]=="#")
        {
            return i+3;            
        }        
        else if(v[i]!="#"&&i+2<v.size()&&v[i+1]=="#"&&v[i+2]!="#")
        {
            return isValid(v,i+2);
        }
        else if(v[i]=="#")return i+1;
        return 0;
    }
    bool isValidSerialization(string preorder) {
        vector<string> v;
 
        stringstream ss(preorder);

        while (ss.good()) {
            string substr;
            getline(ss, substr, ',');
            v.push_back(substr);
        }
        if(v.size()==1&&v[0]=="#")return true;
        int n=isValid(v,0);
        return n==v.size();
    }
};


