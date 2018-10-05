// 
// This code is property of Celartem, Inc dba LizardTech.
// Copyright (c) 1995-2018. All rights reserved.
// Use permitted only under license from LizardTech.
// 

/* PUBLIC */

#ifndef LT_IO_FILE_STREAM_H
#define LT_IO_FILE_STREAM_H

#include "lt_ioStreamInf.h"
#include "lt_fileSpec.h"
#include <stdio.h>

#ifdef __ANDROID__
   #define USE_UNBUFFERED_READER
#endif

#if defined(LT_USE_DIGMAP)
LT_BEGIN_LIZARDTECH_NAMESPACE
class LTDigmapFile;
LT_END_LIZARDTECH_NAMESPACE
#endif

LT_BEGIN_LIZARDTECH_NAMESPACE


/**
 * File stream
 *
 * This class implements a file-based stream.
 *
 */
class LTIOFileStream : public LTIOStreamInf
{
public:

   /** 
    * @name Construction, destruction, initialization
    */
   //@{

   /**   
    * Default Constructor
    */
   LTIOFileStream(void);

   /**   
    * Destructor
    */
   virtual ~LTIOFileStream(void);

   /**
    * Initializes the stream from a file spec
    *
    * @param   fs      file spec
    * @param   mode  mode (see stdio.h)
    */
   virtual LT_STATUS initialize(const LTFileSpec& fs, const char* mode);
   LT_STATUS initialize(const char* path, const char* mode);
   //@}

   // LTIOStreamInf overrides
   virtual bool isEOF();
   virtual bool isOpen();
   virtual LT_STATUS open();
   virtual LT_STATUS close();
   virtual lt_uint32 read(lt_uint8 *pDest, lt_uint32 numBytes);
   virtual lt_uint32 write(const lt_uint8 *pSrc, lt_uint32 numBytes);
   virtual LT_STATUS seek(lt_int64 offset, LTIOSeekDir origin);
   virtual lt_int64 tell();
   virtual LTIOStreamInf *duplicate();
   virtual LT_STATUS getLastError() const;
   virtual const char* getID() const;

   /** 
    * @name Status accessors
    */
   //@{
   /**
    * Returns underlying stdio error code
    */
   int stdio_ferror();

   /**
    * Clears underlying stdio error code
    */
   void stdio_clearerr();
   //@}

   /**
    *   Set buffering - may be called only after open() but before
    *   the first read/write operation.
    *   @param   buf   buffer to use; if NULL then one is allocated
    *   @param   mode   one of the following:
    *                  _IONBF (unbuffered)
    *                  _IOLBF (line buffered)
    *                  _IOFBF (fully buffered)
    *   @param   size   size of buffer
    */
   int stdio_setvbuf( lt_uint8* buf, lt_uint32 mode, lt_uint32 size  );

private:

   void cleanup();
   bool shouldRetry();

protected:

#if defined(LT_USE_DIGMAP)
   LTDigmapFile *m_dmfile;
#elif defined(USE_UNBUFFERED_READER)
   int m_fd;
#else
   FILE* m_file;
   bool m_onceOpened;
#endif
   
   enum
   {
      unknown_state = 1,
      reading_state = 2,
      writing_state = 3
   } m_state;

   LTFileSpec m_path;
   char *m_mode;
   char *m_uri;
};

LT_END_LIZARDTECH_NAMESPACE

#endif   // LT_STREAMINF_H
