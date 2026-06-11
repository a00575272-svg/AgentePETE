# Aporte individual: Alonso - Prompt y Message

## Responsabilidad asignada

Crear las clases `Prompt` y `Message` con validaciones básicas.

## Qué se implementó

Se agregaron dos clases propias al proyecto:

- `Prompt`: representa la entrada del usuario antes de enviarla al procesamiento.
- `Message`: representa los mensajes que se muestran en el historial de la conversación.

## Clase Prompt

La clase `Prompt` recibe el texto escrito por el usuario, lo normaliza y valida que pueda procesarse correctamente.

Validaciones implementadas:

- Rechaza prompts vacíos.
- Rechaza prompts compuestos solo por espacios.
- Limita el texto a 500 caracteres.
- Guarda un mensaje de error cuando el prompt no es válido.

Además, `Prompt` construye el texto final que puede enviarse a Ollama mediante el método:

```cpp
QString ollamaPrompt() const;
```

Este método toma el prompt limpio del usuario y le agrega instrucciones necesarias para que Ollama responda como AgentePETE.

Ejemplo conceptual:

```text
Eres AgentePETE, un asistente personal de organización...

Solicitud del usuario:
Recordarme estudiar POO mañana

Respuesta esperada:
```

Con esto, la aplicación no manda a Ollama solamente el texto crudo del usuario, sino un prompt preparado con contexto e instrucciones.

## Clase Message

La clase `Message` permite distinguir el tipo de mensaje dentro de la conversación:

- Usuario.
- Asistente.
- Sistema.
- Error.

Validaciones implementadas:

- Rechaza mensajes vacíos.
- Limita los mensajes a 2000 caracteres.
- Da formato a los mensajes para mostrarlos en pantalla.

## Integración con la aplicación

`MainWindow` toma el texto de la interfaz, crea un `Prompt` y muestra el resultado usando objetos `Message`.

`ChatController` usa `Prompt` para validar la entrada y preparar el texto que se podría pasar al proveedor de IA mediante:

```cpp
prompt.ollamaPrompt();
```

Mientras la conexión real con Ollama no esté lista, el sistema conserva una respuesta simulada para que el prototipo siga siendo funcional.

## Conceptos de POO aplicados

- Encapsulamiento: las validaciones están dentro de las clases `Prompt` y `Message`.
- Separación de responsabilidades: la interfaz no valida manualmente todo el texto.
- Abstracción: `Prompt` representa la solicitud del usuario y `Message` representa cada mensaje del chat.
- Composición: `MainWindow` y `ChatController` usan objetos de estas clases para completar el flujo.
