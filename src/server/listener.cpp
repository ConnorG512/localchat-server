#include "server/listener.h"

#include <cerrno>
#include <cstring>
#include <format>
#include <stdexcept>
#include <sys/socket.h>

Network::Listener::Listener(const int& file_descriptor, const int back_log)
{
  initListen(file_descriptor, back_log);
}

void Network::Listener::initListen(const int& file_descriptor, const int back_log) const
{
  if(const int result = listen(file_descriptor, back_log); result == -1)
  {
    throw std::runtime_error(std::format("[listener.cpp] Failed to listen! {}.", strerror(errno)));
  }
}
