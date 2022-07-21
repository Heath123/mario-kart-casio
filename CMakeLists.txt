# Configure with [fxsdk build-fx] or [fxsdk build-cg], which provide the
# toolchain file and module path of the fxSDK

cmake_minimum_required(VERSION 3.15)
project(MarioKart)

set(SOURCES
  src/3d.c
  src/buttons.c
  src/configurableConstants.c
  src/data.c
  src/debugHud.c
  src/images.c
  src/main.c
  src/maths.c
  src/miniz.c
  src/particles.c
  src/physics.c
  src/sprites.c
  src/state.c
  src/tilemap.c
)

if (DEFINED FXSDK_PLATFORM_LONG)
  set(SOURCES ${SOURCES}
    src/platforms/gint.c
  )

  include(GenerateG1A)
  include(GenerateG3A)
  include(Fxconv)
  find_package(Gint 2.1 REQUIRED)
  find_package(LibProf 2.1 REQUIRED)

  # Shared assets, fx-9860G-only assets and fx-CG-50-only assets
  set(ASSETS
    # ...
  )
  set(ASSETS_fx
    # assets-fx/example.png
  )
  set(ASSETS_cg
    # assets-cg/example.png
    # assets-cg/bg.png

    assets-cg/bg.png
    assets-cg/bush.png
    assets-cg/boost_0.png
    assets-cg/boost_1.png
    assets-cg/boost_2.png
    assets-cg/boost_3.png
    assets-cg/boost_4.png
    # assets-cg/bush.png
    # assets-cg/castle.png
    assets-cg/countdown_0.png
    assets-cg/countdown_1.png
    assets-cg/countdown_2.png
    assets-cg/countdown_3.png
    assets-cg/fire_0.png
    assets-cg/fire_1.png
    assets-cg/fire_2.png
    assets-cg/font_0.png
    assets-cg/font_1.png
    assets-cg/font_10.png
    assets-cg/font_2.png
    assets-cg/font_3.png
    assets-cg/font_4.png
    assets-cg/font_5.png
    assets-cg/font_6.png
    assets-cg/font_7.png
    assets-cg/font_8.png
    assets-cg/font_9.png
    assets-cg/kart_0.png
    assets-cg/kart_1.png
    assets-cg/kart_10.png
    assets-cg/kart_11.png
    assets-cg/kart_12.png
    assets-cg/kart_13.png
    assets-cg/kart_14.png
    assets-cg/kart_15.png
    assets-cg/kart_16.png
    assets-cg/kart_17.png
    assets-cg/kart_18.png
    assets-cg/kart_19.png
    assets-cg/kart_2.png
    assets-cg/kart_20.png
    assets-cg/kart_21.png
    assets-cg/kart_3.png
    assets-cg/kart_4.png
    assets-cg/kart_5.png
    assets-cg/kart_6.png
    assets-cg/kart_7.png
    assets-cg/kart_8.png
    assets-cg/kart_9.png
    assets-cg/lap_0.png
    assets-cg/lap_1.png
    assets-cg/lap_2.png
    assets-cg/loop.png
    assets-cg/shadow1.png
    assets-cg/shadow2.png
    assets-cg/smallboost_0.png
    assets-cg/smallboost_1.png
    assets-cg/smallboost_2.png
    assets-cg/smallboost_3.png
    assets-cg/smallboost_4.png
    assets-cg/smoke_0.png
    assets-cg/smoke_1.png
    assets-cg/smoke_2.png
  )

  fxconv_declare_assets(${ASSETS} ${ASSETS_fx} ${ASSETS_cg} WITH_METADATA)

  add_executable(mariokart ${SOURCES} ${ASSETS} ${ASSETS_${FXSDK_PLATFORM}})
  target_compile_options(mariokart PRIVATE -Wall -Wextra -Werror-implicit-function-declaration -Ofast -flto)
  target_link_libraries(mariokart Gint::Gint)
  target_link_libraries(mariokart LibProf::LibProf)

  if("${FXSDK_PLATFORM_LONG}" STREQUAL fx9860G)
    generate_g1a(TARGET mariokart OUTPUT "MarioKart.g1a"
      NAME "MarioKart" ICON assets-fx/icon.png)
  elseif("${FXSDK_PLATFORM_LONG}" STREQUAL fxCG50)
    generate_g3a(TARGET mariokart OUTPUT "MarioKart.g3a"
      NAME "Mario Kart" ICONS assets-cg/icon-uns.png assets-cg/icon-sel.png)
  endif()

else()
  set(SOURCES ${SOURCES}
    src/platforms/emscripten.c
  )

  set(CMAKE_EXECUTABLE_SUFFIX ".html")
  add_executable(mariokart ${SOURCES})
  target_compile_options(mariokart PRIVATE -Wall -Wextra -Werror=implicit-function-declaration -Werror=incompatible-pointer-types -g)
  target_link_options(mariokart PRIVATE --shell-file=../emscripten.html -g)
endif()
