class Solution {
public:
    // a == b => a^b=0
    // 对于 i, j, k, 只要 i～k异或等于0，那中间的j随便取
    int countTriplets(vector<int>& arr) {
        if(arr.size() < 2) {
            return 0;
        }
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            for(int k = i + 1; k < arr.size(); k++) {
                x ^= arr[k];
                if(x == 0) {
                    ans += (k - i);
                }
            }
        }
        return ans;
    }
};