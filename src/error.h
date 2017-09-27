#ifndef EPOLL_ERROR_H_
#define EPOLL_ERROR_H_

#include <errno.h>

#include "internal.h"
#include "ntstatus.h"

#define _return_error_helper(error, value) \
  do {                                     \
    err_set_win_error(error);              \
    return (value);                        \
  } while (0)

#define return_error(value, ...) _return_error_helper(__VA_ARGS__ + 0, value)

EPOLL_INTERNAL errno_t err_map_win_error_to_errno(DWORD error);
EPOLL_INTERNAL void err_set_win_error(DWORD error);

#endif /* EPOLL_ERROR_H_ */
