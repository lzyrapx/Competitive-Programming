class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        int dp = 0;
        int maxx = -INT_MAX;
        for(int i = 0; i < array.size(); i++)
        {
            if(dp >= 0){
                dp += array[i];
            }
            else dp = array[i];
            if(maxx < dp) {
                maxx = dp;
            }
        }
        return maxx;
    }
};