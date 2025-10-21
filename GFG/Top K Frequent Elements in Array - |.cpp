//Approach-1 : (Using unordered_map + Hashmap)
class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        // Code here
        unordered_map <int,int> m;
        for(auto i:arr) m[i]++;
        
        priority_queue <pair<int,int>> p;
        for(auto i:m) p.push({i.second,i.first});

        vector <int> ans;
        for(int i = 0;i < k;i++){
            ans.push_back(p.top().second);
            p.pop();
        }
        
        return ans;
    }
};


//Approach-2 : (Using sorting)
class Solution {
  public:
    static bool comp(const pair<int, int> &a, const pair<int, int> &b) {

        if(a.second > b.second) {

            return true;
        }
        
        if(a.second == b.second) {
            return a.first > b.first;
        }
        return false;
    }
    
    vector<int> topKFreq(vector<int> &nums, int k) {
        // Code here
        unordered_map<int, int> mp;

        for(auto i : nums) {

            mp[i]++;
        }
        
        vector<pair<int, int>> freq;
        for(auto it : mp) {
            freq.push_back({it.first, it.second});
        }
        
        sort(freq.begin(), freq.end(), comp);
        
        vector<int> ans;
        for(int i=0; i<k; i++) {
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};
