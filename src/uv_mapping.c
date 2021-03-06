#include "uv.h"
#include "wasi_types.h"
#include "uv_mapping.h"


uvwasi_errno_t uvwasi__translate_uv_error(int err) {
  switch (err) {
    case UV_E2BIG:           return UVWASI_E2BIG;
    case UV_EACCES:          return UVWASI_EACCES;
    case UV_EADDRINUSE:      return UVWASI_EADDRINUSE;
    case UV_EADDRNOTAVAIL:   return UVWASI_EADDRNOTAVAIL;
    case UV_EAFNOSUPPORT:    return UVWASI_EAFNOSUPPORT;
    case UV_EAGAIN:          return UVWASI_EAGAIN;
    case UV_EALREADY:        return UVWASI_EALREADY;
    case UV_EBADF:           return UVWASI_EBADF;
    case UV_EBUSY:           return UVWASI_EBUSY;
    case UV_ECANCELED:       return UVWASI_ECANCELED;
    case UV_ECONNABORTED:    return UVWASI_ECONNABORTED;
    case UV_ECONNREFUSED:    return UVWASI_ECONNREFUSED;
    case UV_ECONNRESET:      return UVWASI_ECONNRESET;
    case UV_EDESTADDRREQ:    return UVWASI_EDESTADDRREQ;
    case UV_EEXIST:          return UVWASI_EEXIST;
    case UV_EFAULT:          return UVWASI_EFAULT;
    case UV_EFBIG:           return UVWASI_EFBIG;
    case UV_EHOSTUNREACH:    return UVWASI_EHOSTUNREACH;
    case UV_EINTR:           return UVWASI_EINTR;
    case UV_EINVAL:          return UVWASI_EINVAL;
    case UV_EIO:             return UVWASI_EIO;
    case UV_EISCONN:         return UVWASI_EISCONN;
    case UV_EISDIR:          return UVWASI_EISDIR;
    case UV_ELOOP:           return UVWASI_ELOOP;
    case UV_EMFILE:          return UVWASI_EMFILE;
    case UV_EMLINK:          return UVWASI_EMLINK;
    case UV_EMSGSIZE:        return UVWASI_EMSGSIZE;
    case UV_ENAMETOOLONG:    return UVWASI_ENAMETOOLONG;
    case UV_ENETDOWN:        return UVWASI_ENETDOWN;
    case UV_ENETUNREACH:     return UVWASI_ENETUNREACH;
    case UV_ENFILE:          return UVWASI_ENFILE;
    case UV_ENOBUFS:         return UVWASI_ENOBUFS;
    case UV_ENODEV:          return UVWASI_ENODEV;
    case UV_ENOENT:          return UVWASI_ENOENT;
    case UV_ENOMEM:          return UVWASI_ENOMEM;
    case UV_ENOPROTOOPT:     return UVWASI_ENOPROTOOPT;
    case UV_ENOSPC:          return UVWASI_ENOSPC;
    case UV_ENOSYS:          return UVWASI_ENOSYS;
    case UV_ENOTCONN:        return UVWASI_ENOTCONN;
    case UV_ENOTDIR:         return UVWASI_ENOTDIR;
    case UV_ENOTEMPTY:       return UVWASI_ENOTEMPTY;
    case UV_ENOTSOCK:        return UVWASI_ENOTSOCK;
    case UV_ENOTSUP:         return UVWASI_ENOTSUP;
    case UV_ENXIO:           return UVWASI_ENXIO;
    case UV_EPERM:           return UVWASI_EPERM;
    case UV_EPIPE:           return UVWASI_EPIPE;
    case UV_EPROTO:          return UVWASI_EPROTO;
    case UV_EPROTONOSUPPORT: return UVWASI_EPROTONOSUPPORT;
    case UV_EPROTOTYPE:      return UVWASI_EPROTOTYPE;
    case UV_ERANGE:          return UVWASI_ERANGE;
    case UV_EROFS:           return UVWASI_EROFS;
    case UV_ESPIPE:          return UVWASI_ESPIPE;
    case UV_ESRCH:           return UVWASI_ESRCH;
    case UV_ETIMEDOUT:       return UVWASI_ETIMEDOUT;
    case UV_ETXTBSY:         return UVWASI_ETXTBSY;
    case UV_EXDEV:           return UVWASI_EXDEV;
    case 0:                  return UVWASI_ESUCCESS;
    /* The following libuv error codes have no corresponding WASI error code:
          UV_EAI_ADDRFAMILY, UV_EAI_AGAIN, UV_EAI_BADFLAGS, UV_EAI_BADHINTS,
          UV_EAI_CANCELED, UV_EAI_FAIL, UV_EAI_FAMILY, UV_EAI_MEMORY,
          UV_EAI_NODATA, UV_EAI_NONAME, UV_EAI_OVERFLOW, UV_EAI_PROTOCOL,
          UV_EAI_SERVICE, UV_EAI_SOCKTYPE, UV_ECHARSET, UV_ENONET, UV_EOF,
          UV_ESHUTDOWN, UV_UNKNOWN
    */
    default:
      /* libuv errors are < 0 */
      if (err > 0)
        return err;

      return UVWASI_ENOSYS;
  }
}


