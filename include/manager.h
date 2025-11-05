#pragma once

#include "server/server.h"
#include "client-list.h"

class Manager
{
public:
  Manager();
  void mainLoop();
  [[nodiscard]] bool readyToExit() const noexcept;

private:
  Networking::Server server_instance_{"40050"};
  ClientList client_list_{};  
};
