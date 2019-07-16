class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int profs[prices.size()]; // Best possible profit per day
        
        int low = INT_MAX;
        // Track lowest buying point and profit for each day after
        for(int i = 0; i < prices.size(); i++) {
            low = min(low, prices.at(i));
            profs[i] = prices.at(i) - low;
        }
        
        int maxProf = 0;
        // Acquire overall greatest profit
        for(auto i : profs)
            maxProf = max(maxProf, i);
        
        return maxProf;
    }
};