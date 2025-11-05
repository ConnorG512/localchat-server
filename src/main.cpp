#include "command-parser.h"
#include "manager.h"

#include <cstdlib>
#include <iostream>

int main(int argc, const char* argv[])
{
  if (const auto result = CommandParser::OverMaxArgs(std::span<const char*>(argv, argv + argc)); !result.has_value())
  {
    std::cerr << result.error() << "\n";
    CommandParser::printAvailableArguments();
    return EXIT_FAILURE;
  }

  Manager server_manager{};

  while (!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }

  return EXIT_SUCCESS;
}
