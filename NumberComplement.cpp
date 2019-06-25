class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        string bin = bitset<32>(num).to_string();
        bin = bin.substr(bin.find('1'));
        
        for(int i = 0; i < bin.length(); i++) {
            if(bin[bin.length()-1-i] == '0')
                res += pow(2, i);
        }
        return res;
    }
};