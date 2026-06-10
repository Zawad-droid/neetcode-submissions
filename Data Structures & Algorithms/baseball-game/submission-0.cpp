class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>record;
        int total = 0;
        for(int i = 0; i < operations.size(); i++){
            if(operations[i] != "+" && operations[i] != "C" && operations[i] != "D"){
                record.push(stoi(operations[i]));
            }
            if(operations[i] == "+"){
                int first = record.top();
                record.pop();
                int second = record.top();
                int sum = first + second;
                record.push(first);
                record.push(sum);
            }
            if(operations[i] == "D") record.push(record.top() * 2);
            if(operations[i] == "C") record.pop();
        }
        while(!record.empty()){
            total += record.top();
            record.pop();
        }
        return total;
    }
};