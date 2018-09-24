set(BASE_DIR  "${PROJECT_SOURCE_DIR}/game/engine")
set (LIB_PATH "${PROJECT_SOURCE_DIR}/game/lib")

set (ENGINE_INCLUDE_DIR "${BASE_DIR}/include" CACHE INTERNAL "")
set (PROJECT_SRC_DIR     "${BASE_DIR}/src")

# Gets the list of files inside the src directory
file(GLOB_RECURSE SOURCES "${PROJECT_SRC_DIR}/*.cpp" "${PROJECT_SRC_DIR}/*.c"
                          "${LIB_PATH}/source/*.cpp" "${LIB_PATH}/source/*.c")

include_directories("${ENGINE_INCLUDE_DIR}")
include_directories("${LIB_PATH}/include")

add_library(engine STATIC ${SOURCES})
