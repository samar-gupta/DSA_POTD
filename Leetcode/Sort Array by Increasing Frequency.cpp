//Leetcode Link : https://leetcode.com/problems/sort-array-by-increasing-frequency/

//Approach-1 (Using unordered_map)
class Solution {
public:
  vector<int>frequencySort (vector<int>&nums) {
	unordered_map < int, int >mp;
	for(int &num : nums) {
		mp[num]++;
	  }

	auto lambda = [&](int &num1, int &num2) {
	  if(mp[num1] == mp[num2]) {
		 return num1 > num2;
      }

       return mp[num1] < mp[num2];
     }; 
      
     sort (begin (nums), end (nums), lambda); 
      
     return nums;
  }
};



//Approach-2 (Without using unordered_map)
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int mp[201] = {0};

        for (int &num : nums) {
            mp[num + 100]++; //+100 is done because -100 <= nums[i] <= 100
        }

        //vector of pairs (value, frequency)
        vector<pair<int, int>> freqVec;
        for (int i = 0; i < 201; ++i) {
            if (mp[i] > 0) {
                freqVec.push_back({i - 100, mp[i]}); //i-100 is done to get the original number
            }
        }

        auto lambda = [](pair<int, int>& p1, pair<int, int>& p2) {
            if (p1.second == p2.second) {
                return p1.first > p2.first;
            }
            return p1.second < p2.second;
        };


        sort(freqVec.begin(), freqVec.end(), lambda); 

        vector<int> result;
        for (const auto& p : freqVec) {
            result.insert(result.end(), p.second, p.first);
        }

        return result;
    }
};
