# Get full relative path from root
file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

# Convert path to a flat target name (slashes to underscores)
string(REPLACE "/" "_" TARGET_NAME ${REL_PATH})

# Add your source file(s) here
add_executable(${TARGET_NAME} TryThis02.cpp) 