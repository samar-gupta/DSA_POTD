//Approach-1 :
class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        int i = 1;
        int count = 0;
        
        while (p >= (i*i)) {
            p = p - (i*i);
            count++;
            i++;
        }
        
        return count;
    }
};



//Approach-2 :
class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
        long long low = 0, high = 10000;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            long long sum = mid * (mid + 1) * (2 * mid + 1) / 6;

            if (sum <= p) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
