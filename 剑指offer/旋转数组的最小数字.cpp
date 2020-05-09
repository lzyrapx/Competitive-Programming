class Solution {
public:
	// 就是求第一次 rotateArray[i] > rotateArray[i+1]
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.size() == 0) return 0;
        int low = 0;
        int high = rotateArray.size() - 1;
        while(low < high)
        {
            int mid = (low + high) / 2;
            if(rotateArray[mid] > rotateArray[high])
            {
                low = mid + 1;
            }
            else if(rotateArray[mid] == rotateArray[high])
            {
                high = high - 1;
            }
            else if(rotateArray[mid] < rotateArray[high])
            {
                high = mid;
            }
        }
        return rotateArray[low];
    }
};