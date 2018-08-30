#ifndef RMW_NODE_H_
#define RMW_NODE_H_

#include "rmw/rmw.h"

#include <micrortps/client/client.h>

#define EPROS_PRINT_TRACE() printf("func %s, in file %s:%d\n", __PRETTY_FUNCTION__, __FILE__, __LINE__);

// TODO(Borja): use static memory allocations with a fixed number of sessions/nodes.
typedef struct
{
    mrUDPTransport udp;
    mrSession session;
    mrObjectId participant_id;
    mrObjectId publisher_id;
    mrObjectId datawriter_id;
} MicroNode;

mrStreamId best_input;
mrStreamId reliable_input;
mrStreamId best_output;
mrStreamId reliable_output;

rmw_node_t* create_node(const char* name, const char* namespace_, size_t domain_id);
rmw_ret_t destroy_node(rmw_node_t* node);

#endif // !RMW_NODE_H_