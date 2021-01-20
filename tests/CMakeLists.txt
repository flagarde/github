add_executable(Dumb Dumb.cpp)
install(TARGETS Dumb RUNTIME DESTINATION "bin/tests")

#if($ENV{INSTALL_ROOT} STREQUAL "TRUE")
  message(STATUS "ROOT should be installed. Compiling the ROOT tests")
  find_package(ROOT)
  add_executable(ROOT ROOT.cpp)
  install(TARGETS ROOT RUNTIME DESTINATION "bin/tests")
#endif()
