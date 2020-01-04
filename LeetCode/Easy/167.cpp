/*
 * @Descripttion: boring life && prevent age-related memory loss.
 * @Version: 1.0.0
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-10-02 20:21:50
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0;
        int high = numbers.size() - 1;
        while(numbers[low] + numbers[high] != target) {
            if(numbers[low] + numbers[high] < target) {
                low ++;
            }
            else {
                high --;
            }
        }
        return vector<int>({low + 1, high + 1});
    }
};