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
        HeaderFiles/curses.h
        library/Terminal.h
        library/Terminal.cpp
        HeaderFiles/Regra.h
        SourceFiles/Regra.cpp
        HeaderFiles/Temperatura.h
        SourceFiles/Temperatura.cpp
        HeaderFiles/Luz.h
        SourceFiles/Luz.cpp
        HeaderFiles/Radiacao.h
        SourceFiles/Radiacao.cpp
        HeaderFiles/Vibracao.h
        SourceFiles/Vibracao.cpp
        HeaderFiles/Humidade.h
        SourceFiles/Humidade.cpp
        HeaderFiles/Fumo.h
        SourceFiles/Fumo.cpp
        HeaderFiles/Som.h
        SourceFiles/Som.cpp
        HeaderFiles/Aquecedor.h
        SourceFiles/Aquecedor.cpp
        HeaderFiles/Aspersor.h
        SourceFiles/Aspersor.cpp
        HeaderFiles/Refrigerador.h
        SourceFiles/Refrigerador.cpp
        HeaderFiles/Lampada.h
        SourceFiles/Lampada.cpp
)
target_link_libraries(${PROJECT_NAME} C:/Users/KevinRodrigues/CLionProjects/PDCurses-3.9/wincon/pdcurses.a)
