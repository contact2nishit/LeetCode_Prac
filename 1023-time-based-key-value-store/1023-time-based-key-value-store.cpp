class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> Map;
public:
    TimeMap() {
        this->Map = unordered_map<string, vector<pair<int, string>>>();
    }
    
    void set(string key, string value, int timestamp) {
        this->Map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!Map.count(key) || Map[key].empty() || Map[key][0].first > timestamp) return "";
        int l = 0;
        int r = Map[key].size() - 1;
        while (l <= r) {
            int mid = (l+r)/2;
            if (Map[key][mid].first == timestamp) return Map[key][mid].second;
            else if (Map[key][mid].first > timestamp) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        //if (Map[key][Map[key].size() - 1].first < timestamp) return Map[key][Map[key].size() - 1].second;
        return Map[key][r].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */