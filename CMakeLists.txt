cmake_minimum_required(VERSION 3.24) # FetchContent is available in 3.11+
project(2CCPP_Project)

set(CMAKE_CXX_STANDARD 17)

######## RAYLIB ########
# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Dependencies
set(RAYLIB_VERSION 4.2.0)
find_package(raylib ${RAYLIB_VERSION} QUIET) # QUIET or REQUIRED
if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)
    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()


################## nlohmann/json ###################
set(JSON_VERSION 3.11.2)
find_package(nlohmann_json ${JSON_VERSION} QUIET)
if (NOT nlohmann_json_FOUND)
    include(FetchContent)

    FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v${JSON_VERSION}/json.tar.xz)
    FetchContent_MakeAvailable(json)
endif ()

# Our Project
add_executable(${PROJECT_NAME} main.cpp
        headers/Board.h
        headers/Game.h
        headers/GameState.h
        headers/GameStates.h
        headers/IState.h
        headers/Player.h
        headers/RaylibWrapper.h

        headers/settings.h
        headers/ThreadHandler.h
        headers/Vec2.h
        headers/Tile.h
        headers/UI/CheckBox.h

        src/Game.cpp
        src/GameStates.cpp
        src/Player.cpp
        src/RaylibWrapper.cpp
        src/ThreadHandler.cpp
        src/Board.cpp
        src/UI/Button.cpp

        src/Tile.cpp

        src/UI/CheckBox.cpp src/UI/NumberChoice.cpp src/Tiles.cpp src/Players.cpp)


set(raylib_VERBOSE 1)


if (WIN32)
target_link_libraries(${PROJECT_NAME} raylib -static) # -static to make the compiler add the missing dll libraries !!
target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
elseif(UNIX)
# Checks if OSX and links appropriate frameworks (Only required on MacOS)
    target_link_libraries(${PROJECT_NAME} raylib) # -static to make the compiler add the missing dll libraries !!
    target_link_libraries(${PROJECT_NAME} nlohmann_json::nlohmann_json)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()

# Web Configurations
#if (${PLATFORM} STREQUAL "Web")
#    # Tell Emscripten to build an example.html file.
#    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
#endif()