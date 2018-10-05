// 
// This code is property of Celartem, Inc dba LizardTech.
// Copyright (c) 1995-2018. All rights reserved.
// Use permitted only under license from LizardTech.
// 
/* PUBLIC */

#ifndef LTI_IMAGE_READER_H
#define LTI_IMAGE_READER_H

// lt_lib_mrsid_core
#include "lti_imageStage.h"
#include "lti_imageStageOverrides.h"


LT_BEGIN_LIZARDTECH_NAMESPACE

/**
 * abstract class for implementing an image reader
 *
 * The LTIImageReader abstract class extends the LTIImageStage so that it can
 * be used as a decoder for an image format, i.e. the "end" of an image
 * pipeline.  This is the base class for such classes as the MrSIDImageReader.
 */
#ifdef SWIG
class LTIImageReader : public LTIImageStage
#else
class LTIImageReader : public LTIOverrideDimensions
                              <LTIOverridePixelProps
                              <LTIOverrideGeoCoord
                              <LTIOverrideMagnification
                              <LTIOverrideIsSelective
                              <LTIOverrideStripHeight
                              <LTIOverrideDelegates
                              <LTIOverridePixelLookupTables
                              <LTIOverrideMetadata
                              <LTIImageStage> > > > > > > > >
#endif
{
   LT_DISALLOW_COPY_CONSTRUCTOR(LTIImageReader);
public:
   // LTIImage
   LT_STATUS getDimsAtMag(double mag,
                          lt_uint32& width,
                          lt_uint32& height) const;

   lt_uint32 getModifications(const LTIScene &scene) const;


   // LTIImageStage
   LTIMaskSource *getMask() const;
   bool getPipelineInfo(LTIPipelineInfo info) const;

   lt_int64 getEncodingCost(const LTIScene& scene) const;
   bool getReaderScene(const LTIScene &decodeScene,
                       LTIScene &readerScene) const;

   // override too support ImageReaders that don't support band selection
   LT_STATUS readBegin(const LTIPixel &pixelProps, const LTIScene &fullScene);
   LT_STATUS readStrip(LTISceneBuffer &buffer, const LTIScene &stripScene);
   LT_STATUS readEnd(void);

protected:
   LTIImageReader(bool supportBandSelection);

   LT_STATUS init(const LTIImage *image = NULL);

   
   LT_STATUS loadMetadataIntoObjects(const LTIMetadataDatabase &fileMetadata,
                                     LTIPixel &pixelProps,
                                     bool updatePixelProps,
                                     bool updateGeoCoord);
   virtual const char *getSourceName(void) const = 0;

protected:
   const bool m_supportBandSelection;
};


LT_END_LIZARDTECH_NAMESPACE


#endif // LTI_IMAGE_READER_H
