class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int ans = 0;
        vector<int>h(n + 1,0);
        vector<int>left(n + 1, 0);
        vector<int>right(n + 1,n);
        
        for(int i = 0; i < matrix.size(); i++) //行
        {
            int now_left = 0;
            int now_right = matrix[0].size();
            for(int j = 0; j < matrix[0].size(); j++) //矩形的最左边
            {
                if(matrix[i][j] == '1')
                {
                    h[j]++;
                    left[j] = max(left[j], now_left);
                }
                else
                {
                    h[j] = 0;
                    left[j] = 0;
                    now_left = j + 1;
                }
            }
            
            for(int j = matrix[0].size() - 1; j >= 0; --j)
            {
                if(matrix[i][j] == '1')
                {
                    right[j] = min(right[j], now_right); //注意：去最小值！
                }
                else
                {
                    right[j] = matrix[0].size();
                    now_right = j ;
                }
                ans = max(ans,h[j] * (right[j] - left[j]) );
            }
        }
        return ans;
    }
};