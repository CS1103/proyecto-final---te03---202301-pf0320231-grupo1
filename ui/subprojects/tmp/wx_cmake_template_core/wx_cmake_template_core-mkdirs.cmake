# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/lucas/utec/progra3/proyecto/ui/src"
  "/home/lucas/utec/progra3/proyecto/ui/subprojects/Build/wx_cmake_template_core"
  "/home/lucas/utec/progra3/proyecto/ui/subprojects/Install/wx_cmake_template_core"
  "/home/lucas/utec/progra3/proyecto/ui/subprojects/tmp/wx_cmake_template_core"
  "/home/lucas/utec/progra3/proyecto/ui/subprojects/Stamp/wx_cmake_template_core"
  "/home/lucas/utec/progra3/proyecto/ui/subprojects/Download/wx_cmake_template_core"
  "/home/lucas/utec/progra3/proyecto/ui/subprojects/Stamp/wx_cmake_template_core"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/lucas/utec/progra3/proyecto/ui/subprojects/Stamp/wx_cmake_template_core/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/lucas/utec/progra3/proyecto/ui/subprojects/Stamp/wx_cmake_template_core${cfgdir}") # cfgdir has leading slash
endif()
