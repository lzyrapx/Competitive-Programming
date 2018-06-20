class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream s1(version1);
        stringstream s2(version2);
        string v1,v2;
        getline(s1,v1,'.');
        getline(s2,v2,'.');
        while(v1.size() != 0 || v2.size() != 0)
        {
            // cout << v1 << " " << v2 << endl;
            // 没有就用 0 补全
            if(v1.size() == 0) v1 = "0";
            if(v2.size() == 0) v2 = "0"; 
            if(stoi(v1) > stoi(v2)) return 1;
            else if(stoi(v1) < stoi(v2)) return -1;
            else {
                v1 = ""; v2 = "";
            }
            getline(s1,v1,'.');
            getline(s2,v2,'.');
        }
        return 0;
    }
};