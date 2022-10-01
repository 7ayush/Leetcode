class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2 == 1){
            return {};
        }
        map<int, int> counter;
        for(int num: changed){
            counter[num]++;
        }
        vector<int> op;
        for(auto it=counter.rbegin(); it!= counter.rend(); it++){
            int count = it->second;
            if (count == 0){
                continue;
            }
            int num = it->first;
            if (num % 2 == 1){
                return {};
            }
            int half = num/2;
            if (counter[half] < count){
                return {};
            }
            if (num == 0){
                if (count % 2 == 1){
                    return {};
                }
                for(int j = 0; j<count/2; j++){
                    op.push_back(0);
                }
                counter[0] = 0;
            }else {
                for(int j=0; j<count; j++){
                    op.push_back(half);
                    counter[half]--;
                }
            }
        }
        return op;
    }
};
