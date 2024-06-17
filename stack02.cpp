// 2 stacks in an array
#include<iostream>
#include<stack>
using namespace std;

class TwoStacks{
    public:
        int *arr;
        int top1, top2;
        int size;

        TwoStacks(int size){
            this -> size = size;
            top1 = -1;
            top2 = size;
            arr = new int[size];
        }
        // push in stack 1
        void push1(int element){
            if(size - top1 > 1){
                top1++;
                arr[top1] = element; 
            }
            else{
                cout << "Stack1 overflow" << endl;
            }
        }
        // push in stack 2
        void push2(int element){
            if(top2 - top1 > 1){
                top2--;
                arr[top2] = element;
            }
            else{
                cout << "Stack2 overflow" << endl;
            }
        }
        // pop from stack 1
        int pop1(){
            if(top1 >= 0){
                int ans = arr[top1];
                top1--;
                return ans;
            }
            else{
                cout << "Stack underflow" << endl;
                return -1;
            }
        }
        // pop from stack 2
        int pop2(){
            if(top2 < size){
                int ans = arr[top2];
                top2++;
                return ans;
            }
            else{
                cout << "Stack underflow" << endl;
                return -1;
            }
        }
};

int main(){
    TwoStacks ts(6);
    
    ts.push1(3);
    ts.push1(4);
    ts.push2(9);
    ts.push2(8);
    cout<<ts.pop1()<<endl;
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<ts.pop2()<<endl;
    cout<<ts.pop1()<<endl;
    cout<<ts.pop2()<<endl;

}