/*
 * @Author: zhaoyang.liang
 * @Github: https://github.com/LzyRapx
 * @Date: 2019-11-09 15:35:05
 */
class Solution {
public:
    // the years 1971 and 2100
    // Kim larsson calculation formula
    // https://en.wikipedia.org/wiki/Doomsday_rule
    int dayofWeek(int day, int month, int year) {
        int y = year;
        if (month < 3) {
            month += 12;
            y--;
         }
        return (day + ((month + 1) * 26) / 10 + y + y / 4 + 6 * (y / 100) + y / 400 + 5) % 7 + 1;
    }
    string dayOfTheWeek(int day, int month, int year) {
        int d = dayofWeek(day, month, year);
        vector<string> ve{"Sunday", "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        return ve[d % 7];
    }
};