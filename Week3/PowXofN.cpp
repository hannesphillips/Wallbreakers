class Solution {
public:
    double myPow(double x, int n) {
        if(!n) return 1;                    // Power 0
        if(n == 1) return x;                // Power 1
        if(x == 1) return 1;                // Base 1
        if(x == -1) {                       // Base -1
            if(n % 2) return -1;
            return 1;
        }
        if(n == INT_MIN) return 0;          // Edge case, min power
        
        if(n < 0) return 1.0 / powHelp(x, -n);  // Negative exponent
        return powHelp(x, n);                   // Positive exponent
    }
    
    double powHelp(double x, int n) {
        // Base cases
        if(!n) return 1;
        if(n == 1) return x;
        
        double p = powHelp(x, n/2);             // Memoize
        if(n % 2) return x * p * p;
        else return p * p;
    }
};