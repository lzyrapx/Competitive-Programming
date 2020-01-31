/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-31 22:38:31
 */
class Solution {
public:
    // segment tree
    // two points
    // deque
    // binary search
    
    #define lson l , mid , rt << 1
    #define rson mid+1 , r, rt<<1|1
    
    int MIN[50000 * 4];
    
    void pushup(int rt)
    {
        MIN[rt] = min(MIN[rt<<1], MIN[rt<<1|1]);	
    }
    void build(int l,int r, int rt, int id, int val)
    {
        // cout << "l = " << l << " " << "r = " << r << endl;
        if(id > r || id < l) return;
        if(l == r){
            MIN[rt] = val;
            return;
        }
        int mid = (l + r) >> 1;
        build(l , mid , rt << 1, id, val);
        build(mid+1 , r, rt<<1|1, id, val);
        pushup(rt); 
    }
    int query(int l, int r, int rt, int val)
    {
        if(l == r){
            return l;
        }
        int mid = (l + r) >> 1;
        if(MIN[rt << 1 | 1] <= val) {
            return query(mid + 1 , r, rt << 1 | 1, val);
        }
        // MIN[rt << 1] > val
        return query(l, mid , rt << 1, val);
    }
    int shortestSubarray(vector<int>& A, int K) {
        
        memset(MIN, '?', sizeof(MIN));
        
        int n = A.size() + 1;
        int len = INT_MAX;
        int sum = 0;
        
        build(0, n - 1, 1, 0, 0);
        // cout << MIN[0] << endl;
        for(int i = 0; i < A.size(); i++) {
            sum += A[i];
            if(sum >= K) {
                len = min(len, i + 1);
            }
            // sum[i] - sum[pos] <= K
            // sum[pos] <= sum[i] - K
            if(MIN[1] <= sum - K) {
                int pos = query(0, n - 1, 1, sum - K);
                // cout << "pos = " << pos << " i = " << i << endl;
                len = min(len, i - pos + 1);  
            }
            build(0, n - 1, 1, i + 1, sum);
        }
        if(len == INT_MAX) {
            return -1;
        }
        return len;
    }
};