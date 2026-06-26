#include "gtest/gtest.h"

#include "modian/common/service/protocol/input_protocol_service.h"

TEST(input_protocol_service_test, should_return_U_message_when_build_update_response) {
	const modian::common::core::protocol::input::v1::instruction instruction { modian::common::core::protocol::input::v1::message_type::UPDATE, "ni" };
	const auto message = modian::common::service::input_protocol_service::build_instruction_response(instruction);
	ASSERT_EQ(message, R"({"payload":"ni","type":"U"})");
}

TEST(input_protocol_service_test, should_return_empty_string_when_build_response_with_null) {
	const modian::common::core::protocol::input::v1::instruction instruction { modian::common::core::protocol::input::v1::message_type::UPDATE, "" };
	const auto message = modian::common::service::input_protocol_service::build_instruction_response(instruction);
	ASSERT_EQ(message, R"({"payload":"","type":"U"})");
}

TEST(input_protocol_service_test, should_return_C_message_when_when_build_commit_response) {
	const modian::common::core::protocol::input::v1::instruction instruction { modian::common::core::protocol::input::v1::message_type::COMMIT, "你" };
	const auto message = modian::common::service::input_protocol_service::build_instruction_response(instruction);
	ASSERT_EQ(message, R"({"payload":"你","type":"C"})");
}

TEST(input_protocol_service_test, should_get_commit_and_correct_candidate_when_decode) {
	const auto& protocol = modian::common::service::input_protocol_service::parse_instruction_response("C:你");
	ASSERT_EQ(protocol.type, modian::common::core::protocol::input::v1::message_type::COMMIT);
	ASSERT_EQ(protocol.payload, "你");
}

TEST(input_protocol_service_test, should_get_update_and_correct_message_when_decode) {
	const auto& protocol = modian::common::service::input_protocol_service::parse_instruction_response("U:dia");
	ASSERT_EQ(protocol.type, modian::common::core::protocol::input::v1::message_type::UPDATE);
	ASSERT_EQ(protocol.payload, "dia");
}

TEST(input_protocol_service_test, should_get_none_when_decode_empty_message) {
	const auto& protocol = modian::common::service::input_protocol_service::parse_instruction_response("");
	ASSERT_EQ(protocol.type, modian::common::core::protocol::input::v1::message_type::NONE);
	ASSERT_EQ(protocol.payload, "");
}
