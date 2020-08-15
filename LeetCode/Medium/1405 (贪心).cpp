class Solution {
public:
    // 0 <= a, b, c <= 100
    // 最多a个'a'，b个'b'，c个'c'，不能出现'aaa','bbb','ccc',输出任意这样的字符串
    struct cmp{
        bool operator()(pair<char,int> a,pair<char,int> b){
            return a.second<b.second;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        string ans;
        pair<char,int>last = make_pair('#',-1);
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        pq.push(make_pair('a',a));
        pq.push(make_pair('b',b));
        pq.push(make_pair('c',c));
        while(true){
            pair<char,int>cur = pq.top();
            pq.pop();
            // 第一次添加或者上次添加字符和这次不同
            if(last.first == '#' || last != cur) {
                if(cur.second == 0) {
                    break;
                }
                ans = ans + cur.first;
                cur.second--;
                if(cur.second > 0) {
                    ans = ans + cur.first;
                    cur.second--;
                }
                last = cur;
                pq.push(cur);
            }
            // 上次添加字符和这次相同
            else {
                pair<char,int>now = pq.top();
                pq.pop();
                if(now.second > 0) {
                    ans = ans + now.first;
                    now.second--;
                    last = now;
                    pq.push(now);
                    pq.push(cur);
                }
            }
        }
        return ans;
    }
};