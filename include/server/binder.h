#pragma once

#include <sys/socket.h>
#include <netdb.h>

namespace Network 
{
  class Binder
  {
    public: 
      Binder(const int& file_descriptor, const struct addrinfo* const address_str);
      
      Binder(const Binder& binder) = delete;                                            // Delete copy constructor.
      Binder& operator=(const Binder& binder) = delete;                                 // Delete copy assignment constructor.

      void initBind(const int& file_descriptor, const addrinfo* const address_str);
  };
}
