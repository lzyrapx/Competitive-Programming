class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string ans = "";
        vector<string>ve(numRows);
        
        int d = 1;
        int row = 0;
        for(auto c : s) {
            ve[row].push_back(c);
            row  = row + d;
            if(row == numRows - 1) d = -1;
            if(row == 0) d = 1;
        }
        for(auto x : ve) {
            // cout << x << endl;
            ans = ans + x;
        }
        return ans;
    }
};