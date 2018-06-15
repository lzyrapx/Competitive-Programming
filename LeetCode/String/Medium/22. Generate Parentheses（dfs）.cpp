class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        if(n == 0) return ans;
        if(n == 1) return vector<string>({"()"});
        string s = "";
        dfs(n,n,s,ans);
        return ans;
    }
    // 剩余要安排左括号数量和右括号数量
    void dfs(int left, int right, string s,vector<string>&ans){
        if(left == 0 && right == 0) {
            // cout << s << endl;
            ans.push_back(s);
            return;
        }
        if(left > 0) {
            dfs(left - 1, right, s + "(", ans);
        }
        if(right > left) {
            dfs(left, right - 1, s + ")", ans);
        }
    }
};