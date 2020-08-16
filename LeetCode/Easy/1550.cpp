class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size() < 3) {
            return false;
        }
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] % 2 == 1) {
                cnt++;
                if(cnt == 3) {
                    return true;
                }
            }
            else {
                cnt = 0;
            }
        }
        return false;
    }
};