class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {

        int canattendfrom = 0;

        sort(intervals.begin(), intervals.end(), [](auto a, auto b)
             {
            if (a.start == b.start)
                return a.end <= b.end;
            return a.start < b.start; });

        for (auto &interval : intervals)
        {
            if (interval.start < canattendfrom)
                return false;

            canattendfrom = interval.end;
        }

        return true;
    }
};