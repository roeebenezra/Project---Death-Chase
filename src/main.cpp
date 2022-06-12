#include <SFML/Graphics.hpp>
#include "Controller.h"
#include <exception>

int main() try
{
    auto controller = Controller();
    controller.run();
}
catch (std::exception& ex)
{
    std::cerr << "Exception: " << ex.what() << '\n';
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Unknown exception\n";
    return EXIT_FAILURE;
}