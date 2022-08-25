project(ogs-tier1)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
	PRIVATE interface.cpp
)

if(WIN32)
	target_sources(${PROJECT_NAME}
		PRIVATE RegistryWin.cpp
	)
else()
	target_sources(${PROJECT_NAME}
		PRIVATE RegistryUnix.cpp
	)
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
	POSITION_INDEPENDENT_CODE ON
)