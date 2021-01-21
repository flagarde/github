add_executable(Dumb Dumb.cpp)
install(TARGETS Dumb RUNTIME DESTINATION "bin/tests")
add_test(NAME Dumb COMMAND Dumb)

if(DEFINED ENV{INSTALL_ROOT})
  if($ENV{INSTALL_ROOT} STREQUAL "true")
    message(STATUS "ROOT should be installed. Compiling the ROOT tests")
    add_subdirectory(ROOT)
  endif()
endif()

if(DEFINED ENV{INSTALL_GEANT4})
  if($ENV{INSTALL_GEANT4} STREQUAL "true")
    message(STATUS "Geant4 should be installed. Compiling the Geant4 tests")
    add_subdirectory(Geant4)
  endif()
endif()
  
  
