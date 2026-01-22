cmake_minimum_required(VERSION 3.17)
project(Keymancer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/lib)

add_executable(Keymancer
    Code/main.cpp

    Code/Remapper/Remapper.cpp
    Code/Input/Input.cpp
    Code/Keyhook/Keyhook.cpp
    Code/Keyhook/Worker.cpp
    Code/Autopress/Autopress.cpp
    Code/Logger/Logger.cpp
)

if(EXISTS "${CMAKE_SOURCE_DIR}/config")
    add_custom_command(TARGET Keymancer POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_SOURCE_DIR}/config"
            "$<TARGET_FILE_DIR:Keymancer>/config"
    )
else()
    message(WARNING "Config directory not found: ${CMAKE_SOURCE_DIR}/config — skipping post-build copy.")
endif()