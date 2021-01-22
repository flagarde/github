cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(.github VERSION "0.9.0.0" DESCRIPTION "Folder for default workflows and community health files." HOMEPAGE_URL "https://github.com/flagarde/.github" LANGUAGES CXX)

option(BUILD_TESTS "Build the tests" ON)

file(GLOB WORKFLOWS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/workflow-templates/"  "${CMAKE_CURRENT_SOURCE_DIR}/workflow-templates/*.yml")

foreach(WORKFLOW IN LISTS WORKFLOWS)
  message(STATUS "Add ${WORKFLOW} to the worflows directory")
  file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/workflow-templates/${WORKFLOW}" DESTINATION "${CMAKE_CURRENT_SOURCE_DIR}/.github/workflows")
endforeach()

if(BUILD_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
