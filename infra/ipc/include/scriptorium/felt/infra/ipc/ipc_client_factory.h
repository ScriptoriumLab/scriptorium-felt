#pragma once

#include <string>
#include <memory>

#include "scriptorium/felt/core/ipc/isync_ipc_client.h"

namespace scriptorium::felt::infra::ipc {
    class ipc_client_factory {
    public:
        static std::unique_ptr<core::ipc::isync_ipc_client<std::string, std::string>> create_sync_ipc_client(const std::string& name);
    };
}
