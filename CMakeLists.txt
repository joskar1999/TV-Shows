cmake_minimum_required(VERSION 3.12)
project(Projekt)

set(CMAKE_CXX_STANDARD 14)

add_executable(Projekt main.cpp Video.cpp Video.h IMDB.cpp IMDB.h Series.cpp Series.h Movie.cpp Movie.h Live.cpp Live.h List.h Collection.h Stats.cpp Stats.h)