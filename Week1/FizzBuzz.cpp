class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i = 1; i <= n; i++) {
            s.push_back(to_string(i));
            if(!(i % 3)) {
                if(!(i % 5)) {
                    s.at(i-1) = "FizzBuzz";
                }
                else s.at(i-1) = "Fizz";
            }
            else if(!(i % 5)) s.at(i-1) = "Buzz";
        }
        
        return s;
    }
};