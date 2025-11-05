#include "linux-fd.h"

[[nodiscard]] const int& LinuxFd::GetFd() const noexcept
{
  assert(fd_ != error_status);
  return fd_;
}

void LinuxFd::setFd(const int file_descriptor) noexcept
{
  fd_ = file_descriptor;
  assert(fd_ != error_status);
}
