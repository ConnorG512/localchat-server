#pragma once

#include "server/addrinfo.h"
#include "server/socket.h"
#include "server/binder.h"
#include "server/acceptor.h"
#include "server/connector.h"

namespace Network
{
class Server
{
public:
  Server() = default;

  Addrinfo addr_info{};
  Socket socket {addr_info.GetAddrInfo()};
  Binder binder {socket.GetFileDescriptor(), addr_info.GetAddrInfo()};
  Acceptor acceptor {socket.GetFileDescriptor()};
  Connector connector {socket.GetFileDescriptor(), addr_info.GetAddrInfo()};
};
} // namespace Network
