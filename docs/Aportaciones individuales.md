# Aportaciones individuales

## Aportación Fernando

### `ChatController`: Lógica y Procesamiento

* **Procesamiento de Lenguaje:** Analiza los textos del usuario y detecta intenciones o comandos específicos (como agendar actividades) mediante métodos como `tryParseAndCreateTask`.
* **Gestión de la IA:** Administra la comunicación directa y exclusiva con el motor local a través de `OllamaProvider`, formateando los prompts antes de enviarlos.
* **Desacoplamiento:** Encapsula toda la lógica de negocio, asegurando que el procesamiento de datos opere de forma independiente a la interfaz gráfica.

### `ChatWindow`: Interfaz y Visualización

* **Gestión Visual:** Despliega y controla los componentes gráficos (`QLineEdit`, `QTextEdit`, `QComboBox`) necesarios para chatear, leer respuestas y seleccionar modelos de IA en tiempo real.
* **Integración Directa:** Gracias a la herencia múltiple (`QMainWindow` y `ChatController`), conecta instantáneamente eventos de la interfaz (como `sendPrompt()`) con el motor lógico.
* **Navegación:** Sirve como el panel de interacción principal, incluyendo controles (como `calendarButton`) para transitar fluidamente hacia la vista del calendario.

## Aportación Alonso

Se agregaron las clases `Prompt` y `Message` para validar la entrada del usuario y representar los mensajes de la conversación de forma ordenada.

Archivos agregados:

```text
include/Prompt.h
src/Prompt.cpp
include/Message.h
src/Message.cpp
```

Validaciones básicas implementadas:

- Prompt vacío o con solo espacios.
- Límite de 500 caracteres para prompts.
- Mensajes vacíos.
- Límite de 2000 caracteres para mensajes.

También se integraron estas clases con `MainWindow` y `ChatController` para que la aplicación muestre errores básicos dentro del historial.



## Aporte de Alonso: Prompt y Message

Alonso implementó las clases `Prompt` y `Message`.

`Prompt` se encarga de recibir la entrada del usuario, limpiarla, validar que no esté vacía y limitar su longitud. Además, prepara el texto final que puede enviarse a Ollama mediante `ollamaPrompt()`, agregando instrucciones de sistema para que la respuesta tenga el comportamiento esperado de AgentePETE.

`Message` se encarga de representar los mensajes del historial, distinguiendo mensajes del usuario, del asistente, del sistema y errores.

Esto mejora el diseño orientado a objetos porque separa la validación y el formato de mensajes de la interfaz gráfica.
