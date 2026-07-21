#pragma once

#include <string>
#include <memory>

#include "scriptorium/felt/core/ipc/isync_ipc_server.h"
#include "scriptorium/felt/core/ipc/iasync_ipc_server.h"

namespace scriptorium::felt::infra::ipc {
    class ipc_server_factory {
    public:
        static std::unique_ptr<core::ipc::isync_ipc_server<std::string, std::string>> create_sync_ipc_server(const std::string& name);
        static std::unique_ptr<core::ipc::iasync_ipc_server<std::string, std::string>> create_async_ipc_server(const std::string& name);
    };
}
