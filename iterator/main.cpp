#include "container.h"
#include <iostream>
using std::cout;
using std::endl;
int main()
{
    Container<int> con;
    con.insert(1);
    con.insert(3);
    con.insert(5);
    con.insert(7);
    con.insert(9);
    Container<int>::iterator iter = con.begin();
    for(;iter!=con.end();iter++)
    {
        cout<<*iter<<endl;
    }
    return 0;
}
