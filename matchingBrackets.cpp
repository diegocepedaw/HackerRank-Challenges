#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

//https://www.hackerrank.com/challenges/ctci-balanced-brackets

bool is_balanced(string expression) {
    stack<char> stack1;
    stack<char> stack2;
    
    //fill stack with individual symbols
    for(int iii=0;iii<expression.length();++iii){
        stack1.push(expression[iii]);
    }
    while(!(stack1.empty())){
       char tempChar = stack1.top();
       stack1.pop();
       if(!stack2.empty()){
           
           char stack2Top = stack2.top();
           //if they are a closing pair discard both of the symbols
           if((stack2Top == ')' && tempChar=='(') || (stack2Top == ']' && tempChar=='[') || (stack2Top == '}' && tempChar=='{')  )
           {
              
               stack2.pop();
               continue;
           }
               
       }
           
       
       if(tempChar == '(' || tempChar == '{' || tempChar == '[')
           return false;
       else
           stack2.push(tempChar);
            
    }
    
    return stack2.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}