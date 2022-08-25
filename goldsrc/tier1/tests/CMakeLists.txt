project(ogs-common)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
	PRIVATE RegistryWin.cpp
)

add_executable(ogs-registry-test)

#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} PROJECT_SOURCES)

target_sources(ogs-registry-test
	#PRIVATE ${PROJECT_SOURCES}
	PRIVATE registry_tests.cpp
)

target_link_libraries(ogs-registry-test ogs-common)