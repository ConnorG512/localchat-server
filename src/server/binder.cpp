#include "server/binder.h"

#include <cstring>
#include <format>
#include <stdexcept>

Network::Binder::Binder(const int& file_descriptor, const addrinfo* const address_str)
{
  initBind(file_descriptor, address_str);
}

void Network::Binder::initBind(const int& file_descriptor, const addrinfo* const address_str) 
{
  if(const int result = bind(file_descriptor, address_str->ai_addr, address_str->ai_addrlen); result == -1)
  {
    throw std::runtime_error(std::format("[binder.cpp] Failed to bind socket! {}.", strerror(result)));
  }
}
