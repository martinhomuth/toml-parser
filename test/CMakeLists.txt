## Build test suite with CuTest

# from http://stackoverflow.com/questions/25199677/how-to-detect-if-current-scope-has-a-parent-in-cmake
get_directory_property(hasParent PARENT_DIRECTORY)

set(test_files
  CuTest.c
  CuTest.h
  ${PROJECT_BINARY_DIR}/AllTests.c
  testmain.c
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
    COMMAND bash ${PROJECT_SOURCE_DIR}/test/make-tests.sh ${PROJECT_SOURCE_DIR}/src/*.c ${PROJECT_SOURCE_DIR}/test/*.c > ${PROJECT_BINARY_DIR}/AllTests.c
    )

  add_test(test ${PROJECT_BINARY_DIR}/run_tests)

  find_program(MEMORYCHECK_COMMAND valgrind)
  set(MEMORYCHECK_COMMAND_OPTIONS --leak-check=full --error-exitcode=1)

  add_test(memory_test ${MEMORYCHECK_COMMAND} ${MEMORYCHECK_COMMAND_OPTIONS} ${PROJECT_BINARY_DIR}/run_tests)
endif()


