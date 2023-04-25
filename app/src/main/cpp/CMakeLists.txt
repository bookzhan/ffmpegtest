# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.18.1)

# Declares and names the project.

project("ffmpegtest")

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

add_library( # Sets the name of the library.
        ffmpegtest

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        common/BZLogUtil.cpp
        common/ffmpeg_base_info.cpp
        native-lib.cpp)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

#configure_file(${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libbzffmpeg.so ${CMAKE_CACHEFILE_DIR}/libbzffmpeg.so COPYONLY)

add_library(bzffmpeg-lib
        SHARED
        IMPORTED)
set_target_properties(bzffmpeg-lib
        PROPERTIES IMPORTED_LOCATION
        libbzffmpeg.so)

find_library(m-lib m)
find_library(z-lib z)
find_library(android-lib android)

include_directories(
        ./
        ./include
        ./include/${ANDROID_ABI}
        ./common
        ./bean
        ./cmdutilt
        ./include
        ./utils
        ./permission
        ./include/libavcodec
        ./include/libavdevice
        ./include/libavfilter
        ./include/libavformat
        ./include/libavutil
        ./include/libpostproc
        ./include/libswresample
        ./include/libswscale
        ./include/libyuv
        ./include/soundtouch
)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        ffmpegtest

        # Links the target library to the log library
        # included in the NDK.
        ${android-lib} ${m-lib} ${z-lib} bzffmpeg-lib ${log-lib})