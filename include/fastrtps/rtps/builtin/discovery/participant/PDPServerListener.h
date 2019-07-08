// Copyright 2019 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/**
 * @file PDPServerListener.h
 *
 */

#ifndef PDPSERVERLISTENER_H_
#define PDPSERVERLISTENER_H_
#ifndef DOXYGEN_SHOULD_SKIP_THIS_PUBLIC


#include "../../../reader/ReaderListener.h"
#include "../../../common/CDRMessage_t.h"

namespace eprosima {
namespace fastrtps{
namespace rtps {

class PDPServer;

/**
 * Class PDPListener, specification used by the PDP to perform the History check when a new message is received.
 * This class is implemented in order to use the same structure than with any other RTPSReader.
 *@ingroup DISCOVERY_MODULE
 */
class PDPServerListener: public ReaderListener {
public:
    /**
    * @param in_PDP
    */
    PDPServerListener(PDPServer* in_PDP)
    : mp_PDP(in_PDP)
    {
    }

    ~PDPServerListener() override {}
    //!Pointer to the associated mp_SPDP;
    PDPServer* mp_PDP;
    /**
     * New added cache
     * @param reader
     * @param change
     */
    void on_new_cache_change_added(
        RTPSReader* reader,
        const CacheChange_t* const change) override;

    /**
     * Get the key of a CacheChange_t
     * @param change Pointer to the CacheChange_t
     * @return True on success
     */
    bool getKey(CacheChange_t* change);
    //!Auxiliary message.
    CDRMessage_t aux_msg;
};


}
} /* namespace rtps */
} /* namespace eprosima */

#endif
#endif /* PDPSERVERLISTENER_H_ */
