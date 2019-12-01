include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/common
	${CMAKE_CURRENT_SOURCE_DIR}/engine
	${CMAKE_CURRENT_SOURCE_DIR}/public
)

add_subdirectory(mathlib)
add_subdirectory(tier1)