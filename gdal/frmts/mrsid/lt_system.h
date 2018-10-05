// 
// This code is property of Celartem, Inc dba LizardTech.
// Copyright (c) 1995-2018. All rights reserved.
// Use permitted only under license from LizardTech.
// 
/* PUBLIC */

/**
 *  @file  lt_system.h
 *
 *  @brief Declaration of standard system headers in a C-interface.
 *
 */


#ifndef LT_SYSTEM_H
#define LT_SYSTEM_H

#include "lt_platform.h"

/*
 * justifications for inclusions are that we want:
 *
 *   NULL
 *   memcpy() ...
 *   malloc() ...
 *   strlen() ...
 *   isdigit() ...
 *   printf() ...
 *   posix
 */


/* common to all platforms */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stddef.h>
#include <ctype.h>
#include <limits.h>
#include <float.h>


#if defined(LT_OS_UNIX)

   #include <unistd.h>
   #include <strings.h>
   #include <time.h>

#elif defined(LT_OS_WIN)

   #include <time.h>

   #ifndef strcasecmp
      #define strcasecmp _stricmp
   #endif
   #ifndef strncasecmp
      #define strncasecmp _strnicmp
   #endif

#else

   #error Port me!

#endif


#endif /* LT_SYSTEM_H */
