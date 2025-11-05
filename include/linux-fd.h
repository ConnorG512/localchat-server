#pragma once

#include <cassert>
#include <unistd.h>

namespace
{
constexpr int error_status{-1};
}

class LinuxFd
{
public:
  LinuxFd(const int file_descriptor = error_status) : fd_{file_descriptor} {}
  ~LinuxFd() { close(fd_); }

  LinuxFd(LinuxFd&& linux_fd) noexcept
    : fd_ { linux_fd.fd_ } {}

  LinuxFd(const LinuxFd&) = delete;            // Delete copy constructor.
  LinuxFd& operator=(const LinuxFd&) = delete; // Delete copy assignment constructor.

  [[nodiscard]] const int& GetFd() const noexcept;

  void setFd(const int file_descriptor) noexcept;
  
private:
  // Defaults to error but if successful would be overwritten by a correct value.
  int fd_{error_status};
};
