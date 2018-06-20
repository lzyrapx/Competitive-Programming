class Solution {
public:
    // ind the minimum minutes difference between any two time points in the list.
    int findMinDifference(vector<string>& timePoints) {
        vector<int>ve(timePoints.size(), 0);
        for(int i = 0; i < timePoints.size(); i++) {
            int hours = stoi(timePoints[i].substr(0,2)) * 60;
            int minute = stoi(timePoints[i].substr(3,2));
            ve[i] = hours + minute;
            cout <<ve[i] <<endl;
        }
        sort(ve.begin(),ve.end());
        ve.push_back(ve[0] + 24 * 60); //注意最后一个
        int minn = 24 * 60;
        for(int i = 0; i < timePoints.size(); i++) {
            minn = min(minn, ve[i + 1] - ve[i]);
        }
        return minn;
    }
};