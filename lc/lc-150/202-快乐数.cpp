class Solution {

    unordered_set<int> s;

  public:
    bool isHappy(int n) {
        if (n == 1)
            return true;
        if (s.find(n) != s.end())
            return false;
        s.insert(n);

        int tot = 0;
        while (n) {
            int t = n % 10;
            tot += t * t;
            n /= 10;
        }
        return isHappy(tot);
    }
};
