/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef OPENDAVINCI_CORE_WRAPPER_LIBRARIES_H_
#define OPENDAVINCI_CORE_WRAPPER_LIBRARIES_H_

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include "core/wrapper/ConfigurationTraits.h"

/**
 * Enumeration of supported, but mutually excluded system libraries.
 */
#include "core/wrapper/SystemLibraryProducts.h"

/**
 * Enumeration of supported, but mutually excluded system libraries.
 */
#include "core/wrapper/SerialPortLibraryProducts.h"

/**
 * Enumeration of supported, but mutually excluded network libraries.
 */
#include "core/wrapper/NetworkLibraryProducts.h"

/**
 * Enumeration of supported, but mutually excluded compression libraries.
 */
#include "core/wrapper/CompressionLibraryProducts.h"

/**
 * Enumeration of supported, but mutually excluded key/value-database  libraries.
 */
#include "core/wrapper/KeyValueDatabaseLibraryProducts.h"

namespace core {
    namespace wrapper {

        enum SYSTEM_ENDIANESS {
            IS_LITTLE_ENDIAN,
            IS_BIG_ENDIAN
        };

        #if defined(__i386__) || defined(i386) || defined(_M_IX86) || defined(_X86_) || defined(__arm__) || defined(__x86_64__) || defined(__ia64__) || defined(_M_X64_)
                const SYSTEM_ENDIANESS USESYSTEMENDINANESS = IS_LITTLE_ENDIAN;
        #elif defined(__ppc__) || defined(__powerpc) || defined(__powerpc__) || defined(__POWERPC__) || defined(_M_PPC)
                const SYSTEM_ENDIANESS USESYSTEMENDINANESS = IS_BIG_ENDIAN;
        #else
            #error "Please define system endianess in core/wrapper/Libraries.h."
        #endif


        /**
         * Which system library has to be used?
         */
        #ifdef WIN32
            OPENDAVINCI_STATIC_CONFIGURATION(SystemLibraryProducts, SystemLibraryWin32);
        #else
            OPENDAVINCI_STATIC_CONFIGURATION(SystemLibraryProducts, SystemLibraryPosix);
        #endif

        /**
         * Which serial port library has to be used?
         */
        #ifdef WIN32
            OPENDAVINCI_STATIC_CONFIGURATION(SerialPortLibraryProducts, SerialPortLibraryWin32);
        #else
            OPENDAVINCI_STATIC_CONFIGURATION(SerialPortLibraryProducts, SerialPortLibraryPosix);
        #endif

        /**
         * Which network library has to be used?
         */
        #ifdef WIN32
            OPENDAVINCI_STATIC_CONFIGURATION(NetworkLibraryProducts, NetworkLibraryWin32);
        #else
            OPENDAVINCI_STATIC_CONFIGURATION(NetworkLibraryProducts, NetworkLibraryPosix);
        #endif

        /**
         * Which compression library has to be used?
         */
        OPENDAVINCI_STATIC_CONFIGURATION(CompressionLibraryProducts, CompressionLibraryZIP);

        /**
         * Which key/value-database library has to be used?
         */
        OPENDAVINCI_STATIC_CONFIGURATION(KeyValueDatabaseLibraryProducts, KeyValueDatabaseBerkeleyDB);
    }
} // core::wrapper

#endif /*OPENDAVINCI_CORE_WRAPPER_LIBRARIES_H_*/
