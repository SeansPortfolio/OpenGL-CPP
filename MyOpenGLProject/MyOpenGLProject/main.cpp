#include <iostream>

#include "Application.h"

int main(int argc, char* argv[])
{
    Application app{};

    if (!app.Init())
    {
        return EXIT_FAILURE;
    }
    
    app.Run();
    app.Quit();

    return EXIT_SUCCESS;
}
