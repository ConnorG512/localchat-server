#include "manager.h"
#include "command-parser.h"
#include <iostream>

int main(int argc, const char* argv[]) {
  if(const auto result = CommandParser::OverMaxArgs(std::span<const char*>(argv, argv+argc)); !result.has_value())
  {
    std::cerr << result.error() << "\n"; 
    return -1;
  }
  CommandParser::printAvailableArguments();
  
  Manager server_manager{};

  while(!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }
  return 0;
}
