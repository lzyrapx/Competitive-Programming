class NumArray {
public:
    vector<int> Sum = {0};
    NumArray(vector<int> nums) {
        int summ = 0;
        for (int n : nums) {
            summ += n;
            Sum.push_back(summ);
        }
    }

    int sumRange(int i, int j) {
        return Sum[j+1] - Sum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */