# Nombre del proyecto: AgentePETE

Un asistente virtual de escritorio integrado localmente que combina el procesamiento de lenguaje natural (NLP) con la gestión inteligente de un calendario y agenda de tareas. El sistema permite interactuar mediante lenguaje natural para consultar la disponibilidad del usuario, listar obligaciones de fechas específicas y automatizar el registro de actividades pendientes sin comprometer la privacidad de los datos.

---

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

## 🎯 Público Objetivo

Este proyecto está diseñado específicamente para:
* **Entusiastas de la Productividad y la Privacidad:** Usuarios que buscan centralizar la gestión de sus horarios a través de una Inteligencia Artificial, pero que exigen un control absoluto de sus datos personales, evitando soluciones en la nube.
* **Desarrolladores y Tecnólogos:** Profesionales que desean un entorno modular, expandible y autocontenido (Self-Hosted) para experimentar con Modelos de Lenguaje Grandes (LLMs) aplicados a herramientas de automatización de oficina.
* **Usuarios de Entornos Locales:** Personas que operan en infraestructuras con conectividad limitada a internet o que prefieren optimizar los recursos locales de hardware para ejecutar sus propios flujos de trabajo inteligentes.

---

## 🛑 Problema que Resuelve

Las herramientas de asistencia y productividad actuales sufren de dos grandes deficiencias:
1. **Vulnerabilidad de Privacidad y Dependencia de Terceros:** La mayoría de los asistentes inteligentes (como OpenAI, Copilot o Google Gemini) requieren enviar agendas completas, tareas empresariales y rutinas diarias a servidores externos, monetizando o procesando información altamente sensible.
2. **Fricción en la Entrada de Datos:** Los calendarios tradicionales obligan al usuario a rellenar manualmente múltiples formularios, seleccionar selectores de fechas confusos y configurar manualmente descripciones de tareas, interrumpiendo el flujo de concentración.

**Nuestra Solución:** Este proyecto unifica un motor gráfico nativo con un proveedor de IA local (`Ollama`), permitiendo que el procesamiento semántico del lenguaje se ejecute completamente en la máquina del usuario mediante llamadas asíncronas de red interna. De este modo, redactar un prompt simple automatiza el mapeo técnico del calendario, resolviendo la fricción de interfaz de forma totalmente segura y confidencial.

---

## 🛠️ Funcionalidades Mínimas del MVP (Producto Mínimo Viable)

En base a la arquitectura modular provista en el código base, el MVP implementa las siguientes capacidades operativas:

* **Consola de Chat Interactiva:** Panel visual centralizado (`MainWindow` y `ChatWindow`) con un selector dinámico de modelos de IA (`QComboBox`) que permite al usuario interactuar de manera fluida mediante mensajes estructurados (`Message`).
* **Integración Nativa con LLM Local:** Un motor de comunicación asíncrono (`OllamaProvider`) integrado con el framework de red de Qt (`QNetworkAccessManager`), encargado de enviar prompts limpios y recibir respuestas en streaming/JSON desde el servidor local de Ollama.
* **Mapeo Automatizado de Tareas mediante NLP:** El controlador de lógica de negocio (`ChatController`) analiza semánticamente las entradas de texto del usuario a través de un algoritmo de detección de palabras clave e intenciones (`tryParseAndCreateTask`), transformando un mensaje informal en una entidad de datos estructurada.
* **Visualización de Calendario Mensual Avanzada:** Una interfaz gráfica cuadriculada basada en componentes dinámicos (`calendarWin`) que permite navegar de manera interactiva a través de los meses anteriores y posteriores, reflejando el estado temporal del usuario.
* **Agenda Diaria Focalizada:** Un diálogo emergente detallado (`DayAgendaDialog`) encargado de renderizar de forma independiente las actividades asignadas a un día seleccionado, organizándolas mediante tarjetas gráficas con títulos, marcas de tiempo y descripciones pormenorizadas.
* **Formulario de Respaldo Manual:** Una ventana de diálogo complementaria (`NewTaskDialog`) que permite forzar el guardado explícito de una tarea capturando títulos, descripciones y fechas exactas (`QDateTime`), sirviendo como puente de validación ante el procesamiento automatizado de la IA.
* **Tolerancia a Fallos y Capa de Excepciones:** Un subsistema de control de errores tipificado (`PeteExceptions`) que intercepta fallas críticas de red, respuestas JSON corruptas o prompts vacíos, evitando el congelamiento de la interfaz de usuario.

