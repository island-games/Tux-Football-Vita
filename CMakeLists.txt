## This file is a quick tutorial on writing CMakeLists for targeting the Vita
cmake_minimum_required(VERSION 2.8)

## This includes the Vita toolchain, must go before project definition
# It is a convenience so you do not have to type 
# -DCMAKE_TOOLCHAIN_FILE=$VITASDK/share/vita.toolchain.cmake for cmake. It is 
# highly recommended that you include this block for all projects.
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

## Define project parameters here
# Name of the project
project(TuxFootball)
# This line adds Vita helper macros, must go after project definition in order 
# to build Vita specific artifacts (self/vpk).
include("${VITASDK}/share/vita.cmake" REQUIRED)

## Configuration options for this app
# Display name (under bubble in LiveArea)
set(VITA_APP_NAME "TuxFootball")
# Unique ID must be exactly 9 characters. Recommended: XXXXYYYYY where X = 
# unique string of developer and Y = a unique number for this app
set(VITA_TITLEID  "ISLD00005")
# Optional version string to show in LiveArea's more info screen
set(VITA_VERSION  "01.00")

## Flags and includes for building
# Note that we make sure not to overwrite previous flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g")
# Optional. You can specify more param.sfo flags this way.
set(VITA_MKSFOEX_FLAGS "${VITA_MKSFOEX_FLAGS} -d PARENTAL_LEVEL=1")

# Add any additional include paths here
include_directories(
)

# Add any additional library paths here
# ${CMAKE_CURRENT_BINARY_DIR} lets you use any library currently being built
link_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  
)

## Build and link
# Add all the files needed to compile here
add_executable(TuxFootball
   ##src/controllers.cpp
   ##src/controllers.h
   ##src/main.cpp
   src/gamestates/extratimefirsthalfstate.cpp 
	src/gamestates/extratimehalftimestate.cpp 
	src/gamestates/extratimesecondhalfstate.cpp 
	src/gamestates/extratimestate.cpp 
	src/gamestates/firsthalfstate.cpp 
	src/gamestates/fulltimestate.cpp 
	src/gamestates/halftimestate.cpp 
	src/gamestates/ingamestatebase.cpp 
	src/gamestates/mainmenustate.cpp 
	src/gamestates/matchabortedstate.cpp 
	src/gamestates/matchfinishedstate.cpp 
	src/gamestates/matchstartstate.cpp 
	src/gamestates/menustatebase.cpp 
	src/gamestates/nationalanthemstate.cpp 
	src/gamestates/penaltyshootoutstate.cpp 
	src/gamestates/redefinekeysstate.cpp 
	src/gamestates/secondhalfstate.cpp 
	src/gamestates/videomenustate.cpp 
	src/gamestates/statebase.cpp 
	src/gamestates/extratimefirsthalfstate.h 
	src/gamestates/extratimehalftimestate.h 
	src/gamestates/extratimesecondhalfstate.h 
	src/gamestates/extratimestate.h 
	src/gamestates/firsthalfstate.h 
	src/gamestates/fulltimestate.h 
	src/gamestates/halftimestate.h 
    src/gamestates/ingamestatebase.h 
	src/gamestates/mainmenustate.h 
	src/gamestates/matchabortedstate.h 
	src/gamestates/matchfinishedstate.h 
	src/gamestates/matchstartstate.h 
	src/gamestates/menustatebase.h 
	src/gamestates/nationalanthemstate.h 
	src/gamestates/penaltyshootoutstate.h 
	src/gamestates/redefinekeysstate.h 
	src/gamestates/secondhalfstate.h 
	src/gamestates/statebase.h 
	src/gamestates/videomenustate.h 
	src/logger/logger.h 
	src/logger/logger.cpp 
	src/menu/elements/menubutton.cpp 
	src/menu/elements/menuitem.cpp 
	src/menu/elements/menukeyselect.cpp 
	src/menu/elements/menulabel.cpp 
	src/menu/elements/menuoptionlist.cpp 
	src/menu/elements/menubutton.h 
	src/menu/elements/menuitem.h 
	src/menu/elements/menukeyselect.h 
	src/menu/elements/menulabel.h 
	src/menu/elements/menuoptionlist.h 
	src/menu/mainmenu.cpp 
	src/menu/menu.cpp 
	src/menu/redefinekeysmenu.cpp 
	src/menu/videosettingsmenu.cpp 
	src/menu/mainmenu.h 
	src/menu/menu.h 
	src/menu/redefinekeysmenu.h 
	src/menu/videosettingsmenu.h 
	src/resources/fontmanager.cpp 
	src/resources/fontmanager.h 
	src/resources/soundmanager.cpp 
	src/resources/soundmanager.h 
	src/resources/surfacemanager.cpp 
	src/resources/surfacemanager.h 
	src/resources/resourcemanager.cpp 
	src/resources/resourcemanager.h 
	src/ball.cpp 
	src/body.cpp 
	src/camera.cpp 
	src/controller.cpp 
	src/gameengine.cpp 
	src/graphics.cpp 
	src/main.cpp 
	src/controllers.cpp
	src/controllers.h
	src/matrix.cpp 
	src/pitch.cpp 
	src/player.cpp 
	src/point3d.cpp 
	src/rect.cpp 
	src/segment.cpp 
	src/spriteobject.cpp 
	src/spritesequence.cpp 
	src/team.cpp 
	src/tilemap.cpp 
	src/SFont.c 
	src/ball.h 
	src/body.h 
	src/camera.h 
	src/const.h 
	src/controller.h 
	src/Font.hpp 
	src/gameengine.h 
	src/graphics.h 
	src/matrix.h 
	src/pitch.h 
	src/player.h 
	src/point3d.h 
	src/rect.h 
	src/segment.h 
	src/SFont.h 
	src/spriteobject.h 
	src/spritesequence.h 
	src/team.h 
	src/tilemap.h 
	src/gettext.h
   
   
 
 

)

# Library to link to (drop the -l prefix). This will mostly be stubs.
target_link_libraries(TuxFootball
    vita2d
	SDL_mixer 
	SDL_image
  SDL
  SDL_gfx
  
  webp
  vorbisfile
  vorbis
  flac
  ogg
  mikmod
  SceAppMgr_stub
  SceLibKernel_stub 
  SceDisplay_stub
  SceCtrl_stub
  SceAudio_stub
  SceSysmodule_stub
  SceHid_stub
  SceTouch_stub
  SceGxm_stub
  SceCommonDialog_stub
  m
  ScePower_stub
  SceModulemgrForKernel_stub
  SceModulemgrForDriver_stub
  freetype 
  png 
  jpeg 
  z 
  c 
  pthread
  SceIofilemgr_stub
  SceCtrl_stub 
  ScePgf_stub 
  ScePvf_stub 
  
  # this line is only for demonstration. It's not needed as 
                    # the most common stubs are automatically included.
)

## Create Vita files
vita_create_self(TuxFootball.self TuxFootball)
# The FILE directive lets you add additional files to the VPK, the syntax is 
# FILE src_path dst_path_in_vpk. In this case, we add the LiveArea paths.
vita_create_vpk(TuxFootball.vpk ${VITA_TITLEID} TuxFootball.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
  FILE data data


)
