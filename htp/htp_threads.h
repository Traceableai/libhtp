#if HAVE_SYSCALL_H
#include <syscall.h>
#endif

#if HAVE_SYS_TYPES_H
#include <sys/types.h> /* for gettid(2) */
#endif

#if HAVE_SYS_PRCTL_H
#include <sys/prctl.h>
#endif

#include <pthread.h>

#ifndef OS_FREEBSD
#define HTPGetThreadIdLong(...) ({ \
   pid_t tmpthid; \
   tmpthid = syscall(SYS_gettid); \
   unsigned long _scgetthread_tid = (unsigned long)tmpthid; \
   _scgetthread_tid; \
})
#endif