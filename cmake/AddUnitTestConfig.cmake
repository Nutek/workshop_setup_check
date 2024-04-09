cmake_minimum_required(VERSION 3.20)

enable_testing()

function(add_unit_test TARGET_NAME)
    message("Adding UnitTest: `${TARGET_NAME}`")

    set(options "")
    set(oneValueArgs LABELS)
    set(multiValueArgs FILTERS)
    # Assumptions:
    # - ADD_UNIT_TEST_LABELS - contains string representing label
    # - ADD_UNIT_TEST_UNPARSED_ARGUMENTS - contains list of files considered as sources
    cmake_parse_arguments(ADD_UNIT_TEST "${options}" "${oneValueArgs}"
                        "${multiValueArgs}" ${ARGN} )

    add_executable(${TARGET_NAME})
    target_sources(${TARGET_NAME} PRIVATE ${ADD_UNIT_TEST_UNPARSED_ARGUMENTS})
    target_link_libraries(${TARGET_NAME}
    PUBLIC
        gmock
        gtest_main
    )

    if(NOT DEFINED ADD_UNIT_TEST_FILTERS)
        add_test(NAME ${TARGET_NAME}
            WORKING_DIRECTORY
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
            COMMAND 
                ${TARGET_NAME}
        )
    else()
        foreach(FILTER IN LISTS ADD_UNIT_TEST_FILTERS)
            add_test(NAME ${TARGET_NAME}_${FILTER}
            WORKING_DIRECTORY
                ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
            COMMAND 
                ${TARGET_NAME} --gtest_filter=*${FILTER}*
            )
        endforeach()
    endif()

    if(DEFINED ADD_UNIT_TEST_LABELS)
        set_tests_properties(${TARGET_NAME} PROPERTIES LABELS ${ADD_UNIT_TEST_LABELS})
    endif()
endfunction()
