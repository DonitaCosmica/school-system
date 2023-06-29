# Directorios
BUILD_DIR = build
SRC_DIR = src

# Archivos fuente
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
SRCS += main.cpp

# Archivos objeto
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Nombre del ejecutable
TARGET = app

# Regla principal
$(TARGET): create_build_folder $(OBJS)
	g++ $(OBJS) -o $(TARGET)

# Regla para compilar los archivos fuente a objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	g++ -c main.cpp -o $(BUILD_DIR)/main.o

# Regla para crear el directorio de compilación
create_build_folder:
	mkdir -p $(BUILD_DIR)

# Regla para limpiar los archivos generados
clean:
	rm -rf $(BUILD_DIR)/*.o $(TARGET)

.PHONY: create_build_folder clean
