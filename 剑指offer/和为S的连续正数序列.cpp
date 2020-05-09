class Solution {
public:
    /*
     一旦确定序列的长度，那么连续正序列就唯一。
    */
    vector<vector<int> > FindContinuousSequence(int sum) {
        if(sum == 0) vector<vector<int>>();
        
        vector<vector<int>>ans;
        // S = (1 + n) * n / 2
        // => max(n) = 2*S
        for(int n = (int)sqrt(2 * sum); n >= 2; --n) //枚举长度
        {
            
            if( ( (n & 1) == 1 && (sum % n) == 0 ) || (( n& 1 ) == 0 && (sum % n) * 2 == n))
            {    
                vector<int>tmp;
                // a, a+1, a+2...a + n - 1
                // na + n(n-1) / 2 = sum
                // a = (sum / n) - (n - 1) / 2
                int k = (sum / n) - (n - 1) / 2;
                for(int j = 1; j <= n; j++)
                {
                    tmp.push_back(k++);
                }
                 ans.push_back(tmp);
            } 
        }
        return ans;
    }
};