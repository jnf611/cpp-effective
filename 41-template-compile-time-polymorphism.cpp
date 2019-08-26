#include <iostream>

using namespace std;

// class declaration:
// - decalration of explicite interface
// - virtual member functions implies runtime polymorphism
class Widget
{
public:
    Widget() {}
    Widget(int value) : m_value(value) {}
    virtual ~Widget() {}
    virtual size_t size() const { return sizeof(m_value); }
    virtual void normalize() { cout << "Widget::normalize()" << endl; }
    void swap(Widget& other) { std::swap(*this, other); }
    bool operator!=(const Widget& other) { return m_value != other.m_value; }

private:
    int m_value;
};

static const Widget someNastyWidget(0);

void doProcessing(Widget& w)
{
    if (w.size() < 10 && w != someNastyWidget) {
        Widget tmp(w);
        tmp.normalize();
        tmp.swap(w);
    }
}

// template definition:
// - implicit interface: method that object must support are defined in the template function
// - compile-time polymorphism consist in
//    - instanciation with different template parameters
//    - function overloading resolution
template<typename T>
void doProcessingTemplate(T& w)
{
    if (w.size() < 10 && w != someNastyWidget) {
        T tmp(w);
        tmp.normalize();
        tmp.swap(w);
    }
}

int main()
{
    Widget w(2);
    doProcessing(w);
    doProcessingTemplate(w);

    return 0;
}