class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int difference_limit) {
        size_t count(0);
		bool flag(true);

		for (const auto &arr1_num : arr1) {
			flag = true;

			for (const auto &arr2_num : arr2) {
				if (abs(arr1_num - arr2_num) <= difference_limit) {
					flag = false;
					break;
				}
			}

			if (flag) {
				count++;
			}
		}

		return count;
    }
};
