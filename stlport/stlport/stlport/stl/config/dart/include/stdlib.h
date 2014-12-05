/*
 * Copyright (C) 1993, All Rights Reserved, by
 * EMC Corporation, Hopkinton, Mass.
 *
 * This software is furnished under a license and may be used and copied
 * only  in  accordance  with  the  terms  of such  license and with the
 * inclusion of the above copyright notice. This software or  any  other
 * copies thereof may not be provided or otherwise made available to any
 * other person. No title to and ownership of  the  software  is  hereby
 * transferred.
 *
 * The information in this software is subject to change without  notice
 * and  should  not be  construed  as  a commitment by EMC Corporation.
 *
 * EMC assumes no responsibility for the use or  reliability  of its
 * software on equipment which is not supplied by EMC.
 *
 */

/*
 * 	RCS Log Removed.  To view log, use: rlog <file>
 */

#ifndef _STDLIB_H_
#define _STDLIB_H_

#if !defined(lint) && defined(INCLUDE_ALL_RCSID)
/* $Header: /cvs/ipprod/cvs_root/RDE/stlport-5.1.5/stl/config/dart/include/stdlib.h,v 1.1 2008/06/07 10:47:34 andrei1 Exp $ */
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* status for exit() or _exit()		*/
#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

#ifndef NULL
#define NULL	0
#endif

#ifndef _SIZE_T_
#ifndef __size_t
#define _SIZE_T_
#define __size_t
#if defined(Blackbird_Fix) && defined(Blackbird_Support)
typedef unsigned int size_t;
#else
typedef long unsigned int size_t;
#endif
#endif
#endif

#ifndef _SSIZE_T_
#define _SSIZE_T_
typedef long int ssize_t;
#endif

#define RAND_MAX	32767
#define MB_CUR_MAX	1
typedef struct _DIV { int  quot,rem; } div_t;
typedef struct _LDIV { long quot,rem; } ldiv_t;

  /* This appears to be unused and causes compile errors */
#ifndef __cplusplus
#if !defined(_WCHAR_T_) && !defined(_WCHART)
#ifndef     __wchar_t
#define     __wchar_t
#define _WCHAR_T_
#define _WCHART
typedef char wchar_t;
#endif
#endif
#endif /* c++ */

double	 atof(const char *);
int	 atoi(const char *);
long	 atol(const char *);
double	 strtod(const char *,char **);
long	 strtol(const char *,char **,int);
unsigned long	 strtoul(const char *,char **,int);
long long strtoll(const char *,char **,int);
unsigned long long strtoull(const char *,char **,int);
int	 rand(void);
void	 srand(unsigned);
void	 abort(void);
int	 atexit(void (*)(void));
void	 exit(int);
char *	 getenv(const char *);
int	 system(const char *);
void *	 bsearch(const void *,const void *,size_t,size_t,
                 int ( *)(const void *,const void *));
void	 qsort(void *,size_t,size_t,
               int ( *)(const void *,const void *));
int	 abs(int);
div_t	 div(int,int);
long	 labs(long);
ldiv_t	 ldiv(long,long);
int	 mblen(const char *,size_t);
int	 mbtowc(wchar_t *,const char *,size_t);
int	 wctomb(char *,wchar_t);
size_t	 mbstowcs(wchar_t *, const char *, size_t);
size_t	 wcstombs(char *, const wchar_t *, size_t);

// XXX: hack
extern void *malloc (size_t __size);
extern void *calloc (size_t __nmemb, size_t __size);
extern void *realloc (void *__ptr, size_t __size);
extern void free (void *__ptr);




#ifdef __cplusplus
}
#endif

#endif /* _STDLIB_H_ */
