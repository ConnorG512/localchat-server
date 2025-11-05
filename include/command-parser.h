#pragma once

#include <expected>
#include <span>
#include <string>

namespace CommandParser
{
[[nodiscard]] std::expected<void, std::string> OverMaxArgs(std::span<const char*> arguments);
void printAvailableArguments();
} // namespace CommandParser
