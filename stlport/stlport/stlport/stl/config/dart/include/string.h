/*
 * Copyright (C) 1991, All Rights Reserved, by
 * Digital Equipment Corporation, Maynard, Mass.
 *
 * This software is furnished under a license and may be used and copied
 * only  in  accordance  with  the  terms  of such  license and with the
 * inclusion of the above copyright notice. This software or  any  other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of  the  software  is  hereby
 * transferred.
 *
 * The information in this software is subject to change without  notice
 * and  should  not be  construed  as  a commitment by Digital Equipment
 * Corporation.
 *
 * Digital assumes no responsibility for the use or  reliability  of its
 * software on equipment which is not supplied by Digital.
 *
 */

/*
 *	RCS Log Removed.  To view log, use: rlog <file>
 */

#ifndef _STRING_H_
#define _STRING_H_

#if !defined(_STDDEF_H_)
#include <stddef.h>
#endif

#if !defined(lint) && defined(INCLUDE_ALL_RCSID)
/* $Header: /cvs/ipprod/cvs_root/RDE/stlport-5.1.5/stl/config/dart/include/string.h,v 1.1 2008/06/07 10:47:34 andrei1 Exp $ */
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern char* strcat(char *, const char *);
extern char* strncat(char *, const char *, size_t);
extern char* strchr(const char *, int);
extern char* strnchr(const char *, int, int);
extern char* strrchr(const char *, int);
extern int strcmp(const char *, const char *);
extern int strncmp(const char *, const char *, size_t);
extern char* strcpy(char *, const char *);
extern char* strncpy(char*, const char*, size_t);
extern size_t strlen(const char *);
extern char* strstr(const char*, const char*);
extern char* strcasestr(const char*, const char*);
extern char* strnstr(const char*, const char*, size_t);
extern char* strtok_r(char *, const char *, char**);
extern size_t strspn(const char *s, const char *set);
extern char* strpbrk(const char *s, const char *set);
extern char* strerror(int errnum);

extern void* memchr(const void *, int, size_t);
extern int   memcmp(const void *, const void *, size_t);
extern void* memmove(void *, const void *, size_t);
extern void* memcpy(void *, const void *, size_t);
extern void* memset(void *, int, size_t);

extern int   memcmp4(const void *, const void *, size_t);
extern void* memcpy4(void *, const void *, size_t);
extern void* memset4(void *, int, size_t);

/* non-standard functions: */

/* extern int strcmpl(const char *, const char *); */
/* extern int memicmp(const char *, const char *, int); */
extern int strcasecmp(const char*, const char*);
extern int strncasecmp(const char*, const char*, int);


#define bcmp(s1, s2, len) memcmp(s1, s2, len)
#define bcopy(s, d, len)  memcpy(d, s, len)
#define bzero(d, len)     (void) memset(d, '\0', len)
extern char* strdup(const char*);



// XXX: hack
extern int strcoll(__const char *__s1, __const char *__s2);
extern size_t strxfrm (char *__restrict __dest,
                       __const char *__restrict __src, size_t __n);
extern size_t strcspn (__const char *__s, __const char *__reject);
extern char *strtok (char *__restrict __s, __const char *__restrict __delim);


#ifdef __cplusplus
}
#endif

#endif /* _STRING_H_ */
