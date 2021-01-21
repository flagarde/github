find_package(ROOT REQUIRED)

separate_arguments(ROOT_CXX_FLAGS)
separate_arguments(ROOT_EXE_LINKER_FLAGS)
    
list(REMOVE_ITEM ROOT_EXE_LINKER_FLAGS "-rdynamic")
    
add_executable(ROOT ROOT.cpp)
target_link_libraries(ROOT PUBLIC ${ROOT_LIBRARIES})
target_link_options(ROOT PUBLIC ${ROOT_EXE_LINKER_FLAGS})
target_include_directories(ROOT PUBLIC ${ROOT_INCLUDE_DIRS})
target_compile_definitions(ROOT PUBLIC ${ROOT_DEFINITIONS})
target_compile_options(ROOT PUBLIC ${ROOT_CXX_FLAGS})
install(TARGETS ROOT RUNTIME DESTINATION "bin/tests")
add_test(NAME ROOT COMMAND ROOT)
