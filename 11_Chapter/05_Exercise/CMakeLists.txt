# Get full relative path from root
file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

# Convert path to a flat target name (slashes to underscores)
string(REPLACE "/" "_" TARGET_NAME ${REL_PATH})

# Get just the last directory name
get_filename_component(DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# Construct source filename: <dir>.cpp
set(SRC_FILE "${DIR_NAME}.cpp")

# Add the executable
add_executable(${TARGET_NAME} ${SRC_FILE})