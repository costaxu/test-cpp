#define COSTA_DEBUG
#include <stdio.h>
#include <tr1/memory>

using std::tr1::shared_ptr;


shared_ptr<int> ReturnSharedPtr()
{
    shared_ptr<int> p(new int(1000));
    shared_ptr<int> p2(p);
    shared_ptr<int> p3=p;
    shared_ptr<int> p4;
    p4=p2;
    return p;
}

int main()
{
    shared_ptr<int> p1 = ReturnSharedPtr();
    printf("%d\n", *p1);
    return 0;
}
