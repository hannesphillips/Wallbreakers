class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res;
        map<string, int> doms;
        string tmp;
        int vis;
        
        for(int i = 0; i < cpdomains.size(); i++) {
            tmp = cpdomains[i];
            vis = stoi(tmp.substr(0, tmp.find(' ')));
            
            doms.insert({tmp.substr(tmp.find(' ') + 1), vis});
            
            int dot = tmp.find('.');
            while(dot != string::npos) {
                tmp = tmp.substr(dot + 1);
                
                if(doms.find(tmp) != doms.end())
                    doms[tmp] += vis;
                else 
                    doms.insert({tmp, vis});
                
                dot = tmp.find('.');
            }
        }
 
        for(auto i : doms) {
            res.push_back(to_string(i.second) + ' ' + i.first);
        }
        multiset<char> s = {}
        
        
        return res;
    }
};