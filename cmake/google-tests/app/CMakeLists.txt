set (PROJECT_APP_NAME "${PROJECT_NAME}_app")


include_directories (${INCLUDE})


file (GLOB source_files "*.cpp")
add_executable (${PROJECT_APP_NAME} ${source_files})


target_link_libraries (${PROJECT_APP_NAME} ${PROJECT_NAME})
