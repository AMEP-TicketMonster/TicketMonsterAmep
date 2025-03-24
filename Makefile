# Compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Librerías necesarias
LIBS = -lmysqlcppconn

# Directorios
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Archivos fuente necesarios
SRCS = \
    capaDades/conectaDB.cpp \
    capaDades/passarelaUsuari.cpp \
    capaDomini/casosUsuari/src/txConsultaUsuari.cpp \
    capaDomini/dto/usuariDTO.cpp \
    app/ticketMonster.cpp \
    capaPresentacio/capaPresentacio.cpp \
    main.cpp

# Generar objetos en obj/ con la misma estructura de directorios
OBJS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRCS))

# Nombre del ejecutable
TARGET = $(BIN_DIR)/ticketmonster

# Regla principal
all: $(TARGET)

# Compilación del ejecutable
$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

# Regla para compilar archivos .cpp a .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpieza de archivos compilados
clean:
	rm -rf $(BUILD_DIR)
