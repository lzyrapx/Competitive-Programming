class Solution {
public:
    double angleClock(int hour, int minutes) {
        double one_minute_angle = 6;
        double one_hour_angle = 30;
        double minutes_angle = one_minute_angle * minutes;
        double hour_angle = (hour % 12) * one_hour_angle + (1.0 * minutes / 60) * one_hour_angle; // 注意，时针有个偏移量
        double diff = abs(hour_angle - minutes_angle);
        return min(diff, 360 - diff);
    }
};