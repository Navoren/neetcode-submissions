/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();

        vector<int> start, end;

        for (auto &it : intervals) {
            start.push_back(it.start);
            end.push_back(it.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for (int i = 1; i < n; i++) {
            if (start[i] < end[i - 1]) {
                return false;
            }
        }

        return true;
    }
};