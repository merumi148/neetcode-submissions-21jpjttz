class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> mainStack;
        int x, y;
        string op = "+-*/";
        for(int i = 0; i < tokens.size(); i++){
            int temp;
            if(op.find(tokens[i]) == string::npos){
                temp = stoi(tokens[i]);
                mainStack.push(temp);
            }
            else{
                if(tokens[i][0] == '+'){
                    x = mainStack.top();
                    mainStack.pop();
                    y = mainStack.top();
                    mainStack.pop();
                    temp = y + x;
                    mainStack.push(temp);
                }
                if(tokens[i][0] == '-'){
                    x = mainStack.top();
                    mainStack.pop();
                    y = mainStack.top();
                    mainStack.pop();
                    temp = y - x;
                    mainStack.push(temp);
                }
                if(tokens[i][0] == '*'){
                    x = mainStack.top();
                    mainStack.pop();
                    y = mainStack.top();
                    mainStack.pop();
                    temp = y * x;
                    mainStack.push(temp);
                }
                if(tokens[i][0] == '/'){
                    if(mainStack.top() == 0) return 0;
                    x = mainStack.top();
                    mainStack.pop();
                    y = mainStack.top();
                    mainStack.pop();
                    temp = y / x;
                    mainStack.push(temp);
                }
                
            }
        }
         return mainStack.top();
    }
};
