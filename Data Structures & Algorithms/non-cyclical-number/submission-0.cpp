class Solution {
   public:
    bool isHappy(int n) {
        unordered_map<int, bool> mp;

        mp[n] = true;

        while (n != 1) {
            n = op (n);

            if (mp[n] == true)
                return false;

            mp[n] = true;
        }

        return true;
    }

   private:
    int op(int n) {
        int ans = 0;

        while (n) {
            ans = ans + pow(n % 10, 2);
            n /= 10;
        }

        return ans;
    }
};
