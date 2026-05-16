#include "gtest/gtest.h"

#include <windows.h>

#include "modian/common/core/protocol/v1/input/key_event.h"

TEST(key_event_test, should_translate_to_backspace_command_when_user_input_is_vb_back) {
	constexpr WPARAM key{VK_BACK};
	const auto request = modian::common::core::protocol::input::v1::key_event::from_os_key(key);

	ASSERT_EQ(request.content, "cmd:backspace");
}

TEST(key_event_test, should_translate_to_right_command_when_user_input_is_vb_right) {
	constexpr WPARAM key{VK_RIGHT};
	const auto request = modian::common::core::protocol::input::v1::key_event::from_os_key(key);

	ASSERT_EQ(request.content, "cmd:right");
}

TEST(key_event_test, should_translate_to_left_command_when_user_input_is_vb_left) {
	constexpr WPARAM key{VK_LEFT};
	const auto request = modian::common::core::protocol::input::v1::key_event::from_os_key(key);

	ASSERT_EQ(request.content, "cmd:left");
}

TEST(key_event_test, should_translate_to_space_command_when_user_input_is_vb_space) {
	constexpr WPARAM key{VK_SPACE};
	const auto request = modian::common::core::protocol::input::v1::key_event::from_os_key(key);

	ASSERT_EQ(request.content, "cmd:space");
}

TEST(key_event_test, should_translate_to_normal_input_when_user_input_other_keys) {
	constexpr WPARAM key{'N'};
	const auto request = modian::common::core::protocol::input::v1::key_event::from_os_key(key);

	ASSERT_EQ(request.content, "N");
}

