#include <iostream>

using namespace std;

// functor or function object
class FunctionObject
{
public:
    // a fonction object overloads operator()
    bool operator()() { return true; }
};

class Logger
{
public:
    void operator()(const string& log) const { cout << log << endl; }     
};

class AccLogger
{
public:
    ~AccLogger() { flush(); }
    void operator()(const string& log) { m_log += log; }
    void flush() { cout << m_log << endl; m_log.clear(); }

private:
    string m_log;
};

int main()
{
    // undefined behaviour
    int* p = 0;
    cout << "deferecing a null pointer is undefined, maybe provoke segfault" << endl;
    //cout << *p << endl;

    // out of range access
    char hello[] = "hello";
    char c = hello[10];
    char d = hello[257];
    cout << c << ", " << d << "." << endl;
    
    FunctionObject fo;
    if (fo()) {
        cout << "fo is " << endl;
    }
    
    Logger log;
    log("this");
    log("is");
    log("fun");

    AccLogger alog;
    alog("this ");
    alog("is also ");
    alog("fun");

    return 0;
}
