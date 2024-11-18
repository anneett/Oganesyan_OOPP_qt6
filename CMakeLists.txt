cmake_minimum_required(VERSION 3.16)

project(oganesyan_OOPP_qt6 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_ROOT "C:/Users/egiaz/Documents/oganesyan_oopp_qt/boost_1_86_0")

# include_directories(C:/Users/egiaz/Documents/oganesyan_oopp_qt/boost_1_86_0)
# set(BOOST_LIBRARYDIR "C:/Users/egiaz/Documents/oganesyan_oopp_qt/boost_1_86_0/stage/lib")
set(Boost_USE_STATIC_LIBS ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
#find_package(Boost 1.86 REQUIRED COMPONENTS serialization)
find_package(Boost 1.86)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
endif()

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(oganesyan_OOPP_qt6
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Book.h
        EBook.h
        Boost.h
        WidgetOganesyan.h
        WidgetOganesyan.cpp
        Book.cpp
        EBook.cpp
        EditDialog.ui
        EditDialog.h
        EditDialog.cpp
        EditBook.ui
        EditBook.h
        EditBook.cpp
        AddBook.ui
        AddBook.h
        AddBook.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET oganesyan_OOPP_qt6 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(oganesyan_OOPP_qt6 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(oganesyan_OOPP_qt6
            ${PROJECT_SOURCES}
        )
    endif()
endif()

#target_link_libraries(oganesyan_OOPP_qt6 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets ${Boost_LIBRARIES})
target_link_libraries(oganesyan_OOPP_qt6 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.oganesyan_OOPP_qt6)
endif()
set_target_properties(oganesyan_OOPP_qt6 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS oganesyan_OOPP_qt6
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(oganesyan_OOPP_qt6)
endif()
