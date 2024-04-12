#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <time.h>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <bits/stdc++.h>

bool isOperator(string str){
    if(str=="(" or str==")" or str=="+" or str=="-" or str=="*" or str=="/") return true;
    return false;
}

int calc(int v1, int v2, string op){
    if(op=="+") return v2+v1;
    if(op=="-") return v2-v1;
    if(op=="*") return v2*v1;
    if(op=="/") return v2/v1;
    return -1;
}

int precedence(string op){
    if(op=="(" or op==")") return 0;
    if(op=="+" or op=="-") return 1;
    if(op=="*" or op=="/") return 2;
    return -1;
}

int evaluateInfixExpression(vector<string> exp){
    // less precedence wala op can not be above the high precedence wala op
    stack<int> operands;
    stack<string> operators;

    exp.insert(exp.begin(), "("), exp.push_back(")");

    for(int i=0;i<exp.size();i++){
        if(isOperator(exp[i])){
            if(exp[i]==")"){
                // evaluate until we get (
                while(operators.top()!="("){
                    int v1= operands.top(); operands.pop();
                    int v2= operands.top(); operands.pop();
                    string op= operators.top(); operators.pop();
                    int result= calc(v1, v2, op);
                    operands.push(result);
                }
                operators.pop();
            }
            else if(exp[i]=="(" or precedence(exp[i])>=precedence(operators.top())) operators.push(exp[i]);
            else{
                // evaluate until condition2 is satisfied
                while(precedence(exp[i])<precedence(operators.top())){
                    int v1= operands.top(); operands.pop();
                    int v2= operands.top(); operands.pop();
                    string op= operators.top(); operators.pop();
                    int result= calc(v1, v2, op);
                    operands.push(result);
                }
                operators.push(exp[i]);
            }
        } 
        else operands.push(stoi(exp[i]));
    }
    
    return operands.top();
}

int main(){

    vector<string> exp= {"2","*","(","5","*","(","3","+","6",")",")","/","15","-","2"};
    cout<< evaluateInfixExpression(exp);

return 0;
}