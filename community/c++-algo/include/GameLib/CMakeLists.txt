cmake_minimum_required (VERSION 2.6)
project (GameLib)

set(HEADERS
    src/customExceptions.h
    src/structs.h
    src/enums.h
    src/util.h
    src/util.cpp
    src/algoCore.h
    src/algoCore.cpp
    src/gameState.h
    src/gameState.cpp
    src/gameMap.h
    src/gameMap.cpp
    src/unit.h
    src/unit.cpp
    src/navigation.h
    src/navigation.cpp
)

add_library(GameLib ${HEADERS})

target_include_directories (GameLib PRIVATE ${CMAKE_SOURCE_DIR}/include/)

target_link_libraries(GameLib json11)
