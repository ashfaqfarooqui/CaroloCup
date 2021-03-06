/*
 * OpenDaVINCI.
 *
 * This software is open source. Please see COPYING and AUTHORS for further information.
 */

#ifndef OPENDAVINCI_CORE_WRAPPER_WIN32IMPL_WIN32UDPFACTORYWORKER_H_
#define OPENDAVINCI_CORE_WRAPPER_WIN32IMPL_WIN32UDPFACTORYWORKER_H_

// core/platform.h must be included to setup platform-dependent header files and configurations.
#include "core/platform.h"

#include "core/wrapper/NetworkLibraryProducts.h"
#include "core/wrapper/UDPFactoryWorker.h"

#include "core/wrapper/WIN32/WIN32UDPReceiver.h"
#include "core/wrapper/WIN32/WIN32UDPSender.h"

namespace core {
    namespace wrapper {

        template <> class OPENDAVINCI_API UDPFactoryWorker<NetworkLibraryWin32>
        {
            public:
                static UDPSender* createUDPSender(const string &address, const uint32_t &port)
                {
                    return new WIN32Impl::WIN32UDPSender(address, port);
                };

                static UDPReceiver* createUDPReceiver(const string &address, const uint32_t &port)
                {
                    bool isMulticast = false;
                    string::size_type posFirstDot = address.find(".");
                    if (posFirstDot != string::npos) {
                        stringstream numericalValueStream(address.substr(0, posFirstDot));
                        uint32_t numericalValue = 0;
                        numericalValueStream >> numericalValue;
                        isMulticast = ( (numericalValue >= 224) && (numericalValue <= 239) );
                        clog << "Creating " << (isMulticast ? "multicast" : "regular") << " UDP receiver at " << address << ":" << port << "." << endl;
                    }
                    return new WIN32Impl::WIN32UDPReceiver(address, port, isMulticast);
                };
        };
    }
} // core::wrapper

#endif /*OPENDAVINCI_CORE_WRAPPER_WIN32IMPL_WIN32UDPFACTORYWORKER_H_*/
