file(GLOB SRCS *.cpp)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)

add_executable(testList ${SRCS})

target_link_libraries(testList
        avltree
        gtest
        gmock
)

include_directories("..")

install(TARGETS testList DESTINATION bin)
