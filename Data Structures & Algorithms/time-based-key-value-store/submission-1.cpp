class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyStore;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        keyStore[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (keyStore.find(key) == keyStore.end()) return "";

        auto &vec = keyStore[key];

        int low = 0, high = vec.size() - 1;
        string result = "";

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (vec[mid].first <= timestamp) {
                result = vec[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};