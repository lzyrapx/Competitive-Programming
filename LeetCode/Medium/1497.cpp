class Solution {
public:
    // 问 arr 中是否可以双双找 pair，让这些 pair 的和可以被 k 整除
    bool canArrange(vector<int>& arr, int k) {
        if(arr.size() == 0) {
            return false;
        }
        vector<int>ve(k + 1, 0);
        for(int i = 0; i < arr.size(); i++){
            ve[(arr[i] % k + k) % k]++;
        }
        for(int i = 1; i < k - i; i++) {
            if(ve[i] != ve[k - i]) {
                return false;
            }
        }
        if(ve[0] % 2 == 0) {
            return true;
        }
        return false;
    }
};