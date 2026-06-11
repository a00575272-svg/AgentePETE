#pragma once

#include <stdexcept>
#include <string>

class PromptVacioException : public std::runtime_error {
public:
    PromptVacioException()
        : std::runtime_error("El prompt no puede estar vacío.") {}
};

class ErrorConexionException : public std::runtime_error {
public:
    explicit ErrorConexionException(const std::string &detalle)
        : std::runtime_error("No se pudo conectar con Ollama: " + detalle) {}
};

class JsonInvalidoException : public std::runtime_error {
public:
    explicit JsonInvalidoException(const std::string &detalle)
        : std::runtime_error("Respuesta JSON inválida: " + detalle) {}
};
