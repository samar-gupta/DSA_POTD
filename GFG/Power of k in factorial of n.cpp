//Intuition : I thought about this problem by first understanding what it's asking. When we have n!, we need to find how many times k divides into it completely. For example, if n=7 and k=2, I need to find the highest power of 2 that divides 7! = 5040.
             //  My initial thought was to use Legendre's formula, but that only works for prime numbers. Since k can be any number, I realized I need to break down k into its prime factors first. If k = p₁^a₁ × p₂^a₂ × ... × pₘ^aₘ, then the power of k in n! is limited by whichever prime factor "runs out" first.
//Approach : Here's how I solved this step by step:
             // 1. Handle edge cases: If k = 1, the answer is infinity (but we return a large number). If k > n!, the answer is 0.
             // 2. Find prime factorization of k: I break down k into its prime factors and their powers.
             // 3. Apply Legendre's formula: For each prime factor p with power a in k, I find how many times p appears in n! using the formula: floor(n/p) + floor(n/p²) + floor(n/p³) + ...
             // 4. Find the limiting factor: For each prime factor p with power a, I calculate how many complete "sets" of k I can form, which is floor(count_of_p_in_n! / a).
             // 5. Return the minimum: The answer is the minimum across all prime factors.
//Time Complexity  : O(√k + log n) — We factorize k in O(√k) time, then for each prime factor (at most log k factors), we apply Legendre's formula which takes O(log n) time.
//Space Complexity : O(log k) — We store the prime factors of k in a vector.
class Solution {
  public:
    int maxKPower(int n, int k) {
        // code here
        // Edge case: if k is 1, any number divides by 1 infinite times
        if (k == 1) return n; // or return a large number
        
        // Find prime factorization of k
        vector<pair<int, int>> primeFactors;
        int temp = k;
        
        // Check for factor 2
        if (temp % 2 == 0) {
            int count = 0;
            while (temp % 2 == 0) {
                count++;
                temp /= 2;
            }
            primeFactors.push_back({2, count});
        }
        
        // Check for odd factors from 3 onwards
        for (int i = 3; i * i <= temp; i += 2) {
            if (temp % i == 0) {
                int count = 0;
                while (temp % i == 0) {
                    count++;
                    temp /= i;
                }
                primeFactors.push_back({i, count});
            }
        }
        
        // If temp is still greater than 1, then it's a prime factor
        if (temp > 1) {
            primeFactors.push_back({temp, 1});
        }
        
        // Apply Legendre's formula for each prime factor
        int result = INT_MAX;
        
        for (auto& factor : primeFactors) {
            int prime = factor.first;
            int power = factor.second;
            
            // Count how many times 'prime' appears in n!
            int countInFactorial = 0;
            for (int p = prime; p <= n; p *= prime) {
                countInFactorial += n / p;
                // Check for overflow before next multiplication
                if (p > n / prime) break;
            }
            
            // How many complete sets of k can we form with this prime?
            int setsFromThisPrime = countInFactorial / power;
            
            // The answer is limited by the prime factor that gives minimum sets
            result = min(result, setsFromThisPrime);
        }
        
        return result;
    }
};
