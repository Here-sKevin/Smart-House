cmake_minimum_required(VERSION 3.26)
project(POO_2324)

set(CMAKE_CXX_STANDARD 17)

add_executable(POO_2324 main.cpp
        HeaderFiles/Interface.h
        SourceFiles/Interface.cpp
        HeaderFiles/Habitacao.h
        SourceFiles/Habitacao.cpp
        HeaderFiles/Zona.h
        SourceFiles/Zona.cpp
        HeaderFiles/Sensor.h
        SourceFiles/Sensor.cpp
        HeaderFiles/Processador.h
        SourceFiles/Processador.cpp
        HeaderFiles/Aparelho.h
        SourceFiles/Aparelho.cpp
        HeaderFiles/Propriedade.h
        SourceFiles/Propriedade.cpp
)
