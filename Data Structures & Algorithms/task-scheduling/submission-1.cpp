class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        /*
        So the idea is
        We will have a queue of n size
        and it will start with n DUMMY nodes

        for each task we will keep frequency
        we pick most frequent elem (priority queue)
        and execute it, if task is still pending we push it to pending queue
        */

        // Base case
        if (n == 0)
        {
            // we can execute every task without any wait
            return tasks.size();
        }

        vector<int> freq(26, 0);

        int work_count = 0;

        for (auto &t : tasks)
        {
            freq[t - 'A']++;

            work_count++;
        }

        // Priority queue and Wait Queue

        // task freq, task id
        priority_queue<pair<int, int>> pq;

        // task freq, task id ("-1" is DUMMY)
        queue<pair<int, int>> q;

        // Init
        for (int id = 0; id < 26; id++)
        {
            if (freq[id] > 0)
            {
                pq.push({freq[id], id});
            }
        }

        // We will start with n DUMMY ID's
        for (int i = 0; i <= n; i++)
        {
            q.push({0, -1});
        }

        // We keep processing until we complete all work_count

        int time = 0;

        while (work_count > 0)
        {
            time++;

            // push elem from q to work_queue
            int wait_elem_freq = q.front().first;
            int wait_elem_id = q.front().second;

            q.pop();

            if (wait_elem_id != -1)
            {
                // Not dummy node
                // This elem is avl for work
                pq.push({wait_elem_freq, wait_elem_id});
            }

            // Process top elem
            if (pq.size() > 0)
            {
                int work_elem_freq = pq.top().first;
                int work_elem_id = pq.top().second;

                pq.pop ();

                // Work is done
                work_count--;

                // If more freq is there, we push to wait queue
                // Else we push dummy node
                if (work_elem_freq > 1)
                {
                    q.push({work_elem_freq - 1, work_elem_id});
                }
                else
                {
                    // Push dummy node
                    q.push({0, -1});
                }
            }
            else
            {
                // All our work is in wait_queue

                // Push dummy node
                q.push({0, -1});
            }
        }

        return time;
    }
};