# Install script for directory: C:/ncs/v3.4.0/zephyr

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Zephyr-Kernel")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/ncs/toolchains/dcbdc366a1/opt/zephyr-sdk/gnu/arm-zephyr-eabi/bin/arm-zephyr-eabi-objdump.exe")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/arch/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/lib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/soc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/boards/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/subsys/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/drivers/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/nrf/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/mcuboot/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/mbedtls/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/trusted-firmware-m/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/cjson/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/azure-sdk-for-c/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/cirrus-logic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/openthread/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/nrf_wifi/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/memfault-firmware-sdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/hostap/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/canopennode/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/chre/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/cmsis/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/cmsis-dsp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/cmsis-nn/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/cmsis_6/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/dhara/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/fatfs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/hal_nordic/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/hal_st/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/hal_tdk/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/hal_wurthelektronik/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/liblc3/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/libmetal/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/libsbc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/littlefs/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/loramac-node/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/lvgl/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/mipi-sys-t/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/nanopb/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/open-amp/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/percepio/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/picolibc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/segger/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/uoscore-uedhoc/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/zcbor/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/nrfxlib/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/nrf_hw_models/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/modules/connectedhomeip/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/kernel/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/cmake/flash/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/cmake/usage/cmake_install.cmake")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/cmake/reports/cmake_install.cmake")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/msys64/home/aatub/embeddedcodes/embeddedsystemscourse/hw4/build_1/hw4/zephyr/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
