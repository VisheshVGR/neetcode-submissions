class Solution
{
public:
    int trap(vector<int> &height)
    {
        /*
        For each idx we get left max and right max
        water this bar can store is min (leftmax, rightmax);

        we will use running mx for this
        */

        int n = height.size();

        int leftmax = 0;
        int rightmax = 0;

        vector<int> leftmaxheight(n);
        vector<int> rightmaxheight(n);

        for (int i = 0; i < n; i++)
        {
            leftmaxheight[i] = leftmax;
            leftmax = max(leftmax, height[i]);

            rightmaxheight[n - 1 - i] = rightmax;
            rightmax = max(rightmax, height[n - 1 - i]);
        }

        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            answer += max(0, min(leftmaxheight[i], rightmaxheight[i]) - height[i]);
        }

        return answer;
    }
};
