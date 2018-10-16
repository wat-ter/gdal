// 
// This code is property of Celartem, Inc dba LizardTech.
// Copyright (c) 1995-2018. All rights reserved.
// Use permitted only under license from LizardTech.
// 
/* PUBLIC - C */
 
/**       
 * @file
 * 
 * Support for the IO classes.
 */
#ifndef LT_LIB_IO_H
#define LT_LIB_IO_H

#include "lt_base.h"

#ifdef LT_CPLUSPLUS
extern "C" {
#endif

/**
 *   Stream seek directions.
 */
typedef enum LTIOSeekDir
{
   /**   error */
   LTIO_SEEK_DIR_ERROR = 1,
   
   /** Offset from the beginning of the file */
   LTIO_SEEK_DIR_BEG = 2,

   /** Offset from the current read/write position */
   LTIO_SEEK_DIR_CUR = 3,

   /** Offset from the end of the file (offsets need to be negative to be valid) */
   LTIO_SEEK_DIR_END = 4,

   /** Marker */
   LTIO_SEEK_DIR_MAX = 5
} LTIOSeekDir;

//   status codes
#include "lt_ioStatus.h"

//   macros
#define LTIO_HR_FAILED(hr)  (static_cast<lt_int32>(hr) < 0)

#ifdef LT_CPLUSPLUS
}
#endif

#endif
