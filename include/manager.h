#pragma once

#include "server/server.h"

class Manager
{
public:
  Manager();
  void mainLoop();
  [[nodiscard]] bool readyToExit() const noexcept;

private:
  Networking::Server server_instance_{"40050"};
};
