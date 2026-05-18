#include "modian/common/service/protocol/input_protocol_service.h"

namespace modian::common::service {
	std::string input_protocol_service::build_key_event_request(const core::protocol::input::v1::key_event& key_event) {
        return key_event.content;
	}

    core::protocol::input::v1::key_event input_protocol_service::parse_key_event_request(const std::string& request) {
		return core::protocol::input::v1::key_event{request};
	}

	std::string input_protocol_service::build_instruction_response(const core::protocol::input::v1::instruction& instruction) {
		if (instruction.type == core::protocol::input::v1::message_type::NONE) return "";
		if (instruction.payload.empty()) return "";

		std::string draft_message;
		draft_message.reserve(2 + instruction.payload.size());
		draft_message += static_cast<char>(instruction.type);
		draft_message += ':';
		draft_message += instruction.payload;

		return draft_message;
	}

    core::protocol::input::v1::instruction input_protocol_service::parse_instruction_response(const std::string& response) {
		if (response.empty()) return { core::protocol::input::v1::message_type::NONE, "" };

		if (response.size() >= 2 && response.at(1) == ':') {
			switch (response.at(0)) {
            case static_cast<char>(core::protocol::input::v1::message_type::COMMIT):
				return { core::protocol::input::v1::message_type::COMMIT, response.substr(2) };
            case static_cast<char>(core::protocol::input::v1::message_type::UPDATE):
				return { core::protocol::input::v1::message_type::UPDATE, response.substr(2) };
			default:
				return {};
			}
		}

		return { core::protocol::input::v1::message_type::UPDATE, response };
	}
}
