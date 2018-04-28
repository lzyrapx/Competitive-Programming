class Solution {
public:
    const int mod = 1e9 + 7;
    int cnt = 0;
    // 归并排序(从上往下)
    void mergesort(vector<int>&a,int start,int end)
    {
        if(start >= end) return;
        int mid = (start + end) >> 1;
        mergesort(a,start,mid);
        mergesort(a,mid+1,end);
        merge(a,start,mid,end);
    }
    // 将一个数组中的两个相邻有序区间合并成一个
    void merge(vector<int>&a, int start, int mid, int end)
    {
        vector<int>tmp(end - start + 1);
        int i = start, j = mid + 1;
        int k = 0;
        while(i <= mid && j <= end)
        {
            if(a[i] <= a[j]) tmp[k++] = a[i++];
            else {
                tmp[k++] = a[j++];
                cnt += mid - i + 1; // 计算逆序数
                cnt %= mod;
            }
        }
        while(i <= mid) tmp[k++] = a[i++];
        while(j <= end) tmp[k++] = a[j++];
        
        for(k = 0; k < tmp.size(); k++)
        {
            a[start + k] = tmp[k];
        }
    }
    int InversePairs(vector<int> data) {
        if(data.size() == 0) return 0;
        mergesort(data, 0 , data.size() - 1);
        return cnt % mod;
    }
};