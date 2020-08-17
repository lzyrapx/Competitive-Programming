class Solution {
public:
    // 利用 1～N, 构造一个不存在 A[k] * 2 = A[i] + A[j] (i < j < k) 的漂亮数组
    /* 1. A 是漂亮数组，则 a * A + b 也是漂亮数组 
     * 2. A 为奇数漂亮数组，B 为偶数漂亮数组，A + B 为漂亮数组
     * 3. 数组两两配对，左数组 * 2 - 1 一定是奇数组，右数组 * 2 一定为偶数组，合并一定为漂亮数组
     * 假设 [1] 是最小漂亮数组，按照上面规律递推得到的一定是漂亮数组。 
     * |1|1|1|1|1|1|1|1|
     * |1 2|1 2|1 2|1 2|
     * |1 3 2 4|1 3 2 4|
     * |1 5 3 7 2 6 4 8|
     */
    // 总结：尽量让偶数到右边
    void depart(vector<int>&arr, int low, int high) {
        if(low >= high) return;
        int mid = (low + high) / 2;
        depart(arr, low, mid);
        depart(arr, mid + 1, high);
        for(int i = low; i <= mid; i++) {
            arr[i] = 2 * arr[i] - 1;
        }
        for(int i = mid + 1; i <= high; i++) {
            arr[i] = 2 * arr[i];
        }
    }
    vector<int> beautifulArray(int N) {
        vector<int>arr(N, 1);
        depart(arr, 0, N - 1);
        return arr;
    }
};