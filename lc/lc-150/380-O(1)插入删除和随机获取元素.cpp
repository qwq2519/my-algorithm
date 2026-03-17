class RandomizedSet {
    unordered_map<int, int> s; // val : pos
    vector<int> a;

  public:
    RandomizedSet() { srand(time(0)); }

    bool insert(int val) {
        if (s.find(val) != s.end()) {
            return false;
        }
        s[val] = a.size();
        a.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (s.find(val) == s.end()) {
            return false;
        }
        int last = a.back();
        int t = s[val];
        a[t] = last;
        s[last] = t;
        a.pop_back();
        s.erase(val);
        return true;
    }

    int getRandom() { return a[rand() % (a.size())]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
