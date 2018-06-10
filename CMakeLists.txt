set(BASE_DIR "${PROJECT_SOURCE_DIR}/games/SuperDiscoFighter2000")

set (GAME_INC_DIR "${BASE_DIR}/include" CACHE INTERNAL "")
set (PROJECT_SRC_DIR     "${BASE_DIR}/src")

# Gets the list of files inside the src directory
file(GLOB_RECURSE SOURCES "${PROJECT_SRC_DIR}/*.cpp" "${PROJECT_SRC_DIR}/*.c")

include_directories("${GAME_INC_DIR}")

add_library(SuperDiscoFighter2000 STATIC ${SOURCES})
