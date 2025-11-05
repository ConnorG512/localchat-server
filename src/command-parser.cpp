#include "command-parser.h"

#include <array>
#include <format>
#include <getopt.h>
#include <print>
#include <unistd.h>

namespace
{
constexpr auto valid_args{std::to_array<const char*>({"--help", "-h", "--verbose", "-v", "--password", "-p"})};
}

std::expected<void, std::string> CommandParser::OverMaxArgs(std::span<const char*> arguments)
{
  constexpr int max_arguments{2};

  if (arguments.size() > max_arguments)
  {
    return std::unexpected("Too many arguements provided!");
  }
  return {};
}

void CommandParser::printAvailableArguments()
{
  std::println("Available Arguments:");
  for (const auto string : valid_args)
  {
    std::println("\t{}", string);
  }
}
