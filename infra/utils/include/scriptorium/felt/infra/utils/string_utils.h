#pragma once

#include <string>

namespace scriptorium::felt::infra::utils {
	std::wstring utf8_to_wstring(std::string_view str);
	std::string get_dict_path();
}
