class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>> files;
        vector<vector<string>> ans;
        if(paths.size() == 0) return ans;
        
        for(auto path: paths) 
        {
            stringstream ss(path);
            string root, s;
            getline(ss,root,' ');
            while(getline(ss,s,' ')) 
            {
                string filename = root + '/' + s.substr(0,s.find('('));
                string filecontent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                files[filecontent].push_back(filename);
            }
        }
        for(auto file : files) 
        {
            if(file.second.size() >= 2) {
                ans.push_back(file.second);
            }
        }
        return ans;
    }
};