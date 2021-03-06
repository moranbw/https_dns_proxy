#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <stdlib.h>        // NOLINT(llvmlibc-restrict-system-libc-headers)
#include <ev.h>

#ifdef __cplusplus
extern "C" {
#endif
// Initializes logging.
// Writes logs to descriptor 'fd' for log levels above or equal to 'level'.
void logging_init(int fd, int level);

// Initialize periodic timer to flush logs.
void logging_flush_init(struct ev_loop *loop);

// Cleans up and flushes open logs.
void logging_cleanup();

// Returns 1 if debug logging is enabled.
int logging_debug_enabled();

// Internal. Don't use.
void _log(const char *file, int line, int severity, const char *fmt, ...);
#ifdef __cplusplus
}
#endif

enum _LogSeverity {
  LOG_DEBUG,
  LOG_INFO,
  LOG_WARNING,
  LOG_ERROR,
  LOG_FATAL,
  LOG_MAX
};

#define DLOG(...) _log(__FILENAME__, __LINE__, LOG_DEBUG, __VA_ARGS__)
#define ILOG(...) _log(__FILENAME__, __LINE__, LOG_INFO, __VA_ARGS__)
#define WLOG(...) _log(__FILENAME__, __LINE__, LOG_WARNING, __VA_ARGS__)
#define ELOG(...) _log(__FILENAME__, __LINE__, LOG_ERROR, __VA_ARGS__)
#define FLOG(...) _log(__FILENAME__, __LINE__, LOG_FATAL, __VA_ARGS__)

#endif // _LOGGING_H_
