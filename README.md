# menu
Simple sugar for terminal application

#### For example:

```
#include "menu.hpp"

class App: public Menu
{
public:
    App() : Menu(START, "Application menu"){};

private:
    virtual void initialize() override;

    enum Condition: int
    {
        START,
        ADD,
        DEL,
        EDIT,
        EXIT,
    };

    void start();
    void add();
    void del();
    void edit();
    void exit();
};
```

## main.cpp:
```
int main()
{
    App app;
    app.run();
}
```
