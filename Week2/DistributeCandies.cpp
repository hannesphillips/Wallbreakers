class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int> candy;
        
        for(auto i : candies)
            candy[i]++;
        
        // for(auto x : candy)
        //     cout << x.first << ' ' << x.second << endl;
        
        return min(candies.size()/2, candy.size());
    }
};