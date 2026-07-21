#pragma once

#include "scriptorium/felt/core/protocol/v1/input/instruction.h"
#include "scriptorium/felt/core/protocol/v1/input/key_event.h"

namespace scriptorium::felt::service {
	class input_protocol_service {
	public:
		static std::string build_key_event_request(const core::protocol::input::v1::key_event& key_event);
		static core::protocol::input::v1::key_event parse_key_event_request(const std::string& request);

		static std::string build_instruction_response(const core::protocol::input::v1::instruction& instruction);
		static core::protocol::input::v1::instruction parse_instruction_response(const std::string& response);
	};
}
