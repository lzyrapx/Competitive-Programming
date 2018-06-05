class Solution {
public:
    //从数组中取若干个数字的函数，而且取出的数要最大
    vector<int>maxVector(vector<int>nums, int k)// 取 k 个
    {
        int drop = nums.size() - k; // 需要丢弃的数字的个数
        vector<int>ans;
        for(auto x : nums)
        {
            //数组的尾元素小于当前遍历的元素,去掉ans数组的尾元素,drop自减一
            while(drop > 0 && ans.size() > 0 && ans.back() < x)
            {
                ans.pop_back();
                drop--;
            }
            ans.push_back(x);
        }
        ans.resize(k);
        return ans;
    }
    //从两个数组开头每次取两个，把大的加入结果数组，然后删掉这个大的
    //然后继续取一对比较，直到两个数组都为空停止
    vector<int> mergeVector(vector<int>nums1, vector<int>nums2)
    {
        vector<int>ans;
        while(nums1.size() + nums2.size())
        {
            vector<int>&tmp = nums1 > nums2 ? nums1 : nums2;
            ans.push_back(tmp[0]);
            tmp.erase(tmp.begin());
        }
        return ans;
    }
    
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) return vector<int>();
        int m = nums1.size();
        int n = nums2.size();
        vector<int>ans;
        for(int i = max(0, k - n); i <= min(k , m); i++)
        {
            ans = max(ans, mergeVector(maxVector(nums1, i), maxVector(nums2, k - i)));
        }
        return ans;
    }
};