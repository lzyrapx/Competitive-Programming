class Solution {
public:
    // 既然递增，那就 双指针
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int>ans;
        int i = 0;
        int j = array.size() - 1;
        while(i < j)
        {
            if(array[i] + array[j] == sum) {
                ans.push_back(array[i]);
                ans.push_back(array[j]);
                break;
            }
            while(i < j && array[i] + array[j] > sum) j--;
            while(i < j && array[i] + array[j] < sum) i++;
        }
        return ans;
    }
};