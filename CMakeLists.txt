# Configure with [fxsdk build-fx] or [fxsdk build-cg], which provide the
# toolchain file and module path of the fxSDK

cmake_minimum_required(VERSION 3.15)
project(MarioKart)

set(SOURCES
  src/3d.c
  src/buttons.c
  src/debugHud.c
  src/images.c
  src/main.c
  src/maths.c
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
  )

  fxconv_declare_assets(${ASSETS} ${ASSETS_fx} ${ASSETS_cg} WITH_METADATA)

  add_executable(mariokart ${SOURCES} ${ASSETS} ${ASSETS_${FXSDK_PLATFORM}})
  target_compile_options(mariokart PRIVATE -Wall -Wextra -Werror-implicit-function-declaration -Ofast -flto)
  target_link_libraries(mariokart Gint::Gint)

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
  target_compile_options(mariokart PRIVATE -Wall -Wextra -Werror-implicit-function-declaration -O3 -flto)
  target_link_options(mariokart PRIVATE --shell-file=../emscripten.html)
endif()
