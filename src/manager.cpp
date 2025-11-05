#include "manager.h"

#include <print>

Manager::Manager()
{
  std::println("Server Initialised...");
}
void Manager::mainLoop()
{
}

[[nodiscard]] bool Manager::readyToExit() const noexcept{
  return false;
}
