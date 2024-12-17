//Leetcode Link : https://leetcode.com/problems/construct-string-with-repeat-limit

//Approach-1 (Using pointers and frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0); //S.C : O(26)
        for(char &ch : s) { //T.C : O(n)
            count[ch-'a']++;
        }

        string result;

        int i = 25; //start form last letter so that we can find the largest character first
        while(i >= 0) { //O(26)
            if(count[i] == 0) {
                i--;
                continue;
            }

            char ch  = 'a' + i; //you will get the character
            int freq = min(count[i], repeatLimit);

            result.append(freq, ch);
            count[i] -= freq;

            if(count[i] > 0) {
                //find next largest character
                int j = i-1;
                while(j >= 0 && count[j] == 0) { //O(26)
                    j--;
                }

                if(j < 0) {
                    break;
                }

                result.push_back('a' + j);
                count[j]--;
            }
        }

        return result;
    }
};


//Approach-2 (Using max-heap + frequency table)
//T.C : O(n)
//S.C : O(26)
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> count(26, 0);
        for(char &ch : s) {
            count[ch-'a']++;
        }

        priority_queue<char> pq;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                char ch = 'a' + i;
                pq.push(ch);
            }
        }

        string result;
        while(!pq.empty()) {
            char ch = pq.top();
            pq.pop();

            int freq = min(count[ch-'a'], repeatLimit);
            result.append(freq, ch);

            count[ch-'a'] -= freq;

            if(count[ch-'a'] > 0 && !pq.empty()) {
                char nextChar = pq.top();
                pq.pop();

                result.push_back(nextChar);
                count[nextChar-'a']--;

                if(count[nextChar-'a'] > 0) {
                    pq.push(nextChar);
                }

                pq.push(ch);

            }
        }

        return result;
    }
};
