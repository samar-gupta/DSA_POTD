//Company Tags    : Amazon, Google, Oracle, Zoho, Zycus
//Leetcode Link   : https://leetcode.com/problems/sort-characters-by-frequency/

//Approach-1 (Using Simple vector of pair and sorting it -  O(nlogn)
class Solution {
public:
    typedef pair<char, int> P;

    string frequencySort(string s) {
        vector<P> vec(123);

        for(char &ch : s) {
            int freq = vec[ch].second;
            vec[ch] = {ch, freq+1};
        }

        auto lambda = [&](P &p1, P &p2) {
            return p1.second > p2.second;
        };

        sort(begin(vec), end(vec), lambda);

        string result = "";

        for(int i = 0; i < 123; i++) {
            if(vec[i].second > 0) {
                char ch = vec[i].first;
                int freq = vec[i].second;
                string temp = string(freq, ch);

                result += temp;       //result += string(vec[i].second, vec[i].first);
            }
        }

        return result;
    }
};





//Approach-2 (Using Priority Queue) - O(nlong)
class Solution {
public:
    typedef pair<char, int> P;

    struct comp {
        bool operator()(P &p1, P &p2) {
            return p1.second < p2.second;         //max-heap      //heap - top me maximum frequency waali entry hogi
        }
    };

    string frequencySort(string s) {
        priority_queue<P, vector<P>, comp> pq;
        
        unordered_map<char, int> mp;

        for(char &ch : s) {                       //frequency updated in map
            mp[ch]++;
        }

        for(auto &it : mp) {                       //filling in heap from map
            pq.push({it.first, it.second});
        }

        string result = "";

        while(!pq.empty()) {
            P temp = pq.top();
            pq.pop();

            result += string(temp.second, temp.first);
        }

        return result;
    }
};
