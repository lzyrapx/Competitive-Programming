class Solution {
public:
    // 判断两个长方形是否相交
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int nx = max(rec1[0],rec2[0]);
        int ny = max(rec1[1],rec2[1]);
        int mx = min(rec1[2],rec2[2]);
        int my = min(rec1[3],rec2[3]);
        if(mx > nx && my > ny) return true; // 相交
        else return false;
    }
};