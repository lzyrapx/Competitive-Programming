class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia;
        int rb, ib;
        char ch;
        stringstream aa(a), bb(b);
        aa >> ra >> ch >> ia >> ch;
        bb >> rb >> ch >> ib >> ch;
        int shi = ra * rb - ia * ib;
        int xu = ra * ib + rb * ia;
        string ans = to_string(shi) + "+" + to_string(xu) + "i";
        return ans;
    }
};