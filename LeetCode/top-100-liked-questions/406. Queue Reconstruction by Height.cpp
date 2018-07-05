class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        return (a.first > b.first) || (a.first == b.first && a.second < b.second);
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector< pair<int,int>> ans;
        sort(people.begin(), people.end(),cmp);
        for(int i = 0; i < people.size(); i++){
            // cout << people[i].second << endl;
            // 按照k值的位置一直插入到答案中
            ans.insert(ans.begin() + people[i].second, people[i]);
        }    
        return ans;
    }
};