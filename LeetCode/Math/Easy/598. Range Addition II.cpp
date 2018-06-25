class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0) return m * n;
        int p = m, q = n;
        for(int i = 0; i < ops.size(); i++) {
            p = min(p,ops[i][0]);
            q = min(q,ops[i][1]);
        }
        return p * q;
    }
};