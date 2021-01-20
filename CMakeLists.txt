cmake_minimum_required(VERSION 3.15.5...3.19.3)

project(.github VERSION "0.9.0.0" DESCRIPTION "Folder for default workflows and community health files." HOMEPAGE_URL "https://github.com/flagarde/.github" LANGUAGES CXX)

option(BUILD_TESTS "Build the tests" ON)

if(BUILD_TESTS)
  include(CTest)
  add_subdirectory(tests)
endif()
