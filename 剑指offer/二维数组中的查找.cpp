class Solution {
public:
    bool Find(int target, vector<vector<int> > array) { // O(n+m)
        if(array.size() == 0) return false;
        int i = 0;
        int j = array[0].size() -1;
        int val = array[i][j];
        while(j >= 0 && i <= array.size() - 1)
        {
            if(array[i][j] == target) return true;
            else if(target > array[i][j] ) i++;
            else if(target < array[i][j]) j--;
        }
        return false;
    }
};