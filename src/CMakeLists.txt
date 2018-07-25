set(SRCS
    spotlightprovider.cpp
)

add_library(plasma_potd_spotlightprovider MODULE ${SRCS})
target_link_libraries(plasma_potd_spotlightprovider
    Plasma::PotdProvider
    KF5::KIOCore
    Qt5::Gui
    Qt5::Core
)

install(TARGETS plasma_potd_spotlightprovider DESTINATION ${KDE_INSTALL_PLUGINDIR}/potd)
