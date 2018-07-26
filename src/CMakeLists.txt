set(spotlight_provider_SRCS
    spotlightprovider.cpp
)

add_library(spotlightprovider_static STATIC ${spotlight_provider_SRCS})
target_link_libraries(spotlightprovider_static
    Plasma::PotdProvider
    KF5::KIOCore
    Qt5::Gui
    Qt5::Core
)

add_library(plasma_potd_spotlightprovider MODULE spotlightprovider_plugin.cpp)
target_link_libraries(plasma_potd_spotlightprovider
    spotlightprovider_static
)

install(TARGETS plasma_potd_spotlightprovider DESTINATION ${KDE_INSTALL_PLUGINDIR}/potd)
