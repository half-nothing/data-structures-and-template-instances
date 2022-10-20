#include "Vector.hpp"
using namespace std;

int main()
{
    int c[] = {1, 2, 3, 4, 5, 6}, a=1,b=7;
    Vector<int> vector(c, 6);
    vector.print();
    vector.push_back(a);
    vector.print();
    vector.push_back(b);
    vector.print();
    vector.pop_back();
    vector.print();
    return 0;
}
