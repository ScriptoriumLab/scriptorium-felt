#include "modian/common/infra/ipc/ipc_server_factory.h"

#include <memory>

#include "modian/common/infra/ipc/win/sync_named_pipe_client.h"
#include "modian/common/infra/ipc/win/sync_named_pipe_server.h"
#include "modian/common/infra/ipc/win/async_named_pipe_server.h"

namespace modian::common::infra::ipc {
    std::unique_ptr<core::ipc::isync_ipc_server<std::string, std::string>> ipc_server_factory::create_sync_ipc_server(const std::string& name) {
        return std::make_unique<sync_named_pipe_server>(name);
    }

    std::unique_ptr<core::ipc::isync_ipc_client<std::string, std::string>> ipc_server_factory::create_sync_ipc_client(const std::string& name) {
        return std::make_unique<sync_named_pipe_client>(name);
    }

    std::unique_ptr<core::ipc::iasync_ipc_server<std::string, std::string>> ipc_server_factory::create_async_ipc_server(const std::string& name) {
        return std::make_unique<async_named_pipe_server>(name);
    }
}
