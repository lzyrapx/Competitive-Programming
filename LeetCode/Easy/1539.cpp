class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr.size() == 0) {
            return k;
        }
        int pre = 0;
        int diff = 0;
        for(int i = 0; i < arr.size(); i++) {
            diff = arr[i] - pre;
            if(diff > 1) {
                k = k - diff + 1;
            }
            if(k <= 0) {
                int num = k + diff - 1;
                for(int j = pre + 1; j < arr[i]; j++, num--) {
                    if(num == 1) {
                        return j;
                    }
                }
            }
            pre = arr[i];
        }
        return arr[arr.size() - 1] + k;
    }
};