class Solution {
public:
    // 给你一个数组，数组的每个元素表示你能前进的最大步数，最开始时你在第一个元素所在的位置，
    // 之后你可以前进，问能不能到达最后一个元素位置。路径不唯一。
    /*
    思路：贪心
    从第一步开始计算可以前进的最大步长，每走一步更新该值，始终保持当前位置的时候可前进步长最大。
    到达最终位置前，若出现步长< 0的情况，说明失败。
    */
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return true;
        int step = nums[0];
        for(int i = 1; i < n; i++) {
            step--;
            if(step < 0) {
                return false;
            }
            if(nums[i] > step)
            {
                step = nums[i];
            }
        }
        return true;
    }
};