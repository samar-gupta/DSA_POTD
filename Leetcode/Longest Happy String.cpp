//Leetcode Link : https://leetcode.com/problems/longest-happy-string

//Approach (simple thought process - heap)
//T.C : O(a+b+c)
//S.C : O(1)
class Solution {
public:
    typedef pair<int, char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P, vector<P>> pq; //max-heap

        if(a > 0) {
            pq.push({a, 'a'});
        }
        if(b > 0) {
            pq.push({b, 'b'});
        }
        if(c > 0) {
            pq.push({c, 'c'});
        }

        string result = "";

        while(!pq.empty()) {
            int currCount = pq.top().first;
            int currChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length()-1] == currChar && result[result.length()-2] == currChar) {
                //we can't use currChar. Check for next largest freqency char
                if(pq.empty()) {
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();

                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0) {
                    pq.push({nextCount, nextChar});
                }
            } else {
                currCount--;
                result.push_back(currChar);
            }

            if(currCount > 0) {
                pq.push({currCount, currChar});
            }
        }

        return result;
    }
};
