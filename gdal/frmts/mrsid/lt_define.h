// 
// This code is property of Celartem, Inc dba LizardTech.
// Copyright (c) 1995-2018. All rights reserved.
// Use permitted only under license from LizardTech.
// 
/* PUBLIC */

/**
 * @file
 *
 * Preprocessor definitions used throughout LizardTech sources.  This file
 * should not be included directly; use lt_base.h instead.
 *
 * @note This file is C-callable.
 */

#ifndef LT_DEFINE_H
#define LT_DEFINE_H

#include "lt_platform.h"

 /**
 * @name Language settings
 */
/*@{*/

#if defined(__cplusplus)
   /** compiler supports C++ (as opposed to straight C) */
   #define LT_CPLUSPLUS

   #define LT_DISALLOW_COPY_CONSTRUCTOR(classname) \
      private: \
         classname(const classname &); \
         classname &operator=(const classname &)

   /**
    * @name C++ namespace settings
    */
   /*@{*/

   /** declare start of namespace, for declarations */
   #define LT_BEGIN_NAMESPACE( theNameSpace ) namespace theNameSpace {
   /** declare end of namespace, for declarations */
   #define LT_END_NAMESPACE( theNameSpace )   }

   /** declare start of nameless namespace, for declarations */
   #define LT_BEGIN_NAMELESS_NAMESPACE namespace {
   /** declare end of nameless namespace, for declarations */
   #define LT_END_NAMELESS_NAMESPACE   }

   /** declare use of namespace */
   #define LT_USE_NAMESPACE( theNameSpace ) using namespace theNameSpace;
   /** declare use of name */
   #define LT_USE_NAME( theName ) using theName;

   // (note this is the same model that is used in lidar/Base.h,
   // except we say "USING" instead of "USE")
   #define LT_BEGIN_LIZARDTECH_NAMESPACE  namespace LizardTech {
   #define LT_END_LIZARDTECH_NAMESPACE    }
   #define LT_USING_LIZARDTECH_NAMESPACE    using namespace LizardTech;

/*@}*/


#endif

/*}@*/

/**
 * @name Debug settings
 */
/*@{*/

#if defined _DEBUG  && !defined LT_DEBUG
   /** symbol for enabling debug code */
   #define LT_DEBUG
#endif

/*@}*/


/**
 * @name Miscellaneous macros
 */
/*@{*/

/** macro turns its argument into a quoted string */
#define LT_STRINGIFY(x) #x
/** macro expands its argument, and it into a quoted string */
#define LT_XSTRINGIFY(x) LT_STRINGIFY(x)

/** return lesser of two parameters */
#define LT_MIN(A,B) ((A) < (B) ? (A) : (B))
/** return greater of two parameters */
#define LT_MAX(A,B) ((A) > (B) ? (A) : (B))

/*@}*/

#if !defined static_assert && __cplusplus < 201103L
#if _MSC_VER < 1600
/* Compile Time Assert */
#define __static_assert2(e, l) typedef int static_assert_line_##l[e ? 1 : -1]
#define __static_assert1(e, l) __static_assert2(e, l)
#define static_assert(e, x) __static_assert1(e, __LINE__)
#endif
#endif



/**
 * @name Support for status string generation
 */
/*@{*/
#define LT_STATUSSTRING_ADD(NUM,STR)

/*@}*/

/* globally disable spurious VC++ warning resulting from use of templates  */
#ifdef LT_COMPILER_MS
   #pragma warning(disable:4786)
#endif

/* WinCE does not support the concept of a "current working directory"
   All file paths are relative to root.  Emulator-based validation
   uses this macro to work around this limitation */
#ifdef LT_OS_WINCE
#define WINCE_STORAGECARD "/Storage Card/"
#else
#define WINCE_STORAGECARD ""
#endif

#ifndef LT_ESRI_SOURCE_SDK
#define LT_SUPPORT_ENCRYPTED_MRSIDS
#endif

/* other includes to provide users of lt_define.h */
#include "lt_types.h"

#endif /* LT_DEFINE_H */
