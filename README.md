# Nombre del proyecto: AgentePETE

## Descripción breve: Crear un asistente personal y personalizado mediante una interfaz interactiva

## Integrantes del equipo: 
- Christian Mojica
- Javier Lopez Fuentes
- Juan Pablo Padilla Ramirez
- Emilio Ceja Castillo
- Alonso Gómez González
- Eugenio Aguilera Nieto
- Victor Manuel Corrales Flores 
- Fernando Hernández Melo

## Asginación de Roles


| No. | Integrante   | Responsabilidad concreta |
|---:|----------|---------------------------|
| 1 | Chris    | Diseñar MainWindow, entrada de prompt, botón de envío y área de respuesta. |
| 2 | Fernando | Implementar ChatController y flujo entre UI, dominio y proveedor de IA. |
| 3 | Alonso   | Crear clases Prompt y Message con validaciones básicas. |
| 4 | Eugenio  | Gestionar historial, Conversation y ConversationStats. |
| 5 | Javier   | Implementar Calendario, día y tareas. |
| 6 | Manolo   | Implementar OllamaProvider con HTTP/JSON usando Qt Network. |
| 7 | JP       | Crear excepciones, validación de prompt vacío, conexión y JSON inválido. |
| 8 | Emilio   | Memoria persistente: archivos de configuración, usuarios, etc. |
|


## Usuario objetivo

Público general

## Problema que resuelve

El desorden y la falta de organización personal al gestionar tareas, actividades y tiempo, dificultando la productividad y el seguimiento de pendientes. 

## Funcionalidades mínimas del MVP:
- Capaz de dar respuestas coherentes a las preguntas, en base a información guardada (como base de datos)
- Interfaz intuitiva.
- Capaz de guardar información de manera local para luego hacer referencia a ella

## Tecnologías a utilizar

- C++
- Qt
- Ollama
- GitHub

## Estado actual del proyecto:

Inicio del proyecto.

## Aporte individual de Alonso

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
