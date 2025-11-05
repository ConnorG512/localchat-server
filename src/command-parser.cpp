#include "command-parser.h"

#include <getopt.h>
#include <unistd.h>
#include <iostream>

void CommandParser::checkForValidArguments(std::span<const char*> arguments)
{
  for(auto string : arguments)
  {
    std::cout << string << "\n";
  }
}
