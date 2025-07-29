class RandomizedSet {
    vector<int> random;
    unordered_set<int> values;

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (values.find(val) != values.end())
            return false;
        random.push_back(val);
        values.insert(val);
        return true;
    }

    bool remove(int val) {
        if (values.find(val) != values.end()) {
            random.erase(std::remove(random.begin(), random.end(), val),
                         random.end());
            values.erase(val);
            return true;
        }
        return false;
    }

    int getRandom() { return random[rand() % random.size()]; }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */