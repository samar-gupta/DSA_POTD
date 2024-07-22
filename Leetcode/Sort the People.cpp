//Leetcode Link : https://leetcode.com/problems/sort-the-people/

//Approach-1 (Using Custom Sort on a vector<pair<string, int>>)
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        
        vector<pair<string, int>> vec(n);
        for(int i = 0; i<n; i++) {
            vec[i] = make_pair(names[i], heights[i]);
        }
        
        auto lambda = [](auto &p1, auto &p2) {
            return p1.second > p2.second;
        };
        
        sort(begin(vec), end(vec), lambda);
    
        for(int i=0; i<n; i++) {
            names[i] = vec[i].first;
        }
        
        return names;
    }
};



//Approach-2 (Using normal sort on vector<pair<int,string >> )
class Solution {
  public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
      int n = names.size();

      vector<pair<int, string>> vec(n);
      for(int i = 0; i < n; i++) {
        vec[i] = make_pair(heights[i], names[i]);
      }

      sort(rbegin(vec), rend(vec));

      for(int i = 0; i < n; i++) {
        names[i] = vec[i].second;
      }

      return names;
    }
};



//Approach-3 (Using unordered_map + sorting)
class Solution {
  public:
    vector <string> sortPeople(vector <string>& names, vector<int>& heights) {
      int n = names.size();

      unordered_map<int, string> mp; //all values of heights are distinct

      for(int i = 0; i < n; i++) {
        mp[heights[i]] = names[i];
      }

      sort(rbegin(heights), rend(heights));

      for(int i = 0; i < n; i++) {
        names[i] = mp[heights[i]];
      }

      return names;
    }
};



//Approach-4 (Using ordered_map)
class Solution {
  public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
      int n = names.size();

      map<int, string> mp; //all values of heights are distinct

      for(int i = 0; i < n; i++) {
        mp[heights[i]] = names[i]; //will be sorted 
      }

        int i = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
          names[i] = it->second;
          i++;
        }

        return names;
      }
    };
