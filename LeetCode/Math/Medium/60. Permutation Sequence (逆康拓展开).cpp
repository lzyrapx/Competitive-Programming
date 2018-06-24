class Solution {
public:
    typedef long long ll;
    string getPermutation(int n, int k) {
        return Cantor_inverse_expansion(k,n);
    }
    ll fact[120];
    void init()
    {
        fact[0] = 1;
        for(int i = 1; i <= 12; i++)  {
            fact[i] = i * fact[i-1];
        }
    }
    string Cantor_inverse_expansion(ll n, int m)
    {//n是在全排列中的名次，注意是从0开始计数的，若从1开始计数则要减去1。m是元素个数
        init();
        n--;
        vector<int> num;
        string ans;
        int k = 0;
        for(int i = 1; i <= m; i++) num.push_back(i);
        for(int i = m; i >= 1; i--)
        {
            ll r = n % fact[i-1];
            ll t = n / fact[i-1];
            n = r;
            sort(num.begin(), num.end());
            ans += (num[t] + '0');
            num.erase(num.begin() + t);
        }
        // cout << "ans = " << ans << endl;
        return ans;
    }   
};