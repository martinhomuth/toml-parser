
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2
  GIT_TAG v2.11.1
  )

if (NOT Catch2_POPULATED)
  FetchContent_Populate(Catch2)

endif()

