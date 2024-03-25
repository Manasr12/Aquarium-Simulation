project(AquariumLib)

set(SOURCE_FILES MainFrame.h MainFrame.cpp pch.h AquariumView.h AquariumView.cpp Aquarium.cpp Aquarium.h Item.cpp Item.h FishBeta.cpp FishBeta.h ids.h CatFish.cpp CatFish.h CarpFish.cpp CarpFish.h DecorCastle.cpp DecorCastle.h Fish.cpp Fish.h)

set(wxBUILD_PRECOMP OFF)
find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)

include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)