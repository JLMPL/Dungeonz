cmake_minimum_required(VERSION 3.5.0)
project(ASS)

set(PROJECT_LINK_LIBS -lsfml-graphics-d -lsfml-window-d -lsfml-audio-d -lsfml-system-d -llua5.2 -lz)
link_directories(/usr/local/lib)

#-Wfatal-errors -Wall

set(FLAGS -g -std=c++14 -Wfatal-errors)
add_definitions(${FLAGS})

include_directories(src)

file(GLOB src 		"src/*.cpp")
file(GLOB other     "src/*/*.cpp")
#file(GLOB core 	    "src/Core/*.cpp")
#file(GLOB resource  "src/Resource/*.cpp")
#file(GLOB input 	"src/Input/*.cpp")
#file(GLOB render    "src/Render/*.cpp")
#file(GLOB gameplay  "src/Gameplay/*.cpp")
#file(GLOB ai        "src/Ai/*.cpp")
#file(GLOB collision "src/Collision/*.cpp")
#file(GLOB gui   	"src/Gui/*.cpp")
#file(GLOB base64 	"src/base64/*.cpp")
#file(GLOB script 	"src/Script/*.cpp")
#file(GLOB state 	"src/GameState/*.cpp")
#file(GLOB sound     "src/Sound/*.cpp")

add_executable(out
    ${src}
    ${other}
#${core}
#${resource}
#${input}
#${render}
#${gameplay}
#${ai}
#${collision}
#${gui}
#${base64}
#${script}
#${state}
#${sound}
)
target_link_libraries(out ${PROJECT_LINK_LIBS})
