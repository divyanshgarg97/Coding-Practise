/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

struct mycomp{
    bool operator()(Interval p1, Interval p2){
        if( p1.end < p2.end)
            return true;
        return false;
    }
};
class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals) {
        // Write your code here
        int n = intervals.size() ; 
        if( n == 0) return true; 
        sort(intervals.begin(),intervals.end(),mycomp());
        bool ans = true; 
        for(int i = 1 ; i < n;i++ ) {
            if(intervals[i-1].end <= intervals[i].start)
                continue;
            else{
                ans = false;
                return ans;
            }
        }
        return ans;
    }
};