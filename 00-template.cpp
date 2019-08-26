#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// template <class T> has same meaning
template <typename T>
void log(const T& t)
{
    cout << t << endl;    
}

class Int
{
public:
    Int(int value, string name = "") : value(value), name(name) {}
    
    // function object
    int operator()() const { return value; }
    
    // operator overload
    bool operator<(const Int& other) const { return value < other.value; }
    
    
    // let attributes public, could be a struct as well
    int value;
    const string name;
};

ostream& operator<<(ostream& os, const Int& i)
{
    return os << (i.name.empty() ? "Int" : i.name) << "(" << i.value << ")";    
}

int main()
{
    // function template with standard types
    cout << "log some standard types:" << endl;
    log("string");
    log(1);
    log(3.14);

    // function template with user type
    cout << endl << "log user type:" << endl;
    Int i(2, "i");
    Int j(3);
    log(i);
    log(j);

    // standard function template with user type
    cout << endl <<"use standard function templates min and max:" << endl;
    cout << "max(2, 3):" << max(2, 3) << endl;
    cout << "max(i, j):" << max(i, j) << endl;
    cout << "min(i, j):" << min(i, j) << endl;

    // with functor usage
    cout << endl << "a functor usage:" << endl;
    cout << "max(i(), j()):" << max(i(), j()) << endl;

    // iteration
    cout << endl << "iterate vector of Int:" << endl;
    vector<Int> v = {j, i};
    for_each (v.begin(), v.end(), log<Int>); // why can't compiler resolve simply log ?
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << ", ";
    }
      
    return 0;
}
