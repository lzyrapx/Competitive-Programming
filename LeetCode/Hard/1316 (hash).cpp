/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-01-23 22:45:43
 */
class Solution {
public:
    typedef long long ll;
    const ll A = 1000000007, B = 998244353;
    ll h[2001], base[2001];
    void hash(string s) {
        h[0] = s[0] % B;
        base[0] = 1;
        for(int i = 1; i < s.size(); i++) {
            h[i] = (h[i - 1] * A + s[i]) % B;
            base[i] = (base[i - 1] * A) % B;
        }
    }
    ll getHashValue(int l, int r){
        if(l == 0) {
            return h[r];
        }
        ll ans = (h[r] - h[l - 1] * base[r - (l - 1)]) % B;
        if(ans < 0){
            return B + ans;
        }
        else{
            return ans;
        }
    }
    int distinctEchoSubstrings(string text) {
        
        hash(text);
        
        unordered_set<string>se;
        for(int i = 0; i < text.size(); i++) {
            for(int len = 1; i + len + len <= text.size(); len++){
                if(getHashValue(i, i + len - 1) == getHashValue(i + len, i + len + len -1)) {
                    se.insert(text.substr(i, len));
                }
            }
        }
        return se.size();
    }
};