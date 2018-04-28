class Solution {
public:
    vector<string> Permutation(string str) {
        if(str.size() == 0)return vector<string>();      
        vector<string> ans;
        sort(str.begin(),str.end());
        do{
            ans.push_back(str);
        }
        while(next_permutation(str.begin(),str.end()));
        return ans;
    }
};

--------------------------------------------------------------
class Solution {
public:
    void dfs(vector<string> &ans, int k, string str) //遍历第k位的所有可能
    {
        if(k == str.size() - 1) ans.push_back(str);
        set<char> se;  //记录出现过的字符
        sort(str.begin() + k, str.end());  //保证按字典序输出
        for(int i = k; i < str.size(); i++)
        {
            if(se.find(str[i]) == se.end()) //只和没交换过的换
            {  
                se.insert(str[i]);
                swap(str[i], str[k]);
                dfs(ans, k + 1, str);
                swap(str[i], str[k]);  //复位
            }
        }
    } 
    vector<string> Permutation(string str) 
    {
        vector<string> ans;
        dfs(ans, 0, str);
        return ans;
    }
};