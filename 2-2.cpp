#include "List.hpp"
using namespace std;

int main()
{
    int c[] = {1, 2, 3, 4, 5, 6}, a=1,b=7;
    List<int> list(c, 6);
    list.print();
    list.pop_front();
    list.print();
    list.pop_back();
    list.print();
    return 0;
}
