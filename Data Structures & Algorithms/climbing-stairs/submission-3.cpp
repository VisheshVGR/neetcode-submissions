class Solution
{
public:
    int climbStairs(int n)
    {
        // we only need last and 2nd last state
        int laststate = 1;
        int secondlaststate = 0;
        int currstate;

        for (int i = 1; i <= n; i++)
        {
            if (i == 1)
            {
                currstate = laststate;
            }
            else
            {
                currstate = laststate + secondlaststate;
            }

            secondlaststate = laststate;
            laststate = currstate;
        }

        return currstate;
    }
};