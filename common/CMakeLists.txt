set(GAMMARAY_UTIL_SRCS
  # TODO: Put these in a private section?
  ../3rdparty/kde/kidentityproxymodel.cpp
  ../3rdparty/kde/krecursivefilterproxymodel.cpp
  ../3rdparty/kde/kfilterproxysearchline.cpp
  ../3rdparty/qt/resourcemodel.cpp

  util.cpp
  singlecolumnobjectproxymodel.cpp
)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
)

qt4_automoc(${GAMMARAY_UTIL_SRCS})
add_library(gammaray_common SHARED ${GAMMARAY_UTIL_SRCS})

target_link_libraries(gammaray_common
  ${QT_QTCORE_LIBRARIES}
  ${QT_QTGUI_LIBRARIES}
)

# TODO: Implement install directives for headers
install(TARGETS gammaray_common ${INSTALL_TARGETS_DEFAULT_ARGS})
