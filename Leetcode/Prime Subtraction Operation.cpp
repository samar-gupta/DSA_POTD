//Leetcode Link : https://leetcode.com/problems/prime-subtraction-operation

//Approach (Store prime and check)
//T.C : O(n * maxNum)
//S.C : O(1000) ~ O(1)
class Solution {
public:
    bool isPrime[1000];

    void sieve() { //O(1)
        fill(isPrime, isPrime+1000, true); //initiliase the array ith all True
        isPrime[0] = false; //0 is not a prime number
        isPrime[1] = false; //1 is not a prime number
        
        for(int i = 2; i * i < 1000; i++) {
            if(isPrime[i] == true) {
                for(int j = i*i; j < 1000; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();

        sieve(); //it will populate my isPrime array //O(1)
        //isPrime[i] == true means, i is a prime number else i is no a prime number


        //O(n * maxNum)
        for(int i = n-2; i >= 0; i--) { //O(n)
            if(nums[i] < nums[i+1]) {
                continue;
            }

            //nums[i] >= nums[i+1]
            //decrease nums[i] atleast less than nums[i+1]

            //check prime numbers less than nums[i]
            for(int p = 2; p < nums[i]; p++) { //O(max of nums)
                if(!isPrime[p]) {
                    continue;
                }

                if(nums[i] - p < nums[i+1]) {
                    nums[i] -= p;
                    break;
                }
            }

            if(nums[i] >= nums[i+1]) {
                return false;
            }
        }

        return true;
    }
};
