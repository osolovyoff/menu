#include "menu.hpp"
#include <iostream>

Menu::Menu(int _start_condition, const string& _condition_name /* = "" */)
: m_condition(_start_condition)
, m_root_condition_name(_condition_name)
{}

void Menu::run()
{
    bool is_working = true;
    initialize();

    while (is_working)
    {
        system("cls");
        welcomeTitle(m_root_condition_name);

        is_working = true;
        auto callback = m_functions_condition.find(m_condition);
        if (callback != m_functions_condition.end())
            is_working = callback->second();
    }
}

void Menu::welcomeTitle(const string& _condition_name)
{
    std::cout << _condition_name.c_str() << std::endl;
    std::cout << "_______________________________________________________________" << std::endl << std::endl;
}

void Menu::changeState(int _key, std::initializer_list<int> _list)
{
    for (auto elem:_list)
        if (elem == _key)
            m_condition = _key;
}