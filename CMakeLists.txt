cmake_minimum_required (VERSION 2.6)

## Project definition

set(project_title "toml-parser")
set(project_description "Tom's Obvious, Minimal Language Parser")
set(project_author "Martin Homuth")
set(project_revised_date "20-02-16")
set(project_version_major 0)
set(project_version_minor 1)
set(project_version_patch 0)
set(project_version ${project_version_major}.${project_version_minor}.${project_version_patch})
set(project_copyright_date "2020")
set(project_copyright "Copyright © ${project_copyright_date} ${project_author}")

project(${project_title})

set(TEST true)

## Submodules

## Project configuration

include_directories(${PROJECT_SOURCE_DIR}/src)
include_directories(${PROJECT_SOURCE_DIR}/test)
include_directories(${PROJECT_BINARY_DIR})

## Macro definitions

## Source files

set(src_files
  src/main.c
  )

set(header_files
  # something
  )

## Build test suite with CuTest

# from http://stackoverflow.com/questions/25199677/how-to-detect-if-current-scope-has-a-parent-in-cmake
get_directory_property(hasParent PARENT_DIRECTORY)

if(hasParent)
  # don't create "run_tests" when we're a sub-project of something else
else()
  set(test_files
    test/CuTest.c
    test/CuTest.h
    ${PROJECT_BINARY_DIR}/AllTests.c
    )

  if(DEFINED TEST)
    add_definitions(-DTEST)

    add_executable(run_tests
      ${test_files}
      ${src_files}
      ${header_files}
      )

    # Process source files to look for tests to run
    add_custom_command(
      OUTPUT ${PROJECT_BINARY_DIR}/AllTests.c
      COMMAND bash ${PROJECT_SOURCE_DIR}/test/make-tests.sh ${PROJECT_SOURCE_DIR}/src/*.c > ${PROJECT_BINARY_DIR}
      )

    enable_testing()

    add_test(test ${PROJECT_BINARY_DIR}/run_tests)

    find_program(MEMORYCHECK_COMMAND valgrind)
    set(MEMORYCHECK_COMMAND_OPTIONS --leak-check=full --error-exitcode=1)

    add_test(memory_test ${MEMORYCHECK_COMMAND} ${MEMORYCHECK_COMMAND_OPTIONS} ${PROJECT_BINARY_DIR}/run_tests)
  endif()

endif()
