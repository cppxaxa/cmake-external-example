cmake_minimum_required(VERSION 3.0)
project(test C)
include(ExternalProject)

set(SIPHON "${CMAKE_CURRENT_BINARY_DIR}/siphon")

externalproject_add(siphon_project
	GIT_REPOSITORY git@github.com:imgix/siphon.git
	GIT_TAG 5a5945ee0174e6ed975800e1bcd945a68ba02ff2
	PREFIX "${CMAKE_CURRENT_BINARY_DIR}/siphon_project"
	UPDATE_COMMAND ""
	CMAKE_ARGS
		"-G${CMAKE_GENERATOR}"
		"-DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}"
		"-DCMAKE_INSTALL_PREFIX=${SIPHON}"
)

add_library(siphon STATIC IMPORTED)
set_target_properties(siphon PROPERTIES IMPORTED_LOCATION ${SIPHON}/lib/libsiphon.a)
add_dependencies(siphon siphon_project)

add_executable(example main.c)
include_directories(${SIPHON}/include)
target_link_libraries(example siphon)

