add_executable(
    cminusfc
    main.cpp
    cminusf_builder.cpp
)

target_link_libraries(
    cminusfc
    IR_lib
    common
    syntax
    stdc++fs
)

install(
    TARGETS cminusfc
    RUNTIME DESTINATION bin
)
