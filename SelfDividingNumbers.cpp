class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
       
        for(int i = left; i <= right; i++) {
            bool t = true;
            int x = i;
            while(x > 0) {
                int d = x % 10;
                x /= 10;
                if(d == 0 || i % d != 0) {
                    t = false;
                    break;
                }
            }
            if(t) res.push_back(i);
        }
        return res;
    }
};