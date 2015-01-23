#include <iostream>
#include <memory>
#include <vector>
#include <stdio.h>
using namespace std;

int main()
{
    //auto_ptr<int> p1 (new int(10));
    //auto_ptr<int> p2 (new int(20));
    //p1=p2;
    //printf("p1 %d\n",*p1);
    //printf("p2 %d\n",*p2);

    //auto_ptr<int> p1 ;
    //const auto_ptr<int> p2 (new int(20));

    //new( static_cast<void*> (&p1) ) auto_ptr<int>(p2);
    //printf("p1 %d\n",*p1);
    //printf("p2 %d\n",*p2);
    //p1=p2;
    //vector< auto_ptr<int> > v(10,auto_ptr<int>(new int));
    vector< auto_ptr<int> > v;


    int i=0;
    for(;i<10;i++)
    {
        v.push_back(auto_ptr<int>(new int(10))); 
    }

    //for(i=0;i<10;i++)
    //{
        //printf("%d\n",**(v[i]));
    //}
    return 0;
}
