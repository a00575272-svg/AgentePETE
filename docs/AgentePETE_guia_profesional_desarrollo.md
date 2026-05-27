# AgentePETE

## Guía profesional de desarrollo del proyecto integrador

**C++ · Qt · Ollama · Organización personal inteligente**

---

## Índice

<details open>
<summary>Ver secciones del documento</summary>

1. [Bienvenida al reto](#1-bienvenida-al-reto)
2. [Visión del producto](#2-visión-del-producto)
3. [Objetivo general del proyecto](#3-objetivo-general-del-proyecto)
4. [MVP obligatorio](#4-mvp-obligatorio)
5. [Funcionalidades mínimas del MVP](#5-funcionalidades-mínimas-del-mvp)
6. [Extensión profesional: exportación .ics](#6-extensión-profesional-exportación-ics)
7. [Filosofía de trabajo](#7-filosofía-de-trabajo)
8. [Metodología de trabajo](#8-metodología-de-trabajo)
9. [Flujo profesional de trabajo](#9-flujo-profesional-de-trabajo)
10. [Tablero de trabajo](#10-tablero-de-trabajo)
11. [Roles del equipo](#11-roles-del-equipo)
12. [Arquitectura inicial del proyecto](#12-arquitectura-inicial-del-proyecto)
13. [Plan de avance por semanas](#13-plan-de-avance-por-semanas)
14. [Gestión de issues](#14-gestión-de-issues)
15. [Ejemplo de issue bien escrito](#15-ejemplo-de-issue-bien-escrito)
16. [Etiquetas recomendadas en GitHub](#16-etiquetas-recomendadas-en-github)
17. [Reglas de ramas](#17-reglas-de-ramas)
18. [Reglas de commits](#18-reglas-de-commits)
19. [Reglas de Pull Request](#19-reglas-de-pull-request)
20. [Plantilla sugerida de Pull Request](#20-plantilla-sugerida-de-pull-request)
21. [Definition of Done del MVP](#21-definition-of-done-del-mvp)
22. [Definition of Done de la exportación .ics](#22-definition-of-done-de-la-exportación-ics)
23. [Reglas de integración](#23-reglas-de-integración)
24. [Evidencia individual mínima](#24-evidencia-individual-mínima)
25. [Conceptos del curso aplicados en el proyecto](#25-conceptos-del-curso-aplicados-en-el-proyecto)
26. [Criterios de calidad del proyecto](#26-criterios-de-calidad-del-proyecto)
27. [Riesgos comunes y cómo evitarlos](#27-riesgos-comunes-y-cómo-evitarlos)
28. [Ruta estratégica de desarrollo](#28-ruta-estratégica-de-desarrollo)
29. [Lo que NO debe ser AgentePETE](#29-lo-que-no-debe-ser-agentepete)
30. [Lo que SÍ debe ser AgentePETE](#30-lo-que-sí-debe-ser-agentepete)
31. [Entregable final esperado](#31-entregable-final-esperado)
32. [Mensaje final para el equipo](#32-mensaje-final-para-el-equipo)

</details>

---

## 1. Bienvenida al reto

Bienvenidos al desarrollo de AgentePETE, una aplicación que busca resolver un problema real: ayudar a las personas a organizar mejor sus tareas, pendientes y compromisos mediante una interfaz gráfica construida en C++ con Qt, apoyada por inteligencia artificial local usando Ollama.

Este proyecto no será solamente una tarea de programación. Será una experiencia de desarrollo de software en equipo, inspirada en la forma en que trabajan las empresas tecnológicas: con roles, módulos, repositorio compartido, issues, ramas, revisiones de código, integración progresiva y entregas funcionales.

La meta no es que cada integrante haga una parte aislada. La meta es que ocho personas construyan una sola solución bien diseñada, funcional y defendible.

---

## 2. Visión del producto

AgentePETE será un asistente personal de organización de tareas.

La aplicación permitirá que el usuario registre tareas o pendientes en lenguaje natural, los organice en una agenda local, reciba recomendaciones generadas por IA y visualice su carga de trabajo de forma clara.

Además, como extensión profesional, la aplicación podrá exportar las tareas organizadas a un archivo `.ics`, compatible con calendarios externos como Google Calendar, Outlook o Apple Calendar.

---

## 3. Objetivo general del proyecto

Desarrollar una aplicación gráfica en C++ con Qt que aplique conceptos fundamentales de programación orientada a objetos para construir un sistema modular, extensible y robusto de organización personal con apoyo de IA generativa local.

---

## 4. MVP obligatorio

El MVP, o producto mínimo viable, es la primera versión funcional de AgentePETE. No busca incluir todas las ideas posibles, sino demostrar que la solución principal funciona.

El MVP obligatorio será:

> Una aplicación Qt que permita registrar tareas, guardarlas localmente, visualizarlas en una agenda interna y generar recomendaciones básicas de organización usando un proveedor de IA simulado o real mediante Ollama.

---

## 5. Funcionalidades mínimas del MVP

La primera versión de AgentePETE deberá permitir:

- Abrir una interfaz gráfica en Qt.
- Escribir una tarea o pendiente.
- Validar que la entrada no esté vacía.
- Crear un objeto Task.
- Agregar la tarea a una agenda interna.
- Mostrar tareas por fecha o prioridad.
- Guardar las tareas localmente.
- Cargar las tareas al iniciar la aplicación.
- Generar una recomendación de organización usando MockAIProvider u OllamaProvider.
- Mostrar errores de forma clara para el usuario.

---

## 6. Extensión profesional: exportación .ics

Una vez que el MVP funcione, el equipo desarrollará una extensión de valor profesional:

> Exportar las tareas de AgentePETE a un archivo `.ics` para que el usuario pueda importarlas en aplicaciones de calendario externas.

Esta extensión permitirá que el trabajo realizado dentro de AgentePETE pueda trasladarse a herramientas reales de productividad.

La exportación `.ics` no sustituye al calendario interno. Es un puente entre la app y el ecosistema de calendarios externos.

---

## 7. Filosofía de trabajo

Este proyecto se desarrollará como si el equipo fuera una pequeña consultora de software construyendo una solución para un cliente real.

Eso significa que cada integrante deberá:

- Entender el problema.
- Diseñar una solución.
- Escribir código.
- Documentar decisiones.
- Revisar trabajo de otros.
- Integrar su módulo con el sistema completo.
- Explicar técnicamente su contribución.

No se espera perfección desde el primer intento. Se espera avance profesional: construir, probar, corregir, integrar y mejorar.

---

## 8. Metodología de trabajo

El equipo trabajará con una metodología basada en:

> Scrum ligero + Kanban + GitHub Flow

Esto significa:

- El trabajo se dividirá en avances semanales.
- Cada tarea se registrará como issue en GitHub.
- Cada integrante trabajará en ramas propias.
- Los cambios se integrarán mediante Pull Requests.
- Antes de integrar código, otro compañero deberá revisarlo.
- Cada semana deberá existir una versión más completa del producto.

---

## 9. Flujo profesional de trabajo

Cada funcionalidad deberá seguir este flujo:

```text
Idea o necesidad
        ↓
Issue en GitHub
        ↓
Asignación de responsable
        ↓
Rama de trabajo
        ↓
Commits descriptivos
        ↓
Pull Request
        ↓
Revisión de código
        ↓
Corrección si aplica
        ↓
Merge a main
        ↓
Prueba del sistema integrado
```

Este flujo no es burocracia. Es la forma de proteger el proyecto para que el trabajo de todos pueda integrarse sin perder avances.

---

## 10. Tablero de trabajo

El equipo deberá usar un tablero en GitHub Projects con las siguientes columnas:

- Backlog
- Ready
- In Progress
- In Review
- Testing
- Done
- Blocked

### Significado de cada columna

| Columna | Significado |
|---|---|
| Backlog | Ideas o tareas pendientes de priorizar |
| Ready | Tareas listas para trabajar |
| In Progress | Tareas que alguien está desarrollando |
| In Review | Tareas en Pull Request |
| Testing | Tareas que se están probando |
| Done | Tareas terminadas e integradas |
| Blocked | Tareas detenidas por un problema técnico |

---

## 11. Roles del equipo

Cada integrante tendrá un rol híbrido. Esto significa que cada persona tendrá una responsabilidad técnica principal y una responsabilidad ligera de gestión.

Todos los roles incluyen desarrollo de código.

### Rol 1 — Product Owner + Developer de usuario y requisitos

#### Misión

Asegurar que AgentePETE resuelva un problema real para un usuario claro y que el MVP se mantenga enfocado.

#### Código principal

```text
src/domain/UserProfile.h
src/domain/UserProfile.cpp
src/domain/UserGoal.h
src/domain/UserGoal.cpp
```

#### Responsabilidades técnicas

- Crear la clase UserProfile.
- Crear la clase UserGoal.
- Definir preferencias básicas del usuario.
- Implementar al menos un operador útil, por ejemplo operator==.
- Coordinar que el producto tenga sentido desde la perspectiva del usuario.

#### Responsabilidades de gestión

- Mantener docs/product_backlog.md.
- Redactar historias de usuario.
- Definir criterios de aceptación.
- Ayudar a decidir qué entra y qué no entra al MVP.

#### Entregables

- Clases UserProfile y UserGoal.
- Historias de usuario.
- Backlog inicial del producto.
- Criterios de aceptación del MVP y de exportación .ics.

### Rol 2 — Scrum Master + Developer de controladores

#### Misión

Coordinar el avance del equipo y construir los controladores que conectan las partes principales de AgentePETE.

#### Código principal

```text
src/controllers/AppController.h
src/controllers/AppController.cpp
src/controllers/TaskController.h
src/controllers/TaskController.cpp
src/controllers/CalendarController.h
src/controllers/CalendarController.cpp
src/controllers/ExportController.h
src/controllers/ExportController.cpp
```

#### Responsabilidades técnicas

- Crear AppController.
- Crear TaskController.
- Crear CalendarController.
- Crear ExportController.
- Conectar UI, dominio, IA, persistencia y exportación.
- Usar referencias o apuntadores de forma correcta.

#### Responsabilidades de gestión

- Administrar tablero de GitHub Projects.
- Dar seguimiento a issues.
- Detectar bloqueos.
- Coordinar revisiones de Pull Requests.

#### Entregables

- Controladores funcionales.
- Tablero actualizado.
- Bitácora breve de avance semanal.
- Integración entre módulos.

### Rol 3 — Arquitecto POO + Developer de contratos abstractos

#### Misión

Diseñar la estructura orientada a objetos del sistema y definir los contratos que permitirán que AgentePETE sea extensible.

#### Código principal

```text
src/services/AIProvider.h
src/services/StorageProvider.h
src/exporters/CalendarExporter.h
src/formatters/PromptFormatter.h
src/formatters/ResponseFormatter.h
```

#### Responsabilidades técnicas

- Crear clases abstractas.
- Definir métodos virtuales puros.
- Revisar el uso de override.
- Verificar destructores virtuales.
- Diseñar contratos para IA, almacenamiento, formateo y exportación.

#### Responsabilidades de gestión

- Mantener docs/architecture.md.
- Crear y actualizar diagrama de clases.
- Revisar que las contribuciones respeten la arquitectura.

#### Entregables

- Contratos abstractos.
- Diagrama de clases.
- Documento de arquitectura.
- Revisión técnica de PRs relevantes.

### Rol 4 — UI Developer + Developer de calendario visual

#### Misión

Construir la interfaz gráfica de AgentePETE y hacer que la experiencia de usuario sea clara, útil y atractiva.

#### Código principal

```text
src/ui/MainWindow.h
src/ui/MainWindow.cpp
src/ui/MainWindow.ui
src/ui/TaskInputPanel.h
src/ui/TaskInputPanel.cpp
src/ui/CalendarPanel.h
src/ui/CalendarPanel.cpp
src/ui/RecommendationPanel.h
src/ui/RecommendationPanel.cpp
```

#### Responsabilidades técnicas

- Crear la ventana principal.
- Crear el panel para ingresar tareas.
- Crear el panel de calendario.
- Mostrar tareas por fecha.
- Mostrar recomendaciones de IA.
- Agregar botón para exportar .ics.
- Mostrar mensajes de error o éxito.

#### Responsabilidades de gestión

- Mantener docs/ui_wireframe.md.
- Documentar el flujo visual.
- Cuidar que la interfaz sea simple y funcional.

#### Entregables

- Interfaz Qt funcional.
- Calendario visual.
- Panel de tareas.
- Panel de recomendaciones.
- Acción visual de exportar .ics.

### Rol 5 — Domain Developer + Developer de agenda y eventos
### Javier Lopez Fuentes

#### Misión

Construir el corazón del sistema: tareas, agenda, días de calendario y eventos exportables.

#### Código principal

```text
src/domain/Task.h
src/domain/Task.cpp
src/domain/Schedule.h
src/domain/Schedule.cpp
src/domain/CalendarDay.h
src/domain/CalendarDay.cpp
src/domain/CalendarEvent.h
src/domain/CalendarEvent.cpp
src/domain/Priority.h
```

#### Responsabilidades técnicas

- Crear Task.
- Crear Schedule.
- Crear CalendarDay.
- Crear CalendarEvent.
- Implementar ordenamiento por prioridad o fecha.
- Implementar operadores sobrecargados como operator<, operator== u operator<<.
- Usar miembros estáticos para IDs únicos.

#### Responsabilidades de gestión

- Definir reglas del modelo de tareas.
- Coordinarse con UI, persistencia y exportación.
- Garantizar consistencia de los datos del dominio.

#### Entregables

- Modelo de tareas.
- Modelo de agenda.
- Modelo de eventos exportables.
- Sobrecarga de operadores.
- IDs únicos mediante miembros estáticos.

### Rol 6 — AI/Ollama Developer + Developer de recomendaciones

#### Misión

Implementar la capa de inteligencia artificial para generar recomendaciones útiles de organización.

#### Código principal

```text
src/services/MockAIProvider.h
src/services/MockAIProvider.cpp
src/services/OllamaProvider.h
src/services/OllamaProvider.cpp
src/formatters/TaskPromptFormatter.h
src/formatters/TaskPromptFormatter.cpp
src/domain/Recommendation.h
src/domain/Recommendation.cpp
```

#### Responsabilidades técnicas

- Implementar MockAIProvider.
- Implementar la base de OllamaProvider.
- Crear TaskPromptFormatter.
- Crear Recommendation.
- Construir prompts para organizar tareas.
- Procesar respuestas.
- Manejar errores si Ollama no está disponible.

#### Responsabilidades de gestión

- Mantener docs/ollama_integration.md.
- Documentar cómo probar con proveedor simulado y proveedor real.
- Coordinar con QA los casos de error de IA.

#### Entregables

- Proveedor simulado.
- Proveedor Ollama.
- Formateador de prompts.
- Recomendaciones de organización.
- Documento de integración con Ollama.

### Rol 7 — Persistence Developer + Developer de datos locales

#### Misión

Permitir que AgentePETE guarde y recupere datos para que la aplicación tenga continuidad entre sesiones.

#### Código principal

```text
src/services/JsonStorageProvider.h
src/services/JsonStorageProvider.cpp
src/services/LocalStorageService.h
src/services/LocalStorageService.cpp
src/serializers/TaskSerializer.h
src/serializers/TaskSerializer.cpp
src/serializers/CalendarEventSerializer.h
src/serializers/CalendarEventSerializer.cpp
```

#### Responsabilidades técnicas

- Guardar tareas en archivo JSON.
- Cargar tareas al iniciar la app.
- Serializar objetos Task.
- Serializar objetos CalendarEvent.
- Manejar archivo inexistente.
- Manejar errores de lectura y escritura.
- Proveer datos consistentes para exportación .ics.

#### Responsabilidades de gestión

- Mantener docs/data_format.md.
- Documentar el formato del archivo local.
- Coordinar pruebas con QA.

#### Entregables

- Persistencia local.
- Serializadores.
- Archivo JSON de ejemplo.
- Documento de formato de datos.

### Rol 8 — QA Developer + Developer de robustez y exportación .ics

#### Misión

Asegurar que AgentePETE sea confiable y desarrollar la extensión profesional de exportación .ics.

#### Código principal

```text
src/validators/InputValidator.h
src/validators/InputValidator.cpp
src/validators/TaskValidator.h
src/validators/TaskValidator.cpp
src/exceptions/AppException.h
src/exceptions/InvalidTaskException.h
src/exceptions/StorageException.h
src/exceptions/CalendarExportException.h
src/exporters/IcsExporter.h
src/exporters/IcsExporter.cpp
tests/manual_test_plan.md
```

#### Responsabilidades técnicas

- Crear validadores de entrada.
- Crear excepciones personalizadas.
- Implementar IcsExporter.
- Validar fechas y tareas incompletas.
- Probar exportación .ics.
- Probar errores de almacenamiento.
- Verificar que la app no se cierre ante errores comunes.

#### Responsabilidades de gestión

- Mantener tests/manual_test_plan.md.
- Crear checklist de validación.
- Verificar que cada PR incluya evidencia de prueba.

#### Entregables

- Validadores.
- Excepciones personalizadas.
- Exportador .ics.
- Plan de pruebas.
- Evidencia de pruebas.

---

## 12. Arquitectura inicial del proyecto

La estructura sugerida del repositorio será:

```text
AgentePETE/
├── CMakeLists.txt
├── README.md
├── docs/
│   ├── product_backlog.md
│   ├── sprint_log.md
│   ├── architecture.md
│   ├── ui_wireframe.md
│   ├── ollama_integration.md
│   ├── data_format.md
│   ├── ics_export.md
│   └── user_manual.md
│
├── src/
│   ├── main.cpp
│   ├── ui/
│   ├── domain/
│   ├── controllers/
│   ├── services/
│   ├── exporters/
│   ├── formatters/
│   ├── serializers/
│   ├── validators/
│   └── exceptions/
│
└── tests/
    └── manual_test_plan.md
```

---

## 13. Plan de avance por semanas

### Semana 1 — Fundamentos del producto y base del proyecto

#### Objetivo

Convertir la idea de AgentePETE en un proyecto técnico organizado, compilable y con arquitectura inicial.

#### Entregables esperados

- README actualizado.
- MVP definido.
- Usuario objetivo refinado.
- Historias de usuario.
- Boceto de interfaz.
- Proyecto Qt compilable.
- Diagrama inicial de clases.
- Issues creados en GitHub.
- Primeros contratos abstractos.
- Primeras clases de dominio.

#### Resultado esperado

Al final de la semana, el equipo debe poder decir:

> Ya tenemos una visión clara, un repositorio organizado y una base técnica sobre la cual construir.

### Semana 2 — MVP funcional sin IA real

#### Objetivo

Construir una primera versión funcional que permita registrar tareas, mostrarlas en la interfaz y guardarlas localmente.

#### Entregables esperados

- Interfaz Qt inicial.
- Campo para escribir tarea.
- Botón para agregar tarea.
- Clase Task.
- Clase Schedule.
- Controlador de tareas.
- Persistencia básica en JSON.
- Proveedor simulado de IA.
- Validación de entrada vacía.

#### Resultado esperado

Al final de la semana, el equipo debe poder demostrar:

> La app abre, recibe una tarea, la convierte en objeto, la muestra y la guarda.

### Semana 3 — Recomendaciones con IA y agenda interna

#### Objetivo

Integrar la lógica de recomendación mediante MockAIProvider y preparar la conexión con Ollama.

#### Entregables esperados

- AIProvider.
- MockAIProvider.
- Base de OllamaProvider.
- TaskPromptFormatter.
- Clase Recommendation.
- Panel de recomendaciones en la interfaz.
- Manejo de error si Ollama no está disponible.
- Calendario interno funcional.

#### Resultado esperado

Al final de la semana, el equipo debe poder demostrar:

> La app no solo guarda tareas, también genera una recomendación de organización.

### Semana 4 — Exportación .ics y robustez

#### Objetivo

Agregar la extensión profesional de exportación a calendario y fortalecer el manejo de errores.

#### Entregables esperados

- Clase CalendarEvent.
- Clase abstracta CalendarExporter.
- Clase IcsExporter.
- ExportController.
- Botón de exportación en la interfaz.
- Archivo .ics generado.
- Excepciones personalizadas.
- Plan de pruebas.
- Evidencia de importación o validación del archivo.

#### Resultado esperado

Al final de la semana, el equipo debe poder demostrar:

> AgentePETE puede generar un archivo .ics con tareas exportables a calendarios externos.

### Semana 5 — Integración final y demo profesional

#### Objetivo

Consolidar AgentePETE como una aplicación integrada, demostrable y defendible técnicamente.

#### Entregables esperados

- App integrada.
- README final.
- Manual de usuario.
- Diagrama de clases actualizado.
- Evidencia de ejecución.
- Archivo .ics de ejemplo.
- Plan de pruebas final.
- Demo final.
- Explicación técnica individual por integrante.

#### Resultado esperado

Al final del proyecto, el equipo debe poder decir:

> Construimos una aplicación real en C++/Qt, con arquitectura POO, IA local, persistencia, calendario interno y exportación profesional.

---

## 14. Gestión de issues

Cada tarea debe registrarse como issue.

Un buen issue debe tener:

- Título claro.
- Descripción breve.
- Responsable.
- Criterios de aceptación.
- Módulo afectado.
- Semana objetivo.
- Etiqueta.

---

## 15. Ejemplo de issue bien escrito

**Título:**  
Crear clase Task con ID único y prioridad

**Descripción:**  
Implementar la clase Task para representar una tarea del usuario dentro de AgentePETE.

**Responsable:**  
Rol 5 — Domain Developer

**Criterios de aceptación:**

- [ ] La clase tiene título, descripción, fecha, prioridad y estado.
- [ ] La clase genera un ID único.
- [ ] Se implementa operator< para comparar prioridad o fecha.
- [ ] El código compila.
- [ ] Se incluye ejemplo de uso.
- [ ] Se abre Pull Request para revisión.

**Etiqueta:**  
domain, mvp, poo

---

## 16. Etiquetas recomendadas en GitHub

- mvp
- extension-ics
- ui
- domain
- controller
- ai
- storage
- export
- bug
- documentation
- testing
- blocked
- good-first-issue

---

## 17. Reglas de ramas

Cada integrante debe trabajar en una rama propia por funcionalidad.

Ejemplos:

```text
feature/task-domain-model
feature/ui-calendar-panel
feature/mock-ai-provider
feature/json-storage
feature/ics-exporter
fix/empty-task-validation
docs/update-readme
test/manual-test-plan
```

No se debe trabajar directamente sobre main.

---

## 18. Reglas de commits

Los commits deben explicar qué se hizo.

**Ejemplos correctos:**

```text
Add Task class with priority and unique ID
Implement MockAIProvider for local testing
Create CalendarPanel with selected date view
Add basic JSON storage for tasks
Fix empty task validation
Add ICS exporter skeleton
```

**Ejemplos débiles:**

```text
cambios
avance
cosas
update
ya quedó
```

---

## 19. Reglas de Pull Request

Cada Pull Request debe incluir:

- Qué se implementó.
- Qué archivos se modificaron.
- Cómo se probó.
- Captura de pantalla si aplica.
- Issue relacionado.

---

## 20. Plantilla sugerida de Pull Request

```markdown
## Descripción
Se implementó...

## Issue relacionado
Closes #__

## Archivos principales modificados
- src/...
- docs/...

## Cómo se probó
[ ] Compila correctamente
[ ] Se probó desde la interfaz
[ ] Se probó con datos de ejemplo
[ ] No rompe funcionalidad previa

## Evidencia
Agregar captura, salida esperada o archivo generado si aplica.
```

---

## 21. Definition of Done del MVP

Una funcionalidad del MVP se considera terminada cuando:

- [ ] Tiene issue asociado.
- [ ] Está en una rama propia.
- [ ] Tiene commits descriptivos.
- [ ] El código compila.
- [ ] La funcionalidad puede demostrarse.
- [ ] Fue revisada por otro integrante.
- [ ] No rompe funcionalidades existentes.
- [ ] Está integrada en main.
- [ ] Está documentada si cambia el uso de la app.

---

## 22. Definition of Done de la exportación .ics

La extensión .ics se considera terminada cuando:

- [ ] Existe clase CalendarEvent.
- [ ] Existe clase abstracta CalendarExporter.
- [ ] Existe clase IcsExporter.
- [ ] Existe ExportController.
- [ ] La interfaz tiene botón o acción para exportar.
- [ ] Se genera un archivo .ics.
- [ ] El archivo contiene al menos un evento válido.
- [ ] Se documenta cómo importar el archivo.
- [ ] Se prueba con tareas reales del sistema.
- [ ] Se maneja error si no se puede escribir el archivo.

---

## 23. Reglas de integración

Para evitar que los módulos queden aislados, cada rol debe integrarse con al menos otros dos roles.

| Rol | Debe integrarse con |
|---|---|
| Rol 1 — Product/User | Rol 5, Rol 2 |
| Rol 2 — Controladores | Rol 4, Rol 5, Rol 6, Rol 7, Rol 8 |
| Rol 3 — Arquitectura | Todos |
| Rol 4 — UI | Rol 2, Rol 5, Rol 8 |
| Rol 5 — Dominio | Rol 2, Rol 7, Rol 8 |
| Rol 6 — IA/Ollama | Rol 2, Rol 3, Rol 8 |
| Rol 7 — Persistencia | Rol 5, Rol 2, Rol 8 |
| Rol 8 — QA/ICS | Rol 2, Rol 3, Rol 5, Rol 7 |

---

## 24. Evidencia individual mínima

Cada integrante deberá demostrar:

- [ ] Al menos 2 archivos de código creados o modificados.
- [ ] Al menos 1 clase propia.
- [ ] Al menos 1 issue asignado y cerrado.
- [ ] Al menos 1 Pull Request.
- [ ] Al menos 1 revisión a un Pull Request de otro compañero.
- [ ] Explicación técnica de su contribución.
- [ ] Identificación del concepto POO aplicado.

---

## 25. Conceptos del curso aplicados en el proyecto

| Concepto | Aplicación en AgentePETE |
|---|---|
| Apuntadores | Objetos Qt, controladores, servicios abstractos |
| Sobrecarga de operadores | Comparación de tareas, prioridades, eventos |
| Herencia | Proveedores de IA, exportadores, almacenamiento |
| Polimorfismo | Uso de interfaces como AIProvider, StorageProvider, CalendarExporter |
| Clases abstractas | Contratos para IA, persistencia y exportación |
| Miembros estáticos | IDs únicos de tareas o eventos |
| Excepciones | Errores de entrada, almacenamiento, Ollama y exportación |
| Encapsulamiento | Separación entre atributos y comportamiento de clases |
| Composición | Schedule contiene tareas; controladores usan servicios |

---

## 26. Criterios de calidad del proyecto

Una buena versión de AgentePETE no será la que tenga más funciones, sino la que tenga mejor ingeniería.

Se evaluará positivamente que el proyecto tenga:

- Código organizado.
- Clases con responsabilidades claras.
- Separación entre UI y lógica.
- Uso correcto de POO.
- Manejo de errores.
- Repositorio ordenado.
- README útil.
- Commits descriptivos.
- Issues cerrados.
- Demo funcional.
- Participación de todos los integrantes.

---

## 27. Riesgos comunes y cómo evitarlos

| Riesgo | Cómo evitarlo |
|---|---|
| Que todo quede en MainWindow | Usar controladores y clases de dominio |
| Que solo una persona programe | Asignar módulos de código por rol |
| Que el proyecto no compile | Integrar semanalmente, no al final |
| Que Ollama retrase el avance | Usar primero MockAIProvider |
| Que .ics distraiga del MVP | Implementarlo solo después de agenda local |
| Que GitHub sea solo almacenamiento | Usar issues, ramas y PRs |
| Que la app sea solo un chat | Mantener el foco en tareas y agenda |
| Que no haya evidencia individual | Cada alumno debe tener PRs y commits propios |

---

## 28. Ruta estratégica de desarrollo

La ruta recomendada es:

**Primero:**  
App Qt compilable.

**Después:**  
Registro de tareas.

**Luego:**  
Agenda local.

**Después:**  
Persistencia.

**Luego:**  
Recomendación con IA.

**Después:**  
Exportación .ics.

**Finalmente:**  
Demo profesional.

---

## 29. Lo que NO debe ser AgentePETE

AgentePETE no debe ser solamente:

- Un chat genérico con IA.
- Una ventana bonita sin arquitectura.
- Un conjunto de archivos sin integración.
- Un proyecto donde solo dos personas programen.
- Una app que depende completamente de Ollama para funcionar.
- Una lista de tareas sin diseño orientado a objetos.

---

## 30. Lo que SÍ debe ser AgentePETE

AgentePETE debe aspirar a ser:

- Una aplicación clara y funcional.
- Una solución centrada en el usuario.
- Un proyecto con arquitectura POO.
- Una app Qt bien organizada.
- Una experiencia de colaboración profesional.
- Un sistema que pueda crecer.
- Una demostración real de lo que el equipo aprendió.

---

## 31. Entregable final esperado

Al cierre del proyecto, el equipo deberá entregar:

- Repositorio GitHub completo.
- Código fuente.
- README final.
- Instrucciones de compilación.
- Diagrama de clases.
- Manual breve de usuario.
- Evidencia de ejecución.
- Archivo .ics generado.
- Plan de pruebas.
- Demo final.
- Reflexión técnica individual.

---

## 32. Mensaje final para el equipo

AgentePETE es una oportunidad para construir algo más grande que una tarea de clase. Es una oportunidad para experimentar cómo se desarrolla software en un equipo real: con ideas, decisiones, errores, integración, revisión, mejora y entrega.

El reto no es que cada quien haga “su parte” y se desconecte del resto. El reto es que cada contribución individual se convierta en una pieza de un sistema completo.

Si trabajan con orden, si integran con frecuencia, si se comunican bien y si usan los conceptos de programación orientada a objetos como herramientas de diseño, AgentePETE puede convertirse en una aplicación memorable: una solución útil, técnicamente defendible y con identidad propia.

Construyan poco a poco, pero construyan bien.
