cmake_minimum_required(VERSION 3.6)

project(sort)

include_directories(
	./
)

set(
	Hdrs
		sort.h
)

set(
	Srcs
		main.cpp
		bubble_sort.cpp
		
		
)

source_group("Source FILES" FILES
	${Srcs}
	)

source_group("Header FILES" FILES
	${Hdrs}
	)

add_executable(${PROJECT_NAME} ${Srcs} ${Hdrs})