cmake_minimum_required(VERSION 2.6)

execute_process(COMMAND getconf LEVEL1_DCACHE_LINESIZE OUTPUT_VARIABLE CLS)
string(REGEX REPLACE "(\r?\n)+$" "" CLS "${CLS}")
message("L1 dcache linesize is ${CLS}")

set(TESTS	matrix_mult_1 matrix_mult_2 matrix_mult_3)

add_definitions("-DCLS=${CLS}")

foreach(test ${TESTS})
	add_executable(${test}	${test}.c)
	add_executable(${test}_opt	${test}.c)
	add_executable(${test}_nat	${test}.c)

	set_target_properties(${test}_opt	PROPERTIES	COMPILE_FLAGS "-O2")
	set_target_properties(${test}_nat	PROPERTIES	COMPILE_FLAGS "-O2 -march=native")
endforeach(test)
