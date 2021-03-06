
# Declare dependencies
macro (SETUP_TESTCASE_DEPENDENCIES)
  add_dependency_external_projects(glm)
  find_package(GLM REQUIRED)
  target_include_directories(${TARGET_NAME} PUBLIC ${GLM_INCLUDE_DIRS})
  
  add_dependency_external_projects(bullet)
  
  find_package(Bullet REQUIRED)
  target_link_libraries(${TARGET_NAME} ${BULLET_LIBRARIES})

  # perform the system include hack for OS X to ignore warnings
  if (APPLE)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -isystem ${BULLET_INCLUDE_DIRS}")
  else()
    target_include_directories(${TARGET_NAME} SYSTEM PRIVATE ${BULLET_INCLUDE_DIRS})
  endif()
  
  link_hifi_libraries(shared physics)
  copy_dlls_beside_windows_executable()
endmacro ()

setup_hifi_testcase(Script)
