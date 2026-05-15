#pragma once

#include <string_view>

namespace modian::common::core::protocol::input::v1 {
    constexpr std::string_view CMD_LEFT = "cmd:left";
    constexpr std::string_view CMD_RIGHT = "cmd:right";
    constexpr std::string_view CMD_SPACE = "cmd:space";
    constexpr std::string_view CMD_BACKSPACE = "cmd:backspace";
}
