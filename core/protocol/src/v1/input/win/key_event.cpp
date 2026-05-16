#include "modian/common/core/protocol/v1/input/key_event.h"

#include <windows.h>

namespace modian::common::core::protocol::input::v1 {
    key_event key_event::from_os_key(uint32_t key) {
        switch (key) {
        case VK_LEFT:  return { std::string(CMD_LEFT) };
        case VK_RIGHT: return { std::string(CMD_RIGHT) };
        case VK_SPACE: return { std::string(CMD_SPACE) };
        case VK_BACK:  return { std::string(CMD_BACKSPACE) };
        }

        if (key >= 'A' && key <= 'Z') {
            return { std::string(1, static_cast<char>(key)) };
        }

        return { "" };
    }
}
