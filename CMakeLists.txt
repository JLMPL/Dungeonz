cmake_minimum_required(VERSION 2.8.9)
project(ASS)

set(PROJECT_LINK_LIBS -lSDL2main -lSDL2 -lSDL2_image -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -llua5.2 -lz)
link_directories(/usr/local/lib)

set(FLAGS -g -std=c++14 -Wall)
add_definitions(${FLAGS})

include_directories(src)

file(GLOB src 		"src/*.cpp")
file(GLOB core 	    "src/Core/*.cpp")
file(GLOB resource  "src/Resource/*.cpp")
file(GLOB input 	"src/Input/*.cpp")
file(GLOB render    "src/Render/*.cpp")
file(GLOB gameplay  "src/Gameplay/*.cpp")
file(GLOB ai        "src/Ai/*.cpp")
file(GLOB collision "src/Collision/*.cpp")
file(GLOB gui   	"src/Gui/*.cpp")
file(GLOB base64 	"src/base64/*.cpp")
file(GLOB script 	"src/Script/*.cpp")
file(GLOB state 	"src/GameState/*.cpp")
file(GLOB zip 		"src/zip/*.c")

add_executable(out
    ${src}
    ${core}
    ${resource}
    ${input}
    ${render}
    ${gameplay}
    ${ai}
    ${collision}
	${gui}
	${base64}
	${script}
	${state}
	${zip}
)
target_link_libraries(out ${PROJECT_LINK_LIBS})
