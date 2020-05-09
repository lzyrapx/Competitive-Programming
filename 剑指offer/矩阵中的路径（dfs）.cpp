class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    bool dfs(char* matrix, int rows, int cols, char* str, int x, int y, vector<vector<bool>>&vis)
    {
        if(strlen(str) == 0) return true;
        for(int i = 0; i < 4; i++) {
            int now_x = x + dx[i];
            int now_y = y + dy[i];
            if(now_x < rows && now_x >=0 && now_y < cols && now_y >= 0 && vis[now_x][now_y] == false)
            {
                if(matrix[now_x * cols + now_y] == str[0]){
                    vis[now_x][now_y] = true;
                    if(dfs(matrix,rows,cols,str + 1,now_x,now_y,vis)) {
                        return true;
                    }
                    vis[now_x][now_y] = false;
                }
            }
        }
        return false;
    }
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
         vector<vector<bool>> vis(rows+1,vector<bool>(cols+1,false));
         for(int i = 0; i < rows; i++) {
             for(int j = 0; j < cols; j++) {
                 if(matrix[i * cols + j] == str[0]) {
                     vis[i][j] = true;
                     if(dfs(matrix,rows,cols,str+1,i,j,vis))
                     {
                         return true;
                     }
                     vis[i][j] = false;
                 }
             }
         }
         return false;
                                 
    }


};