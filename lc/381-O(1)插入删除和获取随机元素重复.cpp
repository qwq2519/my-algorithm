class RandomizedCollection {
    unordered_map<int, unordered_set<int>> m;
    vector<int> v;

  public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool notExist = m.find(val) == m.end() || m[val].empty();
        m[val].insert(v.size());
        v.push_back(val);
        return notExist;
    }

    bool remove(int val) {
        if (m.find(val) == m.end() || m[val].empty()) {
            return false;
        }
        int firstIdx = *m[val].begin();
        int lastIdx = v.size() - 1;
        int lastVal = v[lastIdx];
        m[val].erase(firstIdx);
        v[firstIdx] = lastVal;

        m[lastVal].insert(firstIdx);
        m[lastVal].erase(lastIdx);
        v.pop_back();
        if (m[val].empty()) {
            m.erase(val);
        }
        return true;
    }

    int getRandom() { return v[rand() % v.size()]; }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
