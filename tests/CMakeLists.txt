add_executable(Dumb Dumb.cpp)
install(TARGETS Dumb RUNTIME DESTINATION "bin/tests")
add_test(NAME Dumb COMMAND Dumb)

if(DEFINED ENV{INSTALL_ROOT})
  if($ENV{INSTALL_ROOT} STREQUAL "true")
    message(STATUS "ROOT should be installed. Compiling the ROOT tests")
    find_package(ROOT REQUIRED)
    
    # Early ROOT does not include the flags required on targets
    add_library(FlagsCXX INTERFACE)
    # ROOT 6.14 and earlier have a spacing bug in the linker flags
    # This is required for ROOT < 6.16
    if(${ROOT_VERSION} VERSION_LESS 6.16)
      string(REPLACE "-L " "-L" ROOT_EXE_LINKER_FLAGS "${ROOT_EXE_LINKER_FLAGS}")
    endif()
    
    # Fix for ROOT_CXX_FLAGS not actually being a CMake list
    separate_arguments(ROOT_CXX_FLAGS)
    set_property(TARGET FlagsCXX APPEND PROPERTY INTERFACE_COMPILE_OPTIONS ${ROOT_CXX_FLAGS})
    
    # This also fixes a bug in the linker flags
    separate_arguments(ROOT_EXE_LINKER_FLAGS)
    set_property(TARGET FlagsCXX APPEND PROPERTY INTERFACE_LINK_LIBRARIES ${ROOT_EXE_LINKER_FLAGS})
    
    # This is required on if there is more than one flag (like on macOS)
    separate_arguments(ROOT_EXE_LINKER_FLAGS)
    add_library(ROOT::FlagsCXX ALIAS FlagsCXX)
    
    add_executable(ROOT ROOT.cpp)
    target_link_libraries(ROOT PUBLIC ${ROOT_LIBRARIES} PUBLIC ${ROOT_EXE_LINKER_FLAGS} PUBLIC ROOT::FlagsCXX)
    install(TARGETS ROOT RUNTIME DESTINATION "bin/tests")
    add_test(NAME ROOT COMMAND ROOT)
  endif()
endif()
