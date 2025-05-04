//Leetcode Link : https://leetcode.com/problems/number-of-equivalent-domino-pairs

//way 1 : brute force: O(n*n) 
//way 2 : convert pair to string like a_b and update frequency in map
//way 3 : using map of pair  //S.C : O(n)
//way 4 : using vector(100) //according to constraints max is 99 //update freq. in vec(100)-mp then traverse mp to find pairs by nC2 , selecting 2 pairs from n //S.C : O(100) ~ O(1)  //T.C : O(n) + O(100)
//way 5(optimised way 4): using vector(100) //reducing extra O(100) in T.C, by doing during O(n) //Approach-2

//Approach-1 (Using map of pair)
//T.C : O(n * logn) , note that we are using ordered_map here and insertion in it is log(n)
//S.C : O(n)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> mp;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) { //(2, 1) ---- (1, 2)
                swap(d[0], d[1]);
            }

            mp[{d[0], d[1]}]++;
        }

        int result = 0;

        for(auto &it : mp) {
            int freq = it.second;

            result += freq * (freq-1)/2; //freqC2
        }

        return result;

    }
};


//Approach-2 (constant space)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> vec(100);

        int result = 0;

        for(auto &d : dominoes) {
            if(d[0] > d[1]) {
                swap(d[0], d[1]);
            }

            int num = d[0]*10 + d[1]; //(a, b) --> a*10 + b;

            result += vec[num];

            vec[num]++;
        }

        return result;
    }
};
