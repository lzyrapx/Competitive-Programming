class Solution {
public:
    /*
    利用堆排序，O(NlogK)，适合处理海量数据。
    因为只要求k个数，所以使用最小堆就可以了。
    (如果是要取最大值就是用最大堆)
    */
    void heapsort(vector<int>&input, int root, int end)
    {
        for(int i = end - 1; i>= root; --i)
        {
            int parent = (i + root - 1) / 2;
            if(input[parent] > input[i])
            {
                swap(input[parent], input[i]);
            }
        }
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int>ans;
        if(k > input.size()) return ans;
        for(int i = 0; i < k; i++)
        {
            heapsort(input, i, input.size());
            ans.push_back(input[i]);
        }
        return ans;
    }
};