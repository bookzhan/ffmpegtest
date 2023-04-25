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

add_library(mp3lame-lib
        STATIC
        IMPORTED)
set_target_properties(mp3lame-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libmp3lame.a)

add_library(x264-lib
        STATIC
        IMPORTED)
set_target_properties(x264-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libx264.a)

add_library(avutil-lib
        STATIC
        IMPORTED)
set_target_properties(avutil-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libavutil.a)

add_library(avcodec-lib
        STATIC
        IMPORTED)
set_target_properties(avcodec-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libavcodec.a)

add_library(avfilter-lib
        STATIC
        IMPORTED)
set_target_properties(avfilter-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libavfilter.a)

add_library(swresample-lib
        STATIC
        IMPORTED)
set_target_properties(swresample-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libswresample.a)

add_library(avformat-lib
        STATIC
        IMPORTED)
set_target_properties(avformat-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libavformat.a)


add_library(swscale-lib
        STATIC
        IMPORTED)
set_target_properties(swscale-lib
        PROPERTIES IMPORTED_LOCATION
        ${CMAKE_HOME_DIRECTORY}/lib/${ANDROID_ABI}/libswscale.a)

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
        ${android-lib} ${m-lib} ${z-lib} mp3lame-lib x264-lib avutil-lib avcodec-lib avfilter-lib swresample-lib avformat-lib swscale-lib ${log-lib})