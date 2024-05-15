# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Moitruong/v5.2.1/esp-idf/components/bootloader/subproject"
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader"
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix"
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix/tmp"
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix/src/bootloader-stamp"
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix/src"
  "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "D:/Nam_3/CE233_NhungKhongDay/Nhung_Project/servo_library/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
