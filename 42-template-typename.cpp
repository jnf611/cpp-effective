#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void simpleprint2nd(const T& container)
{
    if (container.size() >= 2)
        cout << "simpleprint2nd:" << container[1] << endl;
}

template <typename T>
void print2nd(const T& container)
{
    if (container.size() >= 2) {
        // need to reuse typename before any nested dependant type
        // eg. any type that depends on template parameter T
        // compiler name:"nested-name-specifier"
        typename T::const_iterator iter(container.begin());
        ++iter;
        int value = *iter;
        cout << "print2nd:" << value << endl;
        T tmp(container); // typename not allowed for the template parameter
        cout << "print2nd(twice):" << tmp[1] << endl;
    }
}

int main()
{
    vector<int> values = {0, 1, 2, 3};

    simpleprint2nd(values);
    print2nd(values);

    return 0;
}