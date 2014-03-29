#ifndef __WEB_SOCK_W32_H__
#define __WEB_SOCK_W32_H__

// Windows uses _DEBUG and NDEBUG
#ifdef _DEBUG
#undef DEBUG
#define DEBUG 1
#endif

#pragma warning(disable : 4996)

#define MSG_NOSIGNAL 0
#define SHUT_RDWR SD_BOTH

#define SOL_TCP IPPROTO_TCP

#define random rand
#define usleep _sleep

#ifdef  __MINGW64__                                                             
#define DEF_POLL_STUFF
#endif
#ifdef  __MINGW32__                                                             
#define DEF_POLL_STUFF
#endif

#if _WIN32_WINNT < 0x0600
#define DEF_POLL_STUFF
#endif

#ifdef DEF_POLL_STUFF

#include <winsock2.h>

typedef struct pollfd {
	SOCKET fd;
	short  events;
	short  revents;
} WSAPOLLFD, *PWSAPOLLFD, *LPWSAPOLLFD;

#define POLLIN      0x0001      /* any readable data available   */
#define POLLOUT     0x0004      /* file descriptor is writeable  */
#define POLLERR     0x0008      /* some poll error occurred      */
#define POLLHUP     0x0010      /* file descriptor was "hung up" */
#define POLLNVAL    0x0020		/* requested events "invalid"    */

#endif

/* override configure because we are not using Makefiles */

#define LWS_NO_FORK

/* windows can't cope with this idea, needs assets in cwd */

#ifndef INSTALL_DATADIR
#define INSTALL_DATADIR "."
#endif

#endif
