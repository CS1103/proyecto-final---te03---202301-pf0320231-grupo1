# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Source/wxWidgets_external"
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Build/wxWidgets_external"
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Install/wxWidgets_external"
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/tmp/wxWidgets_external"
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Stamp/wxWidgets_external"
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Download/wxWidgets_external"
  "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Stamp/wxWidgets_external"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Stamp/wxWidgets_external/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/lenin.chavez/Documents/Programacion-III/proyecto-final---te03---202301-pf0320231-grupo1/ui/subprojects/Stamp/wxWidgets_external${cfgdir}") # cfgdir has leading slash
endif()
