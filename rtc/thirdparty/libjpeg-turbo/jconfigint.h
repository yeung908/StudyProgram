#define VERSION "1.5.1"
#define BUILD "20171104"
#define PACKAGE_NAME "MediaProcessor"

#ifndef INLINE
#if defined(__GNUC__)
#define INLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER)
#define INLINE __forceinline
#else
#define INLINE
#endif
#endif
