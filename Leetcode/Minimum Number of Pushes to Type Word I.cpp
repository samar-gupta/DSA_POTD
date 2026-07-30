//Leetcode Link : https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/

//Approach-1 (Using Map and doing as asked in Problem)
//T.C : O(n) + O(26log26)
//S.C : O(n)
class Solution {
public:
    int minimumPushes(string word) {
        if(word.length() <= 8) {
            return word.length();
        }
        
        int count = 0;
        unordered_map<int, int> mp; //You can use an array of size 10 also and use index 2 to 9
        
        int assign = 2;
        for(char &ch : word) {
            
            if(assign > 9) {
                assign = 2;
            }
            
            mp[assign]++;
            count += mp[assign];
            assign++;
        }
        
        return count;
        
    }
};

//Approach-2 (Simplifying Approach-1 above)
//T.C : O(n) + O(26log26)
//S.C : O(1)
class Solution {
public:
    int minimumPushes(string word) {
        
        //Generic solution
        vector<int> mp(26, 0);
        for(char &ch: word)
            mp[ch - 'a'] = 1; //Mentioned in qn, all letters will be distinct
    
        sort(begin(mp), end(mp), greater<int>()); //descending order of frequency
        
        int ans = 0;
        for(int i = 0; i < 26; i++){
            ans += mp[i]*((i/8) + 1);
        }
        return ans;
    }
};
