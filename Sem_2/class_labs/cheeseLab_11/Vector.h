#include <iostream>
#include <stack>
#include <vector>
using namespace std;

template<class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
    vector<T> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    return v;
}

template<class T>
stack<T> copy_vector_to_stack(const vector<T>& v)
{
    stack<T> s;
    for(int i = (int)v.size() - 1; i >= 0; i--)
        s.push(v[i]);
    return s;
}

template<class T>
class Vector
{
    stack<T> s;
    int len;
public:
    Vector() : len(0) {}

    Vector(int n)
    {
        T a;
        for(int i=0; i<n; i++)
        {
            cin >> a;
            s.push(a);
        }
        len = n;
    }

    Vector(const Vector<T>& v)
    {
        len = v.len;
        vector<T> temp = copy_stack_to_vector(v.s);
        s = copy_vector_to_stack(temp);
    }

    void Print()
    {
        vector<T> v = copy_stack_to_vector(s);
        for(int i = (int)v.size() - 1; i >= 0; i--)
            cout << v[i] << endl;
    }

    T Max()
    {
        vector<T> v = copy_stack_to_vector(s);
        T m = v[0];
        for(const T& x : v)
            if(x > m) m = x;
        return m;
    }

    T Min()
    {
        vector<T> v = copy_stack_to_vector(s);
        T m = v[0];
        for(const T& x : v)
            if(x < m) m = x;
        return m;
    }

    T Srednee()
    {
        vector<T> v = copy_stack_to_vector(s);
        T sum = T();
        for(const T& x : v)
            sum = sum + x;
        return sum / (int)v.size();
    }

    void Add(const T& el, int pos)
    {
        vector<T> v = copy_stack_to_vector(s);
        vector<T> res;
        int i = 1;
        bool added = false;
        for(const T& x : v)
        {
            if(i == pos)
            {
                res.push_back(el);
                added = true;
            }
            res.push_back(x);
            i++;
        }
        if(!added)
            res.push_back(el);
        s = copy_vector_to_stack(res);
        len = (int)res.size();
    }

    void DelMin()
    {
        T m = Min();
        vector<T> v = copy_stack_to_vector(s);
        vector<T> res;
        for(const T& x : v)
            if(!(x == m))
                res.push_back(x);
        s = copy_vector_to_stack(res);
        len = (int)res.size();
    }

    void AddSredneeToAll()
    {
        T sred = Srednee();
        vector<T> v = copy_stack_to_vector(s);
        for(T& x : v)
            x = x + sred;
        s = copy_vector_to_stack(v);
    }
};
