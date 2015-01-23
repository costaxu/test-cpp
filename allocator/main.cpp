#include <vector>
#include "allocator.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
   
    //std::vector<int, Costaxu::allocator<int> > vecInt;
    std::vector<string, Costaxu::allocator<string> > vecString;
    std::vector<int,Costaxu::allocator<int> > vecInt;
    vecString.push_back(string("1234567890"));
    cout<<"vecString.push_back"<<endl;

    vecString.push_back("4567890");
    cout<<"vecString.push_back"<<endl;

    vecString.push_back("abcdefg");
    cout<<"vecString.push_back"<<endl;

    vecInt.push_back(10000);
    cout<<"vecInt.push_back"<<endl;

    vecInt.push_back(12345);
    cout<<"vecInt.push_back"<<endl;

    int i=0;
    cout<<vecString[0]<<endl;
    cout<<vecString[1]<<endl;
    cout<<vecString[2]<<endl;
    cout<<vecInt[0]<<endl;
    cout<<vecInt[1]<<endl;
   /* 
    for(;i<;i++)
    {
        vecInt.push_back(i);
    }
    
    for(i=0;i<10;i++)
    {
        std::cout<<i<<std::endl;
    }
    */ 
    return 0;
}
