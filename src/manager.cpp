#include "manager.h"

#include <print>

Manager::Manager()
{
  std::println("Server Initialised...");
}
void Manager::mainLoop()
{
  const int found_client {server_instance_.acceptConnection()};
  std::println("Found clinet! fd:{}.", found_client);
  client_list_.append(found_client);
}

[[nodiscard]] bool Manager::readyToExit() const noexcept{
  return false;
}
