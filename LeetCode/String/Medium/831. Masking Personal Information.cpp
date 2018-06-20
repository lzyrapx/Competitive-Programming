class Solution {
public:
    string maskPII(string S) {
        if(S.size() == 0) return "";
        string ans;
        // Email address
        if(S.find("@") != string::npos) 
        {
            for(int i = 0; i < S.size(); i++) {
                if(isupper(S[i]) && S[i] <= 'Z' && S[i] >= 'A') S[i] = tolower(S[i]);
                if(i == 0) {
                    ans = S.substr(i,1) + "*****";
                }
                if(i == S.find("@") - 1) {
                    ans += S.substr(i,1);
                }
                if(i > 0 && i < S.find("@")-1) continue;
                if(i >= S.find("@")) ans += S.substr(i,1);
                
            }
        }
        else // Phone number
        {
            string nums;
            for(int i = 0;i < S.size(); i++) {
                if(isdigit(S[i])) nums += S[i];
            }
            int sz = nums.size();
            cout << sz << endl;
            if(sz == 13) { 
                ans += "+***-";
            }
            else if(sz == 12){
                ans += "+**-";
            }
            else if(sz == 11) {
                ans += "+*-";
            }
            ans += "***-***-";
            ans += nums.substr(sz-4,4);
        }
        return ans;
    }
};