int uvwasi__translate_to_uv_signal(uvwasi_signal_t sig) {
  switch (sig) {
#ifdef SIGABRT
    case UVWASI_SIGABRT:   return SIGABRT;
#endif
#ifdef SIGALRM
    case UVWASI_SIGALRM:   return SIGALRM;
#endif
#ifdef SIGBUS
    case UVWASI_SIGBUS:    return SIGBUS;
#endif
#ifdef SIGCHLD
    case UVWASI_SIGCHLD:   return SIGCHLD;
#endif
#ifdef SIGCONT
    case UVWASI_SIGCONT:   return SIGCONT;
#endif
#ifdef SIGFPE
    case UVWASI_SIGFPE:    return SIGFPE;
#endif
#ifdef SIGHUP
    case UVWASI_SIGHUP:    return SIGHUP;
#endif
#ifdef SIGILL
    case UVWASI_SIGILL:    return SIGILL;
#endif
#ifdef SIGINT
    case UVWASI_SIGINT:    return SIGINT;
#endif
#ifdef SIGKILL
    case UVWASI_SIGKILL:   return SIGKILL;
#endif
#ifdef SIGPIPE
    case UVWASI_SIGPIPE:   return SIGPIPE;
#endif
#ifdef SIGQUIT
    case UVWASI_SIGQUIT:   return SIGQUIT;
#endif
#ifdef SIGSEGV
    case UVWASI_SIGSEGV:   return SIGSEGV;
#endif
#ifdef SIGSTOP
    case UVWASI_SIGSTOP:   return SIGSTOP;
#endif
#ifdef SIGSYS
    case UVWASI_SIGSYS:    return SIGSYS;
#endif
#ifdef SIGTERM
    case UVWASI_SIGTERM:   return SIGTERM;
#endif
#ifdef SIGTRAP
    case UVWASI_SIGTRAP:   return SIGTRAP;
#endif
#ifdef SIGTSTP
    case UVWASI_SIGTSTP:   return SIGTSTP;
#endif
#ifdef SIGTTIN
    case UVWASI_SIGTTIN:   return SIGTTIN;
#endif
#ifdef SIGTTOU
    case UVWASI_SIGTTOU:   return SIGTTOU;
#endif
#ifdef SIGURG
    case UVWASI_SIGURG:    return SIGURG;
#endif
#ifdef SIGUSR1
    case UVWASI_SIGUSR1:   return SIGUSR1;
#endif
#ifdef SIGUSR2
    case UVWASI_SIGUSR2:   return SIGUSR2;
#endif
#ifdef SIGVTALRM
    case UVWASI_SIGVTALRM: return SIGVTALRM;
#endif
#ifdef SIGXCPU
    case UVWASI_SIGXCPU:   return SIGXCPU;
#endif
#ifdef SIGXFSZ
    case UVWASI_SIGXFSZ:   return SIGXFSZ;
#endif
    default:               return -1;
  }
}


uvwasi_timestamp_t uvwasi__timespec_to_timestamp(const uv_timespec_t* ts) {
  /* TODO(cjihrig): Handle overflow. */
  return (uvwasi_timestamp_t) ts->tv_sec * NANOS_PER_SEC + ts->tv_nsec;
}
