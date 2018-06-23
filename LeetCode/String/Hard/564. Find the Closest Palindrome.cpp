class Solution {
public:
    long long mirror(long long n)
    {
        string s = to_string(n);
        int i = 0, j = s.size() - 1;
        while(i < j) {
            s[j] = s[i];
            i++;
            j--;
        }
        cout << stol(s) << endl;
        return stol(s);
    }
    string nearestPalindromic(string n) {
        if(n.size() == 0) return "";
        int order = pow(10, n.size() / 2);
        long long ans = stol(n);
        long long tmp  = mirror(ans);
        long long big = mirror((ans / order) * order + order + 1);
        long long small = mirror((ans / order) * order - 1);
        if(tmp > ans) {
            big = max(tmp , small);
        }
        else if(tmp < ans) {
            small = max(tmp,small);
        }
        if(ans - small <= big - ans) ans = small;
        else ans = big;
        return to_string(ans);
    }
};