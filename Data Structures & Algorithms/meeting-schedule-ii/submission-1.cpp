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
        /*
        Idea is to keep two
        start time pointer
        end time pointer
        */
        int n = intervals.size();

        vector<int> starttime;
        vector<int> endtime;

        int startidx = 0;
        int endidx = 0;

        for (auto &data : intervals)
        {
            starttime.push_back(data.start);
            endtime.push_back(data.end);
        }

        sort(starttime.begin(), starttime.end());
        sort(endtime.begin(), endtime.end());

        int mxmeetcount = 0;

        int currmeetcount = 0;

        while (startidx < n)
        {
            if (endtime[endidx] <= starttime[startidx])
            {
                currmeetcount--;
                endidx++;
            }
            else
            {
                currmeetcount++;
                startidx++;
            }

            mxmeetcount = max(mxmeetcount, currmeetcount);
        }

        return mxmeetcount;
    }
};