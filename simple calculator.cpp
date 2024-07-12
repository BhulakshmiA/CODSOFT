#include<iostream>
using namespace std;
int main()
{
    int x,y;
    char operation;
    cout<<"Enter the first number:";
    cin>>x;
    cout<<"Enter an operation(+,-,*,/):";
    cin>>operation;
    cout<<"Enter the second number:";
    cin>>y;
    switch(operation){
        case '+':
        cout<<x+y<<endl;
        break;
        case '-':
        cout<<x-y<<endl;
        break;
        case '*':
        cout<<x*y<<endl;
        break;
        case '/':
        if(y!=0)
        {
            cout<<x/y<<endl;
        }
        else
        {
            cout<<"Error:Division by zero!"<<endl;
        }
        break;
        default:
        cout<<"Invalid operation"<<endl;
    }
    return 0;
}
