#pragma once
#include <span>

namespace CommandParser 
{
  void checkForValidArguments(std::span<const char*> arguments);
}
