#ifndef __QUANTKIT_GLOBAL_H__
#define __QUANTKIT_GLOBAL_H__

#include <QtCore/qglobal.h>

#if defined(QUANTKIT_LIBRARY)
#  define QUANTKIT_EXPORT Q_DECL_EXPORT
#else
#  define QUANTKIT_EXPORT Q_DECL_IMPORT
#endif

#endif // __QUANTKIT_GLOBAL_H__
