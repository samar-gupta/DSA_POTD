//Company Tags   : Amazon
//Leetcode Link  : https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals

//Approach-1 (Using Map and Sorting)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freq;
        
        for(auto &it : mp) {
            freq.push_back(it.second);
        }
        
        sort(begin(freq), end(freq));

        for(int i = 0; i < freq.size(); i++) {
            
            k -= freq[i];
            
            if(k < 0) {
                return freq.size() - i;
            }
        }
        
        return 0; //All were removed
    }
};


//Approach-2 (Using min-heap)
//T.C : O(nlogn)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> mp;
        
        for(int &x : arr) {
            mp[x]++;
        }

        priority_queue<int, vector<int>, greater<int>> pq; //min-heap
        for(auto &it : mp) {
            pq.push(it.second);
        }

        
        while(!pq.empty()) {
            
            k -= pq.top();
            
            
            if(k < 0) {
                return pq.size();
            }
            
            pq.pop();
        }
        
        return 0; //All were removed
    }
};


//Approach-3 (Using Counting Sort)
//T.C : O(n)
//S.C : O(n)
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;

        for(int &x : arr) {
            mp[x]++;
        }

        vector<int> freqCount(n+1);
        //freqCount[i] = number of elements (types) having frequency = i

        int uniqueTypes = mp.size();

        for(auto &it : mp) {
            int freq = it.second;
            freqCount[freq]++;
        }


        for(int freq = 1; freq <= n; freq++) {

            int typesICanDelete = min(k/freq, freqCount[freq]);

            k -= (typesICanDelete * freq);

            uniqueTypes -= typesICanDelete;

            if(k <= freq) {
                return uniqueTypes;
            }
        }

        return 0;
    }
};
