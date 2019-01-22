cmake_minimum_required(VERSION 3.6)

project(sort)

include_directories(
	./
)

set(
	Main
		main.cpp
)

set(
	Hdrs
		sort.h
)

set(
	Srcs
		bubble_sort.cpp
		insertion_sort.cpp
		shell_sort.cpp
		selection_sort.cpp
		heap_sort.cpp
		merge_sort.cpp
		quick_sort.cpp
		bucket_sort.cpp
		radix_sort.cpp
		table_sort.cpp	
)

source_group("Source FILES" FILES
	${Srcs}
	)

source_group("Header FILES" FILES
	${Hdrs}
	)

source_group("Main" FILES
	${Main}
	)

add_executable(${PROJECT_NAME} ${Main} ${Srcs} ${Hdrs})