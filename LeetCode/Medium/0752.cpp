class Solution {
public:
    string plusone(string str,int i)
    {
        if(str[i]=='9')
        {
            str[i]='0';
        }
        else{
            str[i]=str[i]+1;
        } 
        return str;
    }
    string downone(string str,int i)
    {
        if(str[i]=='0')
        {
            str[i]='9';
        }
        else{
            str[i]=str[i]-1;
        }
        return  str;
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>se(deadends.begin(), deadends.end());
        queue<string>que;
        que.push("0000");
        unordered_set<string>vis;
        vis.insert("0000");
        int step = 0;
        while(!que.empty()) {
            int sz = que.size();
            for(int i = 0; i < sz; i++) {
                string cur = que.front();
                que.pop();
                if(se.find(cur) != se.end()) {
                   continue;
                }
                if(cur == target){
                    return step;
                }
                for(int i = 0;i < 4;i++) {
                   string up = plusone(cur,i);
                   if(!vis.count(up))
                   {
                       que.push(up);
                       vis.insert(up);
                   }
                   string down = downone(cur,i);
                   if(!vis.count(down))
                   {
                       que.push(down);
                       vis.insert(down);
                   }
               }
            }
            step++;
        }
        return -1;
    }
};