#pragma once

#include <cassert>
#include <unistd.h>

namespace
{
constexpr int error_status{-1};
}

template <typename File> class LinuxFd
{
public:
  LinuxFd(const int file_descriptor = error_status) : fd_{file_descriptor} {}
  ~LinuxFd() { close(fd_); }

  LinuxFd(const LinuxFd&) = delete;            // Delete copy constructor.
  LinuxFd& operator=(const LinuxFd&) = delete; // Delete copy assignment constructor.

  [[nodiscard]] const int& GetFd() const noexcept
  {
    assert(fd_ != error_status);
    return fd_;
  }

  void setFd(const int file_descriptor) noexcept
  {
    fd_ = file_descriptor;
    assert(fd_ != error_status);
  }
  
private:
  // Defaults to error but if successful would be overwritten by a correct value.
  int fd_{error_status};
};
