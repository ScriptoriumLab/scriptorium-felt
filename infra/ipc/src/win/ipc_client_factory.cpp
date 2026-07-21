#include "scriptorium/felt/infra/ipc/ipc_client_factory.h"

#include <memory>

#include "scriptorium/felt/infra/ipc/win/sync_named_pipe_client.h"

namespace scriptorium::felt::infra::ipc {
    std::unique_ptr<core::ipc::isync_ipc_client<std::string, std::string>> ipc_client_factory::create_sync_ipc_client(const std::string& name) {
        return std::make_unique<sync_named_pipe_client>(name);
    }
}
