#include "command-parser.h"

#include <array>
#include <print>

void CommandParser::checkForValidArguments()
{
  if (passed_arguments.size() <= 1)
  {
    return;
  }

  constexpr std::array<std::pair<const char* const, const char* const>, 3> available_arguments{
      {{"-h", "--help"}}, {{"-p", "--password"}}, {{"-v", "--verbose"}}};

  for(const auto& string : available_arguments)
  {
    std::println(string);
  }
}
