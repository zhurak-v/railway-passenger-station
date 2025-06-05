#include <windows.h>
#include "services/services.hpp"
#include "ui/menu.hpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    Menu menu(service);
    menu.run();

    return 0;
}