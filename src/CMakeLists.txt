rock_library(sdf_parser
    SOURCES Dummy.cpp
    HEADERS Dummy.hpp)

rock_executable(sdf_parser_bin Main.cpp
    DEPS sdf_parser)

