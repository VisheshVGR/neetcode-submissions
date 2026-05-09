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

class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        // Return room with earliest meeting end time
        multiset<int> s;

        sort(intervals.begin(), intervals.end(), [](auto a, auto b)
             {
            if (a.start == b.start)
                return a.end <= b.end;

            return a.start < b.start; });

        for (auto &interval : intervals)
        {
            if (s.empty())
            {
                // add new room
                s.insert(interval.end);
            }
            else
            {
                int meeting_finishing_earliest = *s.begin();

                if (interval.start < meeting_finishing_earliest)
                {
                    // We need more room

                    // add new room
                    s.insert(interval.end);
                }
                else
                {
                    // Remove meeting room with meeting_finishing_earliest
                    s.erase(s.begin());

                    s.insert(interval.end);
                }
            }
        }

        return s.size();
    }
};
