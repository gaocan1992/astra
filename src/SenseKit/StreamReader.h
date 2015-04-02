#ifndef STREAMREADER_H
#define STREAMREADER_H

#include <sensekit_core.h>
#include "StreamSet.h"
#include <set>

namespace sensekit {

    class StreamReader
    {
    public:
        explicit StreamReader(StreamSet& streamSet)
            : m_streamSet(streamSet) { }

        StreamSet& get_streamSet() const { return m_streamSet; }

        StreamConnection* get_stream(sensekit_stream_type_t type,
                                     sensekit_stream_subtype_t subType);

    private:
        bool close_stream(StreamConnection* connection);

        using ConnectionSet = std::set<StreamConnection*>;

        StreamSet& m_streamSet;
        ConnectionSet  m_streamConnections;
    };
}

#endif /* STREAMREADER_H */
