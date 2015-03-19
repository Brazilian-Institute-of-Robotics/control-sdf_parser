rock_library(sdf_parser
    SOURCES sdf_parser.cpp
    HEADERS sdf_parser.hpp
    DEPS_PKGCONFIG sdformat)

rock_executable(sdf_parser_bin Main.cpp
    DEPS sdf_parser)

