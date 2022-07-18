option(OGS_BUILD_UTILS "Build the engine utils" OFF)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/common
	${CMAKE_CURRENT_SOURCE_DIR}/engine
	${CMAKE_CURRENT_SOURCE_DIR}/public
)

add_subdirectory(mathlib)
add_subdirectory(tier1)

if(OGS_BUILD_UTILS)
	add_subdirectory(utils)
endif()