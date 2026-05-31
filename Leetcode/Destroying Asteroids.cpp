//Leetcode Link : https://leetcode.com/problems/destroying-asteroids

//Approach-1 (Simple sorting and greedy)
//T.C : O(n log n)
//S.C : O(1)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));

        long long totalMass = mass;

        for(int &asteroid : asteroids) {
            if(totalMass < asteroid)
                return false;

            totalMass += asteroid;
        }

        return true;
    }
};


//Approach-2 (Early return)
//T.C : O(n log n)
//S.C : O(1)
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(begin(asteroids), end(asteroids));

        for(int &asteroid : asteroids) {
            if(mass < asteroid)
                return false;
            else if(mass >= 1e5)
                return true;

            mass += asteroid;
        }

        return true;
    }
};
