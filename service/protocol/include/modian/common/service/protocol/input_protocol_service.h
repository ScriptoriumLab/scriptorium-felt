#pragma once

#include "modian/common/core/protocol/v1/input/instruction.h"
#include "modian/common/core/protocol/v1/input/key_event.h"

namespace modian::common::service {
	class input_protocol_service {
	public:
		static core::protocol::input::v1::key_event parse_key_event_request(const std::string& request);
		static std::string build_instruction_response(const core::protocol::input::v1::instruction& instruction);
	};
}
