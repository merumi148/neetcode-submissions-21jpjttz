class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mainStack;
        string op = "+-*/";
        for(int i = 0; i < tokens.size(); i++){
            if(op.find(tokens[i]) != string::npos){
                int y = mainStack.top(); mainStack.pop();
                int x = mainStack.top(); mainStack.pop();

                if(tokens[i][0] == '+') mainStack.push(x + y);
                else if(tokens[i][0] == '-') mainStack.push(x - y);
                else if(tokens[i][0] == '*') mainStack.push(x * y);
                else if(tokens[i][0] == '/') mainStack.push(x / y);
            }
            else{
                mainStack.push(stoi(tokens[i]));
            }
        }
         return mainStack.top();
    }
};
