/*
 * Copyright (C) 1991, All Rights Reserved, by
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


#ifndef _TIME_H_
#define _TIME_H_

#if !defined(lint) && defined (INCLUDE_ALL_RCSID)
/* $Header: /cvs/ipprod/cvs_root/RDE/stlport-5.1.5/stl/config/dart/include/time.h,v 1.1 2008/06/07 10:47:34 andrei1 Exp $ */
#endif

/*
 * ANSI time-related types and functions
 *
 * Public definitions:
 *	see ANSI C specification
 *
 */


/* for NULL (required by ANSI C) and size_t */
#ifndef _STDDEF_H_
#include <stddef.h>
#endif

/* Blackbird system call redirection
 */

/* Not yet supported:
#define CLOCKS_PER_SEC 0
*/

typedef long clock_t;
typedef long time_t;


/* Structure to contain broken-down time	*/
struct tm
{	int	tm_sec,		/* seconds 0..59			*/
		tm_min,		/* minutes 0..59			*/
		tm_hour,	/* hour of day 0..23			*/
		tm_mday,	/* day of month 1..31			*/
		tm_mon,		/* month 0..11				*/
		tm_year,	/* years since 1900			*/
		tm_wday,	/* day of week, 0..6 (Sunday..Saturday) */
		tm_yday,	/* day of year, 0..365			*/
		tm_isdst;	/* >0 if daylight savings time		*/
				/* ==0 if not DST			*/
				/* <0 if don't know			*/
};

#ifdef __cplusplus
extern "C" {
#endif


#define CTIME_BUFFER_LENGTH      26         /* Value from orignal ctime code */


extern char*      asctime_r(const struct tm*, char *buf);
extern clock_t    clock();
extern char*      ctime_r(const time_t* timep, char *buf);
extern struct tm* gmtime_r(const time_t*, struct tm*);
extern struct tm* localtime_r(const time_t*, struct tm*);
extern time_t     mktime(struct tm*);
extern time_t     mkgmtime(struct tm*);
extern size_t     strftime(char* s, size_t maxSize, const char* format,
			   const struct tm*);
  /* Blackbird system call redirection
   */
extern time_t     time(time_t*);
extern time_t     time_dump(time_t*);
extern time_t     gettimezone(time_t*);
extern char*      gettimezonename(int tm_isdst);


// XXX: hack
extern double difftime (time_t __time1, time_t __time0);
extern char *asctime (__const struct tm *__tp);
extern char *ctime (__const time_t *__timer);
extern struct tm *gmtime (__const time_t *__timer) ;
extern struct tm *localtime (__const time_t *__timer);

#ifdef __cplusplus
}
#endif



/*
 * The BSD functions do not belong here, but including them simplifies
 * some porting tasks.
 */

#ifndef _BSDTIME_H_
#include "bsdtime.h"
#endif

#endif /* _TIME_H_ */
