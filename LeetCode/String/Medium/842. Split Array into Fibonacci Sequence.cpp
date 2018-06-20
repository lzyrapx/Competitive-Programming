class Solution {
public:
    // Given a string S of digits, such as S = "123456579"
    // we can split it into a Fibonacci-like sequence [123, 456, 579].
    vector<int> splitIntoFibonacci(string S) {
        vector<int>fib;
        return dfs(S, fib, 0) ? fib : vector<int>();
    }
    bool dfs(string &S, vector<int>&fib, int pos)
    {
        if(pos == S.size() && fib.size() > 2) return true;
        int len = S[pos] == '0' ? 0 : 9;
        for(int i = 0; i <= len && pos + i < S.size(); i++) 
        {
            long long cur = stoll(S.substr(pos, i + 1));
            if(cur > ((1<<31) - 1)) return false;
            int j = fib.size();
            if((j < 2) || (j >= 2) && fib[j - 1] + fib[j - 2] == cur) 
            {
                fib.push_back(cur);
                if(dfs(S, fib, pos + i + 1)) return true;
                fib.pop_back();
            }
        }
        return false;
    }
};