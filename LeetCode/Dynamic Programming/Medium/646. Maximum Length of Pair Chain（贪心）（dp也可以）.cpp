class Solution {
public:
    static int cmp(vector<int>& A, vector<int>& B)
    {
        return (A[1] < B[1]) || (A[1] == B[1] && A[0] < B[0]); 
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        sort(pairs.begin(), pairs.end(), cmp);
        int cnt = 1;
        vector<int>& Pair = pairs[0];
        for(int i = 1; i < (int)pairs.size(); i++)
        {
            if(pairs[i][0] > Pair[1]) 
            {
                Pair = pairs[i];
                cnt ++;
            }
        }
        return cnt;
    }
    
};