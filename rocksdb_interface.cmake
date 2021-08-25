# copied from rocksdb
if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Zi /nologo /EHsc /GS /Gd /GR /GF /fp:precise /Zc:wchar_t /Zc:forScope /errorReport:queue")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /FC /d2Zi+ /W4 /wd4127 /wd4800 /wd4996 /wd4351 /wd4100 /wd4204 /wd4324")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -W -Wextra -Wall -pthread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wsign-compare -Wshadow -Wno-unused-parameter -Wno-unused-variable -Woverloaded-virtual -Wnon-virtual-dtor -Wno-missing-field-initializers -Wno-strict-aliasing")
    if(CMAKE_SYSTEM_PROCESSOR MATCHES "x86_64")
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wstrict-prototypes")
    endif()
    if(MINGW)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-format -fno-asynchronous-unwind-tables")
        add_definitions(-D_POSIX_C_SOURCE=1)
    endif()
    if(NOT CMAKE_BUILD_TYPE STREQUAL "Debug")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer")
        include(CheckCXXCompilerFlag)
        CHECK_CXX_COMPILER_FLAG("-momit-leaf-frame-pointer" HAVE_OMIT_LEAF_FRAME_POINTER)
        if(HAVE_OMIT_LEAF_FRAME_POINTER)
            set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -momit-leaf-frame-pointer")
        endif()
    endif()
endif()

file(GLOB ROCKSDB_INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/env/*.cc
        ${CMAKE_CURRENT_LIST_DIR}/memtable/skiplistrep.cc
        ${CMAKE_CURRENT_LIST_DIR}/table/*.cc
        ${CMAKE_CURRENT_LIST_DIR}/util/*.cc
        ${CMAKE_CURRENT_LIST_DIR}/options/*.cc
        ${CMAKE_CURRENT_LIST_DIR}/port/*.cc
        ${CMAKE_CURRENT_LIST_DIR}/db/**/*.cc)