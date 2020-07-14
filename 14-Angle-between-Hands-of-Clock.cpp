//Hour hand = 1min - 0.5 deg
//minute hand = 1min - 6 deg


class Solution {
public:
    double angleClock(int hour, int m) {
        int h = hour%12;
        double h_angle = h*30 + m*0.5;
        double m_angle = m*6;
        double ans1 = abs(h_angle - m_angle);
        double ans2 = 360-ans1;
        return min(ans1,ans2);
        
    }
};