// 
// This code is property of Celartem, Inc dba LizardTech.
// Copyright (c) 1995-2018. All rights reserved.
// Use permitted only under license from LizardTech.
// 
/* PUBLIC */

#ifndef LTI_GEO_IMAGE_READER_H
#define LTI_GEO_IMAGE_READER_H

// lt_lib_mrsid_core
#include "lti_imageReader.h"


LT_BEGIN_LIZARDTECH_NAMESPACE

/**
 * abstract class for implementing a geo image reader
 *
 * The LTIGeoImageReader abstract class extends the LTIImageReader so that it
 * allows whether world files are used or ignored for setting up geo
 * information.
 */
class LTIGeoImageReader : public LTIImageReader
{
   LT_DISALLOW_COPY_CONSTRUCTOR(LTIGeoImageReader);
protected:
   LTIGeoImageReader(bool supportBandSelection);

   LT_STATUS init(bool useWorldFile);

   bool getUseWorldFile() const;

   LT_STATUS readWorldFile(const LTFileSpec &file,
                           bool &changed, bool doUseWorldFileTest = true);
   LT_STATUS readWorldFile(LTIOStreamInf &stream,
                           bool &changed, bool doUseWorldFileTest = true);
private:
   bool m_useWorldFile;
};


LT_END_LIZARDTECH_NAMESPACE

#endif // LTI_GEO_IMAGE_READER_H
