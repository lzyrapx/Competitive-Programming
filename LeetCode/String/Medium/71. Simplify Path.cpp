class Solution {
public:
    string simplifyPath(string path) {
        if(path.size() == 1) return path;
        stack<string>sta;
        string s;
        stringstream ss(path);
        while(getline(ss,s,'/')) { // 以"/"为读分界读字符串流，不包含"/"
            cout << s << endl;
            if(s == "" || s == ".")continue;
            if(s == ".." && !sta.empty()) sta.pop();
            else if(s != "..") sta.push(s);
        }
        string ans = "";
        while(!sta.empty()) {
            ans = "/" + sta.top() + ans;
            sta.pop();
        }
        if(ans.size() == 0) return "/";
        // cout << ans << endl;
        else return ans;
    }
};