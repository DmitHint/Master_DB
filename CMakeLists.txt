cmake_minimum_required(VERSION 3.27)
project(Master_DB C)

set(CMAKE_C_STANDARD 11)

#=======
# Specify paths to source files and header files
set(SOURCE_FILES
        src/modules_db.c
        src/master_modules.c
        src/master_levels.c
        src/master_status_events.c
        src/shared.c
)

set(HEADER_FILES
        include/master_modules.h
        include/master_levels.h
        include/master_status_events.h
        include/shared.h
        include/database.h
        include/libs.h
)
#=======

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
