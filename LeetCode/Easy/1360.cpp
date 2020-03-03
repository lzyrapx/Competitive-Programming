/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2020-03-03 20:50:38
 */
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        vector<int>m{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto isLeap = [&](int year) {
            return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        };
        auto daysFrom1970 = [&](const string& date) {
            int year = stoi(date.substr(0, 4));
            int month = stoi(date.substr(5, 2));
            int days = stoi(date.substr(8, 2));      
            for (int i = 1970; i < year; ++i) {
                days += 365 + isLeap(i);
            }
            for (int i = 1; i < month; ++i) {
                days += m[i - 1];
            }
            days += month > 2 && isLeap(year);
            return days;
        };
        return abs(daysFrom1970(date1) - daysFrom1970(date2));
    }
};