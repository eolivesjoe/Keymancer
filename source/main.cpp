#include "remapper/remapper.h"
#include "keyhook/keyhook.h"
#include "keyhook/worker.h"
#include "logger/logger.h"

#include <filesystem>

int main(int argc, char* argv[])
{
    logger::init();

    if (argc < 2) 
    {
        logger::error("No config file specified.");
        return 1;
    }

    std::string configName = argv[1];

    if (!std::filesystem::path(configName).has_parent_path()) 
    {
        configName = std::string("config/") + configName;
    }

    logger::info("Loading config: " + configName);

    remapper::Remapper remapper(configName);

    if (!remapper.load())
    {
        return 1;
    }


    keyhook::KeyHook hook(remapper);
    keyhook::Worker worker;

    worker.start();
    hook.run();
    worker.stop();
    return 0;
}