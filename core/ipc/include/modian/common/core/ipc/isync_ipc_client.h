#pragma once

namespace modian::common::core::ipc {
    template <typename Req, typename Res>
    class isync_ipc_client {
    public:
        virtual ~isync_ipc_client() = default;

        virtual Res sync_send(const Req& request) = 0;
    };
}
