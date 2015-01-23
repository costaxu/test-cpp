#include <vector>
#include "allocator.h"
#include <iostream>
using namespace std;
int main()
{
   
    std::vector<int > vecInt;
    int i=0;  
    for(;i<10000000;i++)
    {
        vecInt.push_back(i);
    }
    
    return 0;
}
