cmake_minimum_required(VERSION 3.19)
project(cockroach_poker CXX)

set(CMAKE_CXX_STANDARD 17)

set(QT_VERSION 6)
set(REQUIRED_LIBS Core Widgets)
set(REQUIRED_LIBS_QUALIFIED Qt6::Core Qt6::Widgets)

find_package(Qt${QT_VERSION} COMPONENTS ${REQUIRED_LIBS} REQUIRED)

#set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(TEST_MAIN test/maintest.cpp)

if (NOT WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -pedantic")
endif ()

include_directories(src)
#include_directories(resources)

#########################################################################################
# SET UP / DOWNLOAD NEEDED LIBRARIES
#########################################################################################
find_package(Catch2 QUIET)
if (NOT Catch2_FOUND)
    message("Catch not found, downloading from git.")
    Include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v2.13.6)
    FetchContent_MakeAvailable(Catch2)
endif ()

#find_package(jsoncpp QUIET)
#if (NOT jsoncpp_FOUND)
#    message("jsoncpp not found, downloading from git.")
#    Include(FetchContent)
#    FetchContent_Declare(
#            jsoncpp
#            GIT_REPOSITORY https://github.com/open-source-parsers/jsoncpp.git
#            GIT_TAG 1.9.4)
#
#    FetchContent_MakeAvailable(jsoncpp)
#
#endif ()
#include_directories(${jsoncpp_SOURCE_DIR}/include)
include(CTest)

#########################################################################################
# CARD LIBRARY
#########################################################################################
set(
        CARD_SOURCES
        src/model/cards/card.cpp
        src/model/cards/cardcollection.cpp
        src/model/cards/deck.cpp
        src/model/model.cpp
)

set(
        CARD_TEST_SOURCES
        test/model/cards/cardtest.cpp
        test/model/cards/cardcollectiontest.cpp
)


add_library(
        CARD_LIB
        ${CARD_SOURCES}
)

add_executable(
        card_tests
        ${TEST_MAIN}
        ${CARD_TEST_SOURCES}
)

target_link_libraries(card_tests Catch2 CARD_LIB)
add_test(NAME CardTests COMMAND card_tests)

#########################################################################################
# GAME LIBRARY
#########################################################################################
set(
        GAME_SOURCES
        src/model/game/player.cpp
        src/model/game/game.cpp
        src/model/game/round.cpp
)

set(
        GAME_TEST_SOURCES
        test/model/game/playertest.cpp
)

add_library(
        GAME_LIB
        ${GAME_SOURCES}
)

target_link_libraries(GAME_LIB CARD_LIB)

add_executable(
        game_tests
        ${TEST_MAIN}
        ${GAME_TEST_SOURCES}
)

target_link_libraries(game_tests Catch2 GAME_LIB)
add_test(NAME GameTests COMMAND game_tests)

#########################################################################################
# MODEL LIBRARY
#########################################################################################
set(
        MODEL_SOURCES
        src/model/model.cpp
)


add_library(
        MODEL_LIB
        ${MODEL_SOURCES}
)

target_link_libraries(MODEL_LIB GAME_LIB)

#########################################################################################
# VIEW LIBRARY
#########################################################################################
set(
        RESOURCES
        resources/cards.qrc
)

set(
        VIEW_SOURCES
        src/view/components/card.cpp
        src/view/view.cpp
        ${RESOURCES}
        src/view/components/cardhcollection.cpp src/view/components/cardhcollection.hpp)

add_library(
        VIEW_LIB
        ${VIEW_SOURCES}
)

target_link_libraries(VIEW_LIB ${REQUIRED_LIBS_QUALIFIED})

#########################################################################################
# EXECUTABLES
#########################################################################################
add_executable(${PROJECT_NAME} src/main.cpp ${RESOURCES})


target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED} MODEL_LIB VIEW_LIB)
