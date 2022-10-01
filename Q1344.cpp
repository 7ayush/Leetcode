class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourPos=hour*5.0+(minutes/60.0)*5.0;
        double dist=abs(hourPos-minutes);
        double angle=dist*6.0;
        return min(angle,360-angle);        
    }
};
