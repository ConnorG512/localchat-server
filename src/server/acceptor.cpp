#include "server/acceptor.h"
#include <cerrno>
#include <cstring>
#include <format>
#include <stdexcept>
#include <sys/socket.h>
#include <unistd.h>

Network::Acceptor::Acceptor(const int& file_descriptor) { initAccept(file_descriptor); }

Network::Acceptor::~Acceptor() { close(client_file_descriptor_); }

void Network::Acceptor::initAccept(const int& file_descriptor)
{
  client_file_descriptor_ = accept(file_descriptor, reinterpret_cast<sockaddr*>(&client_address_), &address_size_);
  if (client_file_descriptor_ == -1)
  {
    throw std::runtime_error(std::format("[acceptor.cpp] Failed to accept connection! {}.", strerror(errno)));
  }
}
