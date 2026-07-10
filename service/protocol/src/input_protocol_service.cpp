#include "modian/common/service/protocol/input_protocol_service.h"

#include <nlohmann/json.hpp>

#include "modian/common/core/logger/logger_service.h"

namespace modian::common::service {
	std::string input_protocol_service::build_key_event_request(const core::protocol::input::v1::key_event& key_event) {
        return key_event.content;
	}

    core::protocol::input::v1::key_event input_protocol_service::parse_key_event_request(const std::string& request) {
		return core::protocol::input::v1::key_event{request};
	}

    nlohmann::json build_candidate_info(const core::protocol::input::v1::candidate_info& candidate_info) {
        return {
            {"payload", candidate_info.payload}
        };
    }

    core::protocol::input::v1::candidate_info parse_candidate_info(const nlohmann::json& j) {
        return core::protocol::input::v1::candidate_info{
            j.value("payload", "")
        };
    }

    std::string input_protocol_service::build_instruction_response(const core::protocol::input::v1::instruction& instruction) {
        nlohmann::json j;
        switch (instruction.type) {
        case core::protocol::input::v1::message_type::COMMIT:
            j["type"] = "C";
            break;
        case core::protocol::input::v1::message_type::UPDATE:
            j["type"] = "U";
            break;
        case core::protocol::input::v1::message_type::NONE:
        default:
            j["type"] = "N";
            break;
        }
        j["candidate_info"] = build_candidate_info(instruction.candidate_info);

		return j.dump(-1);
	}

    core::protocol::input::v1::instruction input_protocol_service::parse_instruction_response(const std::string& response) {
        core::protocol::input::v1::instruction instruction{core::protocol::input::v1::message_type::NONE, { "" }};

        try {
            const auto j = nlohmann::json::parse(response);
            if (const std::string type_str = j.value("type", "N"); type_str == "C") {
                instruction.type = core::protocol::input::v1::message_type::COMMIT;
            } else if (type_str == "U") {
                instruction.type = core::protocol::input::v1::message_type::UPDATE;
            } else {
                instruction.type = core::protocol::input::v1::message_type::NONE;
            }
            instruction.candidate_info = parse_candidate_info(j.value("candidate_info", nlohmann::json::object()));
        } catch (const nlohmann::json::parse_error& e) {
			core::logger_service::logger()->error("JSON parse failed: {}", e.what());
        }

        return instruction;
	}
}
