#Makefile provisional generado por chatGPT
# Compilador y opciones
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -Iinclude -std=c++11
LDFLAGS = -lmysqlcppconn

# Archivos fuente con rutas explícitas
SRC = main.cpp \
      epicas/usuari.cpp \
      epicas/gestioUsuari/consultarUsuari.cpp \
      epicas/gestioUsuari/eliminarUsuari.cpp \
      epicas/gestioUsuari/iniciarSessio.cpp \
      epicas/gestioUsuari/modificarUsuari.cpp \
      epicas/gestioUsuari/registrarUsuari.cpp \
      pasarelaDB/conectaDB.cpp \
      pasarelaDB/queryUsuari.cpp \
      views/MainWindow.cpp

# Archivos objeto generados a partir de los fuentes
OBJ = $(SRC:.cpp=.o)

# Nombre del ejecutable
TARGET = programa

# Regla principal: compilar el ejecutable
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

# Regla para compilar cada archivo .cpp en un .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar archivos compilados
clean:
	rm -f $(OBJ) $(TARGET)

# Regla para ejecutar el programa
run: all
	./$(TARGET)
