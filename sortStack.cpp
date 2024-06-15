#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &s, int n){
    if(s.empty()|| (!s.empty() && s.top() < n)){
        s.push(n);
        return ;
    }
    int num = s.top();
    s.pop();

    // recursive call
    sortedInsert(s,n);

    s.push(num);
 
}

void sortStack(stack<int> &s){
    if(s.empty()){
        return ;
    }

    int num = s.top();
    s.pop();

    // recursive call
    sortStack(s);

    sortedInsert(s, num);
}

int main(){
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(-3);
    s.push(9);
    s.push(7);

    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}