/*
    Company Tags                : META
    Leetcode Link               : https://leetcode.com/problems/number-of-flowers-in-full-bloom/
*/

/******************************************* C++ *******************************************/
//Approach-2 (Using Binary Search)
//T.C : O((m+n) * log(n))
//S.C : O(m)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();

        vector<int> start_time(m);
        vector<int> end_time(m);

        for(int i = 0; i < m; i++) {
            start_time[i] = flowers[i][0];
            end_time[i] = flowers[i][1];
        }

        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));

        vector<int> result(n);

        for(int i = 0; i < n; i++) {

            int time = people[i];

            int bloomed_flowers_already = upper_bound(begin(start_time), end(start_time), time) - begin(start_time);

            int died_already = lower_bound(begin(end_time), end(end_time), time) - begin(end_time);

            result[i] = bloomed_flowers_already - died_already;
        }

        return result;
    }
};



//Approach-1 (Brute Force) - TLE
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int m = flowers.size();
        int n = people.size();
        
        vector<int> result(n);
        
        for(int i = 0; i<n; i++) {
            
            for(int j = 0; j<m; j++) {
                int start = flowers[j][0];
                int end   = flowers[j][1];
                
                if(people[i] >= start && people[i] <= end) {
                    result[i]++;
                }
                
            }
        
        }
        
        return result;
    }
};
