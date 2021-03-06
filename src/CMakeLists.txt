


set( EXCHCXX_SOURCES 
     xc_kernel.cxx 
     xc_functional.cxx 
     libxc.cxx 
     boilerplate.cxx 
     builtin.cxx 
     builtin_interface.cxx 
     builtin_kernel.cxx 
)

add_library( exchcxx STATIC ${EXCHCXX_SOURCES} )

# TARGET properties

target_compile_features( exchcxx PUBLIC cxx_std_14 )
target_link_libraries( exchcxx PUBLIC Libxc::xc )

# Generate exchcxx_config.hpp
configure_file(
  ${PROJECT_SOURCE_DIR}/include/exchcxx/exchcxx_config.hpp.in
  ${PROJECT_BINARY_DIR}/include/exchcxx/exchcxx_config.hpp
)
target_compile_definitions( exchcxx PUBLIC "EXCHCXX_HAS_CONFIG_H=1" )

if( EXCHCXX_ENABLE_DEVICE )

  if( EXCHCXX_ENABLE_CUDA )
    include( cuda/exchcxx_cuda.cmake )
  endif()


#  get_target_property( DEVICE_TARGET_DEPENDS exchcxx_device 
#    INTERFACE_LINK_LIBRARIES ) 
#
#  target_link_libraries( exchcxx PUBLIC 
#    $<TARGET_OBJECTS:exchcxx_device> 
#    ${DEVICE_TARGET_DEPENDS}
#  )

endif()


target_include_directories( exchcxx
  PUBLIC
    $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/include>
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/src>
)

target_compile_options( exchcxx 
  PRIVATE 
    $<$<COMPILE_LANGUAGE:CXX>: -Wall -Wextra -Wpedantic -Wnon-virtual-dtor>
)

# INSTALL rules
add_library( ExchCXX::ExchCXX ALIAS exchcxx )


include( GNUInstallDirs )
set( INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/ExchCXX )

# Targets
install(TARGETS exchcxx
    EXPORT exchcxx-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)


set_target_properties( exchcxx PROPERTIES EXPORT_NAME ExchCXX )

# Install Headers
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.hpp" )
install(DIRECTORY ${PROJECT_BINARY_DIR}/include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.hpp" )

# Export target to script
install(EXPORT exchcxx-targets
  FILE
    ExchCXXTargets.cmake
  NAMESPACE
    ExchCXX::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

# Export build-tree targets also (to be usable by e.g. FetchContent)
export(EXPORT exchcxx-targets
    NAMESPACE ExchCXX::
    FILE "${PROJECT_BINARY_DIR}/ExchCXXTargets.cmake")

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/ExchCXXConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

# Setup ExchCXXConfig.cmake
configure_package_config_file(${PROJECT_SOURCE_DIR}/cmake/ExchCXXConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/ExchCXXConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
#install(DIRECTORY 
#  ${PROJECT_SOURCE_DIR}/cmake/ 
#  DESTINATION ${INSTALL_CONFIGDIR} 
#  FILES_MATCHING PATTERN "*.cmake"
#)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/ExchCXXConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/ExchCXXConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)
