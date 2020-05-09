class Solution {
public:
    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};
    bool check(int x,int y, int k)
    {
        int sumx = 0;
        while(x > 0) {
            sumx += (x % 10);
            x /= 10;
        }
        int sumy = 0;
        while(y > 0) {
            sumy += (y % 10);
            y /= 10;
        }
        if(sumx + sumy > k) return false;
        return true;
    }
    int movingCount(int k, int rows, int cols)
    {
        if(k < 0) return 0;
        vector<vector<bool>> vis(rows+1,vector<bool>(cols+1,false));
        queue<pair<int,int>>que;
        que.push(make_pair(0,0));
        vis[0][0] = true;
        int ans = 0;
        while(!que.empty())
        {
           pair<int,int> a = que.front();
           que.pop();
           ans ++;
           for(int i = 0 ; i < 4; i++) {
               int x = a.first + dx[i];
               int y = a.second + dy[i];
               if(x >= 0 && x < rows && y >= 0 && y < cols && vis[x][y] == false)
               {
                   if(check(x,y,k)) {
                       vis[x][y] = true;
                       que.push(make_pair(x,y));
                   }
               }
           }
        }
        return ans;
    }
};