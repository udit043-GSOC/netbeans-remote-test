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
 */

/*
 * 	RCS Log Removed.  To view log, use: rlog <file>
 */


#ifndef _STDIO_H_
#define _STDIO_H_

#if !defined(lint) && defined(INCLUDE_ALL_RCSID)
/* $Id: stdio.h,v 1.1 2008/06/07 10:47:34 andrei1 Exp $ */
/* $Source: /cvs/ipprod/cvs_root/RDE/stlport-5.1.5/stl/config/dart/include/stdio.h,v $ */
#endif

/*
 * ANSI stdio.h (or a subset, at least)
 */

#ifndef _STDARG_H_
#include <stdarg.h>
#endif

/* for size_t and NULL */
#ifndef _STDDEF_H_
#include <stddef.h>
#endif

#ifndef _CTYPE_H_
#include <ctype.h>
#endif

#define EOF (-1)

#ifndef NULL
#define NULL    0
#endif

#ifndef _SIZE_T_
#ifndef __size_t
#define _SIZE_T_
#define __size_t
typedef long unsigned int size_t;
#endif
#endif

#ifndef _SSIZE_T_
#define _SSIZE_T_
typedef long int ssize_t;
#endif

#ifndef _OFF_T_
#define _OFF_T_
typedef long long off_t;
typedef long long off64_t;
#endif

typedef off_t fpos_t;
typedef struct Stdio_AbstractFile FILE;


/* temporary definitions */
#define FILENAME_MAX	255
#define FOPEN_MAX	20

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;
extern FILE* console;
/* 
   was: extern const FILE* console;
   due to possible bug in the compiler, *console was considered
   to be a const object(which isn't true), and that caused a problem 
   in getLine() from stdin.cxx
*/

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

    void clearerr(FILE*);
    extern int fclose(FILE*);
    extern int feof(FILE*);
    extern int ferror(FILE*);
    extern int fflush(FILE*);
    extern int fgetc(FILE*);
    extern int fgetpos(FILE*, fpos_t*);
    extern char* fgets(char*, int, FILE*);
    extern int fileno(FILE* fp);
    extern void flockfile(FILE*);
    extern FILE* fopen(const char* filename, const char* mode);
    // new
    extern FILE *freopen (const char * filename,
                          const char * modes,
                      FILE * stream);
    extern void perror (__const char *__s);
    extern int putchar (int __c);
    extern void setbuf (FILE *__restrict __stream, char *__restrict __buf);
    extern int setvbuf (FILE *__restrict __stream, char *__restrict __buf,
                        int __modes, size_t __n);
    extern char *tmpnam (char *__s); 
    extern FILE *tmpfile (void);
    
    //// ond of new 
    extern int getchar (void);
    extern int fprintf(FILE*, const char*, ...);
    extern int fputc(int, FILE*);
    extern int fputs(const char*, FILE*);
    extern size_t fread(void*, size_t, size_t, FILE*);
    extern int fscanf(FILE*, const char*, ...);
    extern int fseek(FILE*, off_t, int);
    extern int fsetpos(FILE*, const fpos_t*);
    extern off_t ftell(FILE*);
    extern void funlockfile(FILE*);
    extern size_t fwrite(const void*, size_t, size_t, FILE*);
    extern int getc(FILE*);
#define getchar() fgetc(stdin)
#define getch() getchar()
    extern char* gets(char*);
    extern int printf(const char*, ...);
    extern int putc(int, FILE*);
#define putchar(c) fputc((c),stdout);
    extern int puts(const char*);
    extern int remove(const char*);
    extern int rename(const char*, const char*);
    extern void rewind(FILE*);
    extern int scanf(const char*, ...);
    extern int sprintf(char*, const char*, ...);
    extern int snprintf(char*, size_t, const char*, ...);
    extern int sscanf(const char*, const char*, ...);
    extern int ungetc(int, FILE*);
    extern int vprintf(const char *format, va_list args);
    extern int vsprintf(char*, const char*, va_list);
    extern int vsnprintf(char*, size_t,  const char*, va_list);
    extern int vfprintf(FILE*, const char*, va_list);

    extern int fgetLine(char*, int, FILE*);
    extern char* extractSubString(char, char*, char*);

  /* this will output to the debug screen rather that the thread screen */
  extern FILE* debuggerio;
  extern int db_printf(const char*, ...);




#define Ctod(c) ((c) - '0')

#ifndef SEEK_SET
#define	SEEK_SET	0	/* set file offset to offset */
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	/* set file offset to current plus offset */
#endif
#ifndef SEEK_END
#define	SEEK_END	2	/* set file offset to EOF plus offset */
#endif

#define	L_tmpnam	1024	/* XXX must be == PATH_MAX */
#define	TMP_MAX		308915776

#define	BUFSIZ	1024

#ifdef __cplusplus
	   }
#endif /* __cplusplus */

#endif /* _STDIO_H_ */
