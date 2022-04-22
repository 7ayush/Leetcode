class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> vec;
        for(int i=left;i<=right;i++){
            int n=i;
            int flag=1;
            while(n){
                int rem=n%10;
                if(rem==0 || i%rem!=0){
                    flag=0;
                    break;
                }
                n/=10;
                
            }
            if(flag) vec.push_back(i);
        }
        return vec;
    }
};
