#ifndef OS_FREEBSD
#define HTPGetThreadIdLong(...) ({ \
   pid_t tmpthid; \
   tmpthid = syscall(SYS_gettid); \
   unsigned long _scgetthread_tid = (unsigned long)tmpthid; \
   _scgetthread_tid; \
})
#endif