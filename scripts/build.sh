#!/bin/bash

BINARY_NAME="coursework"

if [ ! -d "build" ]; then
  echo "Створення директорії build..."
  mkdir build || { echo "Не вдалося створити директорію build"; exit 1; }
fi

cd build || { echo "Не вдалося перейти до директорії build"; exit 1; }

echo "Налаштування проекту через CMake..."
cmake .. || { echo "Помилка під час налаштування проекту через CMake"; exit 1; }

echo "Збірка проекту за допомогою CMake..."
cmake --build . || { echo "Помилка під час збірки проекту"; exit 1; }

./Debug/$BINARY_NAME || { echo "Помилка під час запуску $BINARY_NAME"; exit 1; }
