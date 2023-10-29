/*
    Company Tags                : Was asked in Aptitude 
    Leetcode Link               : https://leetcode.com/problems/poor-pigs/
*/


/************************************************ C++ *********************************************************/
/Approach-1
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie + 1;      //one pig can handle one extra case, as if all are good then last one is the poisonous

        int pigs = 0;

        while(pow(T, pigs) < buckets) {             //(T+1)^pigs = buckets
            pigs++;
        }

        return pigs;
    }
};



/Approach-2 (Using simple one liner)
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        //(T+1)^pigs = buckets
        //pigs = log(buckets)/log(T+1)

        return ceil(log2(buckets)/log2(minutesToTest/minutesToDie + 1));

    }
};
