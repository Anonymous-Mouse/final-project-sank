add_library(simpleLibrary
  enemy.cpp
  monster.cpp
)

find_library(M_LIB m)
target_link_libraries(simpleLibrary ${M_LIB})