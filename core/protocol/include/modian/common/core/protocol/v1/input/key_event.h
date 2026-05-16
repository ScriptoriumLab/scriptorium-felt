#pragma once

#include <string>

namespace modian::common::core::protocol::input::v1 {
	class key_event {
    public:
        key_event() = default;
        key_event(std::string content) : content{std::move(content)} {}

        static key_event from_os_key(uint32_t key);

		std::string content{};
        static constexpr std::string_view CMD_LEFT{ "cmd:left" };
        static constexpr std::string_view CMD_RIGHT{ "cmd:right" };
        static constexpr std::string_view CMD_SPACE{ "cmd:space" };
        static constexpr std::string_view CMD_BACKSPACE{ "cmd:backspace" };
	};
}
