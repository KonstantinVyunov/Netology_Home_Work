# Используем официальный образ Ubuntu как базовый
FROM ubuntu:18.04
# Установка зависимостей
RUN apt-get update && apt-get install -y build-essential cmake
# Создаем директорию для исходного кода
WORKDIR /C++
# Копируем исходный код в контейнер
COPY . /C++
EXPOSE 4000
# Запускаем CMake
RUN cmake . .
# Собираем проект
RUN make
RUN ./zadacha1
# Команда, которая запустит наше приложение
CMD ["./zadacha1"]