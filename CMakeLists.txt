cmake_minimum_required(VERSION 3.10)
project(CGUI_Project CXX)

# --- Manual Raylib Discovery (more robust if find_package fails) ---

# Specify where Raylib's headers are (e.g., /usr/include/)
# If your raylib.h is in /usr/include/raylib, then use /usr/include/
# If your raylib.h is directly in /usr/include, then use /usr/include/
# Check your system: `locate raylib.h` might help find it.
set(RAYLIB_INCLUDE_DIR "/usr/include/") # Common path for many installations
# OR, if it's directly in /usr/include:
# set(RAYLIB_INCLUDE_DIR "/usr/include")


# Specify where the Raylib library file (.so) is
# This path was hinted at by your original error: /usr/lib/libraylib.so
set(RAYLIB_LIBRARY "/usr/lib/libraylib.so")

# You can add a check to make sure these paths are valid
if (NOT EXISTS "${RAYLIB_INCLUDE_DIR}/raylib.h")
    message(FATAL_ERROR "Could not find raylib.h at ${RAYLIB_INCLUDE_DIR}. Please adjust RAYLIB_INCLUDE_DIR in CMakeLists.txt.")
endif()

if (NOT EXISTS "${RAYLIB_LIBRARY}")
    message(FATAL_ERROR "Could not find libraylib.so at ${RAYLIB_LIBRARY}. Please adjust RAYLIB_LIBRARY in CMakeLists.txt.")
endif()

message(STATUS "Manually set Raylib Includes: ${RAYLIB_INCLUDE_DIR}")
message(STATUS "Manually set Raylib Library: ${RAYLIB_LIBRARY}")

# --- End Manual Raylib Discovery ---

# Add your executable
add_executable(cgui_example main.cpp cgui.h)

# Link Raylib libraries
# We use the variable we set manually
target_link_libraries(cgui_example PRIVATE ${RAYLIB_LIBRARY})

# Add Raylib include directories
# We use the variable we set manually
target_include_directories(cgui_example PRIVATE ${RAYLIB_INCLUDE_DIR})

# Add the current source directory to include paths so main.cpp can find cgui.h
target_include_directories(cgui_example PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
