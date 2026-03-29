class Solution {
    vector<int> stack;
    template<typename Op>
    void binaryOp(Op op) {
        int b = stack.back(); stack.pop_back();
        int a = stack.back(); stack.pop_back();
        return stack.push_back(op(a, b));
    }
public:
    int evalRPN(vector<string>& tokens) {
        for(auto& token: tokens) {
           if(token == "+") {
                binaryOp(plus<int>{});
           } else if(token == "-") {
                binaryOp(minus<int>{});
           } else if(token == "/") {
                binaryOp(divides<int>{});
           } else if(token == "*") {
                binaryOp(multiplies<int>{});
           } else {
                stack.push_back(stoi(token));
           }
        }
        return stack.back();
    }
};
