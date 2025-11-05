#include "manager.h"
#include "command-parser.h"

#include <cassert>
#include <unistd.h>

int main(int argc, char *argv[]) {
  
  Manager server_manager{};

  CommandParser::checkForValidArguments();

  while(!server_manager.readyToExit())
  {
    server_manager.mainLoop();
    sleep(1);
  }
  return 0;
}
