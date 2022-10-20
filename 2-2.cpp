#include "include/List.hpp"
using namespace std;

int main()
{
    int a = 6, b = 5, c[] = {1, 2, 3, 4, 5, 6};
    List<int> list(c, 6);
    list.print();
    list.print(true);
    return 0;
}
