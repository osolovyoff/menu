#pragma once
#ifndef menu_h__
#define menu_h__

#include <string>
#include <functional>
#include <unordered_map>

class Menu
{
    typedef std::string string;
    typedef std::pair<int, const char*> ÑonditionTitle;

public:
    Menu(int _start_condition, const string& _condition_name = "");
    void run();

private:
    virtual void initialize() = 0;

protected:
    template<class O, class M>
    void setCallBack(int _condition, O* _obj, M _method)
    {
        m_functions_condition[_condition] = std::bind(_method, _obj);
    }

// additional functions
private:
    void welcomeTitle(const string& _state);
    void changeState(int _key, std::initializer_list<int> _list);

protected:
    int     m_condition;
    string  m_root_condition_name;

    std::unordered_map< int, std::function<bool()> > m_functions_condition;
};

#endif // menu_h__