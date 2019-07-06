class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> looped;                  // Track duplicate digit sets
        vector<int> digits;
        
        int sum = 0;
        /* Continue until sum of squares = 0 */
        while(sum != 1) {
            sum = 0;
            while(n > 0) {                          // Extracts digits of integer
                digits.push_back(n % 10);
                n /= 10;
            }
            
            for(int i = 0; i < digits.size(); i++)  // Calculate sum of squares
                sum += pow(digits[i], 2);
        
            if(looped.find(sum) != looped.end())    // If the sum has been seen prior, exit
                return false;
            
            /* Set up next iteration */
            looped.insert(sum);
            digits.clear();
            n = sum;
        }
        return true;
    }
};