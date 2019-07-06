class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        string word;
        map<string, int> words;
        
        A += ' ' + B;
        int i = 0, parse;
        while(parse != string::npos) {
            parse = A.find(' ', i);
            word = A.substr(i, parse - i);
            i = parse + 1;
            
            words[word]++;
        }
        
        vector<string> res;
        for(map<string, int>::iterator it = words.begin(); it != words.end();
           ++it) {
            if(it->second == 1)
                res.push_back(it->first);
            // cout << it->first << it->second << endl;
        }
        
        return res;
                
    }
};