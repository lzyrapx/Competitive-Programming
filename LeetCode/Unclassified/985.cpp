/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-12-29 00:58:31
 */
class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        map<int,int>mp;
        int sum = 0;
        for(int i = 0; i < A.size(); i++) {
            mp[i] = A[i];
            if(A[i] % 2 == 0) {
                sum += A[i];
            }
        }
        vector<int>ans;
        for(int i = 0; i < queries.size(); i++) {
            if(mp[queries[i][1]] % 2 == 0) {
                sum -= mp[queries[i][1]];
            }
            mp[queries[i][1]] += queries[i][0];
            if(mp[queries[i][1]] % 2 == 0) {
                sum += mp[queries[i][1]];
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};