set(SRCS
    unsplashprovider.cpp
)

add_library(plasma_potd_unsplashprovider MODULE ${SRCS})
target_link_libraries(plasma_potd_unsplashprovider
    Plasma::PotdProvider
    KF5::KIOCore
    Qt5::Gui
    Qt5::Core
)

install(TARGETS plasma_potd_unsplashprovider DESTINATION ${KDE_INSTALL_PLUGINDIR}/potd)
