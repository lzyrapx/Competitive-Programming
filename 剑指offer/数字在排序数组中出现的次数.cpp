class Solution {
public:
    int search(vector<int>&data, double num)
    {
        int low = 0;
        int high = data.size() - 1;
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(data[mid] < num) {
                low = mid + 1;
            }
            else if(data[mid] > num) {
                high = mid - 1;
            }
        }
        return low;
    }
    int GetNumberOfK(vector<int> data ,int k) {
        if(data.size() == 0) return 0;
        return search(data,k + 0.5) - search(data,k - 0.5);
    }
};