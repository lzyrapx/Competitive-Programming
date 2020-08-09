class Solution {
public:
    // 先给你一些表达式和这些表达式的答案，再给你一些新的表达式，问你这些新表达式的答案
    // 把除法运算转化成图表示,比如:a->b = 2.0 b->c = 3.0
    // a,b,c 看成节点,它的值为权值.那么 a/c = ? 相当于,a->c <==> a->b->c = 2.0*3.0 = 6
    
    const int inf = INT_MAX;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int>mp;
        int num = 1;
        vector<vector<double>>graph(100, vector<double>(100, inf));
        for(int i = 0; i < equations.size(); i++) {
            if(mp.find(equations[i][0]) == mp.end()) {
                mp[equations[i][0]] = num++;
            }
            if(mp.find(equations[i][1]) == mp.end()) {
                mp[equations[i][1]] = num++;
            }
            graph[mp[equations[i][0]]][mp[equations[i][1]]] = values[i];
            graph[mp[equations[i][1]]][mp[equations[i][0]]] = 1 / values[i];
        }
        for(int i = 1; i < num; i++) {
            for(int j = 1; j < num; j++) {
                for(int k = 1; k < num; k++) {
                    if(graph[i][k] != inf && graph[k][j] != inf && graph[i][j] == inf) {
                        graph[i][j] = graph[i][k] * graph[k][j];
                    }
                }
            }
        }
        vector<double> ans;
        for(int i = 0; i < queries.size(); i++) {
            if(mp.find(queries[i][0]) != mp.end() && mp.find(queries[i][1]) != mp.end()) {
                int a = mp[queries[i][0]];
                int b = mp[queries[i][1]];
                if(graph[a][b] != inf) {
                    ans.push_back(graph[a][b]);
                }
                else {
                    ans.push_back(-1);
                }
            }
            else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};