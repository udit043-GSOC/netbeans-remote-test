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
 * 	RCS Log Removed.  To view log, use: rlog <file>
 */

#ifndef _BSDTIME_H_
#define _BSDTIME_H_

#if !defined(lint) && defined (INCLUDE_ALL_RCSID)
/* $Header: /cvs/ipprod/cvs_root/RDE/stlport-5.1.5/stl/config/dart/include/bsdtime.h,v 1.1 2008/06/07 10:47:34 andrei1 Exp $ */
#endif

/*
 * BSD (non-ANSI) time-related types and functions
 *
 * Public definitions:
 *	struct timeval
 *	gettimeofday()
 *	settimeofday()
 *	adjtime()
 *
 */

struct timeval {
    long tv_sec;
    long tv_usec;
};


/*
 * struct timezone is no longer used, even in BSD.
 * We provide it here only to simplify porting of anachronistic code.
 * The values returned by gettimeofday() should not be taken seriously.
 */

struct timezone {
    int tz_minuteswest; /* minutes west of Greenwich */
    int tz_dsttime;     /* type of dst correction */
};

#define DST_NONE        0       /* not on dst */
#define DST_USA         1       /* USA style dst */
#define DST_AUST        2       /* Australian style dst */
#define DST_WET         3       /* Western European dst */
#define DST_MET         4       /* Middle European dst */
#define DST_EET         5       /* Eastern European dst */

#ifdef __cplusplus
extern "C" {
#endif

/*
 * The second (timezone) argument to settimeofday() is no longer
 * used, even in BSD; it is retained here as void* for compatibility.
 * settimeofday() will fail if the timesoze argument in not NULL.
 */

extern int gettimeofday(struct timeval*, struct timezone*);
extern int settimeofday(const struct timeval*, void*);
extern int adjtime(const struct timeval* delta,
		   struct timeval* olddelta);

#ifdef __cplusplus
}
#endif

#endif /* _BSDTIME_H_ */