---

## 💻 Tecnologías Utilizadas

El ecosistema del proyecto se fundamenta sobre tecnologías nativas caracterizadas por su alto rendimiento, portabilidad y eficiencia en memoria:

* **Lenguaje de Programación:** C++ (Estándar C++17 o superior), garantizando una ejecución óptima, tipado fuerte y un manejo preciso de los ciclos de vida de los objetos del dominio.
* **Framework Principal (UI y Red):** **Qt Framework (v5 / v6)**, utilizando módulos especializados:
  * `QtWidgets` (Para la arquitectura de ventanas embebidas, diálogos dinámicos y navegación con `QStackedWidget`).
  * `QtNetwork` (`QNetworkAccessManager`, `QNetworkReply` para despachar peticiones HTTP REST de manera asíncrona y no bloqueante).
  * `QtCore` / `QtGui` (Estructuras de datos optimizadas como `QString`, `QVector`, `QDate` y `QDateTime`).
* **Motor de Inteligencia Artificial:** **Ollama API**, configurado localmente en el puerto del sistema operativo para servir modelos generativos compactos y eficientes (ej. *Llama3*, *Mistral*, o *Phi-3*) mediante peticiones estructuradas en formato JSON.
* **Librería Estándar de C++ (STL):** Uso de los módulos `<chrono>` para cálculos de tiempo de alta resolución y `<stdexcept>` para la jerarquía de excepciones seguras de negocio.

---

## 🚀 Implementaciones Futuras (Roadmap de Evolución)

Con el propósito de transformar este MVP en un entorno de producción avanzado, se contemplan las siguientes fases de desarrollo a corto y mediano plazo:

1. **Capa de Persistencia de Datos con SQLite:** Sustituir el almacenamiento temporal actual en memoria (`QVector`, arrays de estructuras) por una base de datos embebida robusta mediante el módulo `QtSql`. Esto asegurará la persistencia a largo plazo de las tareas y permitirá indexar consultas cronológicas eficientemente.
2. **Estructuración Avanzada de Salidas (JSON Controlado):** Migrar el análisis básico de texto por palabras clave en `ChatController` hacia un esquema de **Structured Outputs** forzado en Ollama (ej. mediante formatos JSON Schema obligatorios). Esto permitirá que el LLM devuelva siempre una estructura exacta que contenga `{fecha, hora, titulo, descripcion}` de forma infalible.
3. **Módulo de Notificaciones en Segundo Plano:** Implementar un servicio de fondo (*Daemon/Background Agent*) que lea constantemente la base de datos cronológica y active notificaciones emergentes nativas en el sistema operativo mediante el centro de alertas del sistema (utilizando abstracciones de Qt), avisando al usuario minutos antes de un evento.
4. **Sincronización con Estándares Abiertos (iCalendar):** Desarrollar un motor de importación y exportación de archivos en formato `.ics`, facilitando la interoperabilidad con gestores de calendario globales como Thunderbird, Google Calendar o Apple Calendar de manera desconectada.
5. **Rediseño Estético Completo y Modo Oscuro (QSS):** Implementar hojas de estilo en cascada de Qt (Qt Style Sheets - QSS) para dotar a la aplicación de una interfaz gráfica moderna, minimalista y con soporte nativo para el intercambio dinámico entre Modo Claro y Modo Oscuro, optimizando la experiencia visual diaria.


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
