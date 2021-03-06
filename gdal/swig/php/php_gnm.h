/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.12
 *
 * This file is not intended to be easily readable and contains a number of
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG
 * interface file instead.
 * ----------------------------------------------------------------------------- */

#ifndef PHP_GNM_H
#define PHP_GNM_H

extern zend_module_entry gnm_module_entry;
#define phpext_gnm_ptr &gnm_module_entry

#ifdef PHP_WIN32
# define PHP_GNM_API __declspec(dllexport)
#else
# define PHP_GNM_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(gnm);
PHP_MSHUTDOWN_FUNCTION(gnm);
PHP_RINIT_FUNCTION(gnm);
PHP_RSHUTDOWN_FUNCTION(gnm);
PHP_MINFO_FUNCTION(gnm);

ZEND_NAMED_FUNCTION(_wrap_MajorObject_GetDescription);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_SetDescription);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_GetMetadataDomainList);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_GetMetadata_Dict);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_GetMetadata_List);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_SetMetadata);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_GetMetadataItem);
ZEND_NAMED_FUNCTION(_wrap_MajorObject_SetMetadataItem);
ZEND_NAMED_FUNCTION(_wrap_CastToNetwork);
ZEND_NAMED_FUNCTION(_wrap_CastToGenericNetwork);
ZEND_NAMED_FUNCTION(_wrap_Network_ReleaseResultSet);
ZEND_NAMED_FUNCTION(_wrap_Network_GetVersion);
ZEND_NAMED_FUNCTION(_wrap_Network_GetName);
ZEND_NAMED_FUNCTION(_wrap_Network_GetFeatureByGlobalFID);
ZEND_NAMED_FUNCTION(_wrap_Network_GetPath);
ZEND_NAMED_FUNCTION(_wrap_Network_DisconnectAll);
ZEND_NAMED_FUNCTION(_wrap_Network_GetProjection);
ZEND_NAMED_FUNCTION(_wrap_Network_GetProjectionRef);
ZEND_NAMED_FUNCTION(_wrap_Network_GetFileList);
ZEND_NAMED_FUNCTION(_wrap_Network_CreateLayer);
ZEND_NAMED_FUNCTION(_wrap_Network_CopyLayer);
ZEND_NAMED_FUNCTION(_wrap_Network_DeleteLayer);
ZEND_NAMED_FUNCTION(_wrap_Network_GetLayerCount);
ZEND_NAMED_FUNCTION(_wrap_Network_GetLayerByIndex);
ZEND_NAMED_FUNCTION(_wrap_Network_GetLayerByName);
ZEND_NAMED_FUNCTION(_wrap_Network_TestCapability);
ZEND_NAMED_FUNCTION(_wrap_Network_StartTransaction);
ZEND_NAMED_FUNCTION(_wrap_Network_CommitTransaction);
ZEND_NAMED_FUNCTION(_wrap_Network_RollbackTransaction);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_ConnectFeatures);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_DisconnectFeatures);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_DisconnectFeaturesWithId);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_ReconnectFeatures);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_CreateRule);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_DeleteAllRules);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_DeleteRule);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_GetRules);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_ConnectPointsByLines);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_ChangeBlockState);
ZEND_NAMED_FUNCTION(_wrap_GenericNetwork_ChangeAllBlockState);
#endif /* PHP_GNM_H */
