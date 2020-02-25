
add_executable(intro main.c)
target_link_libraries(
  intro PRIVATE project_options project_warnings
  )

add_splint(intro main.c)
