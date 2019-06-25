class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> even, odd;
        for(int i = 0; i < A.size(); ++i) {
            if(A.at(i) % 2 == 0) even.push_back(A.at(i));
            else odd.push_back(A.at(i));
        }
        for(int j = 0; j < odd.size(); ++j) {
            even.push_back(odd.at(j));
        }
        
        return even;
    }
};