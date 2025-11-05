#include "manager.h"
#include "command-parser.h"


int main(int argc, const char* argv[]) {
  Manager server_manager{};

  CommandParser::checkForValidArguments(std::span<const char*>(argv, argv+argc));

  while(!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }
  return 0;
}
