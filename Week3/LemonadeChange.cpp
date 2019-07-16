class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int change[2] = {1, 0}; // Maintain count of 5s and 10s
        
        /* 
        If 1st customer doesn't pay with a 5,
        can't provide change 
        */
        if(bills.at(0) != 5) return false;
        
        /* 
        Check array for proper change combos.
        Return true iff all customers receive proper change 
        */
        for(int i = 1; i < bills.size(); i++) {
            if(bills[i] == 5)
                change[0]++;
            
            else if(bills[i] == 10) {
                if(!change[0])
                    return false;
                change[0]--;
                change[1]++;
            }
            
            else {
                if(change[0] && change[1]) {
                    change[0]--;
                    change[1]--;
                }
                else if(change[0] >= 3)
                    change[0] -= 3;
                else
                    return false;
            }
        }
        
        return true;
    }
};