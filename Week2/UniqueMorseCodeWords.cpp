class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Used to lookup morse encoding for each char
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // Track unique encodings
        unordered_set<string> unique;
        
        for(int i = 0; i < words.size(); i++) {
            string code = "";
            // Build encoded word
            for(int j = 0; j < words[i].length(); j++) {
                code += morse[words[i][j] - 97];
            }
            if(unique.find(code) == unique.end()) // Determine if unique or seen already
                unique.insert(code);
        }
    return unique.size();
    }
};