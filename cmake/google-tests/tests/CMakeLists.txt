set (PROJECT_TEST_NAME "${PROJECT_NAME}_tests")


find_package (GTest REQUIRED)
include_directories (${GTEST_INCLUDE_DIRS} ${INCLUDE})


file (GLOB source_files "*.cpp")
add_executable (${PROJECT_TEST_NAME} ${source_files})


target_link_libraries (${PROJECT_TEST_NAME} ${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES})


add_test (${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})
