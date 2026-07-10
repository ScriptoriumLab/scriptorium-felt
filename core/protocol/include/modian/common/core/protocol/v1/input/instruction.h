#pragma once

#include <string>

namespace modian::common::core::protocol::input::v1 {
	enum class message_type {
		NONE = 'N',
		UPDATE = 'U',
		COMMIT = 'C'
	};

    struct candidate_info {
        std::string payload{};
    };

	struct instruction {
		message_type type{message_type::NONE};
	    candidate_info candidate_info;
	};
}
