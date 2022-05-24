#include <iostream>
using namespace std;
 
template<typename... Targs>
void test(Targs...args) {
    int num = sizeof...(Targs);
    cout << num << "\n";
    int num2 = sizeof...(args);
    cout << num2 << "\n";
    for (int i : args...) cout << i << "\n";
}
 
int main()
{
    test(1,2,3,4);
}