class Solution {
public:
    int calPoints(vector<string>& ops) {
        int sum = 0;
        stack<int> vals;
        
        for(int i = 0; i < ops.size(); i++) {
            if(ops[i] == "+") {
                int t = vals.top();
                vals.pop();
                int s = vals.top() + t;
                vals.push(t);
                vals.push(s);
                sum += s;
                
            }
            else if(ops[i] == "C") {
                sum -= vals.top();
                vals.pop();
            }
            else if(ops[i] == "D") {
                vals.push(2 * vals.top());
                sum += vals.top();
            }
            else {
                vals.push(stoi(ops[i]));
                sum += vals.top();
            }
            // cout << sum << endl;
        }
        return sum;
    }
};