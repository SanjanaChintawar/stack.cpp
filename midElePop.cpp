// Middle element delete karo in stack
#include<iostream>
#include<stack>
using namespace std;

void deleteMiddle(stack<int> &s,int count, int size){

    if(count == size/2){
        s.pop();
        return ;
    }

    int num = s.top();
    s.pop();

    // recursive call
    deleteMiddle(s, count+1, size);

    s.push(num);
}

int main(){
    stack<int>s;
    int count = 0;

    int n = 4;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    deleteMiddle(s,count,n);

    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}