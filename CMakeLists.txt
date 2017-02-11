cmake_minimum_required(VERSION 2.8.9)
project(ASS)

set(PROJECT_LINK_LIBS -lSDL2main -lSDL2 -lSDL2_image -lsfml-graphics-d -lsfml-window-d -lsfml-system-d -llua5.2 -lz)
link_directories(/usr/local/lib)

set(FLAGS -g -std=c++14 -Wall)
add_definitions(${FLAGS})

include_directories(src)

file(GLOB src 		"src/*.cpp")
file(GLOB core 	    "src/core/*.cpp")
file(GLOB resource  "src/resource/*.cpp")
file(GLOB input 	"src/input/*.cpp")
file(GLOB render    "src/render/*.cpp")
file(GLOB gameplay  "src/gameplay/*.cpp")
file(GLOB ai        "src/ai/*.cpp")
file(GLOB collision "src/collision/*.cpp")
file(GLOB gui   	"src/gui/*.cpp")
file(GLOB message 	"src/message/*.cpp")
file(GLOB base64 	"src/base64/*.cpp")
file(GLOB script 	"src/script/*.cpp")

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
	${message}
	${base64}
	${script}
)
target_link_libraries(out ${PROJECT_LINK_LIBS})
