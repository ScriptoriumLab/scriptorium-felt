#define SCRIPTORIUM_LOGGER_EXPORTS

#include "scriptorium/felt/core/logger/logger_service.h"
#include "scriptorium/felt/core/logger/console_logger.h"

namespace scriptorium::felt::core {
    static constexpr auto ascii_scriptorium_ime = R"(
        ================================================================================================================================================

        █████████                      ███             █████                        ███                                █████                 █████    
        ███▒▒▒▒▒███                    ▒▒▒             ▒▒███                        ▒▒▒                                ▒▒███                 ▒▒███     
        ▒███    ▒▒▒   ██████  ████████  ████  ████████  ███████    ██████  ████████  ████  █████ ████ █████████████      ▒███         ██████   ▒███████ 
        ▒▒█████████  ███▒▒███▒▒███▒▒███▒▒███ ▒▒███▒▒███▒▒▒███▒    ███▒▒███▒▒███▒▒███▒▒███ ▒▒███ ▒███ ▒▒███▒▒███▒▒███     ▒███        ▒▒▒▒▒███  ▒███▒▒███
        ▒▒▒▒▒▒▒▒███▒███ ▒▒▒  ▒███ ▒▒▒  ▒███  ▒███ ▒███  ▒███    ▒███ ▒███ ▒███ ▒▒▒  ▒███  ▒███ ▒███  ▒███ ▒███ ▒███     ▒███         ███████  ▒███ ▒███
        ███    ▒███▒███  ███ ▒███      ▒███  ▒███ ▒███  ▒███ ███▒███ ▒███ ▒███      ▒███  ▒███ ▒███  ▒███ ▒███ ▒███     ▒███      █ ███▒▒███  ▒███ ▒███
        ▒▒█████████ ▒▒██████  █████     █████ ▒███████   ▒▒█████ ▒▒██████  █████     █████ ▒▒████████ █████▒███ █████    ███████████▒▒████████ ████████ 
        ▒▒▒▒▒▒▒▒▒   ▒▒▒▒▒▒  ▒▒▒▒▒     ▒▒▒▒▒  ▒███▒▒▒     ▒▒▒▒▒   ▒▒▒▒▒▒  ▒▒▒▒▒     ▒▒▒▒▒   ▒▒▒▒▒▒▒▒ ▒▒▒▒▒ ▒▒▒ ▒▒▒▒▒    ▒▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒▒▒ ▒▒▒▒▒▒▒▒  
                                            ▒███                                                                                                      
                                            █████                                                                                                     
                                            ▒▒▒▒▒                                                                                                      

        ================================================================================================================================================
    )";

    std::shared_ptr<base_logger> logger_service::instance = std::make_shared<console_logger>();
    std::mutex logger_service::mutex_;
    std::atomic<int> update_logger_times{0};

    void logger_service::print_logo() {
        logger()->info(ascii_scriptorium_ime);
    }

    std::shared_ptr<base_logger> logger_service::logger() {
        std::lock_guard lock(mutex_);
        if (!instance) {
            static auto fallback = std::make_shared<console_logger>();
            return fallback;
        }
        return instance;
    }

    void logger_service::shutdown() {
        std::lock_guard lock(mutex_);
        if (instance) {
            instance->info("Logger service shutting down...");

            instance.reset();
        }

        update_logger_times.store(0);
    }
}
