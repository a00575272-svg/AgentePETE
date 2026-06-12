# Diagrama de clases — AgentePETE

```mermaid
classDiagram
    %% Clases Base de Qt y C++
    class QMainWindow
    class QDialog
    class QObject
    class runtime_error

    %% Interfaz de Calendario
    class calendarWin {
        - Ui::calendarWin* ui
        - QDate currentMonth
        - QVector~QPushButton*~ dayButtons
        - QPushButton* backButton_
        + calendarWin(QWidget* parent)
        + regresarAlChat() void
        - updateCalendar() void
        - on_pushButton_13_clicked() void
        - on_createTaskButton_clicked() void
        - on_nextMonthButton_clicked() void
        - on_previousMonthButton_clicked() void
    }
    QMainWindow <|-- calendarWin

    %% Lógica de Controlador
    class ChatController {
        - OllamaProvider ollamaProvider_
        + ChatController()
        + processPrompt(QString rawPrompt) QString
        + preparePromptForOllama(QString rawPrompt) QString
        - buildSimulatedResponse(Prompt prompt) QString
        - containsKeyword(QString text, QString keyword) bool
        - tryParseAndCreateTask(QString prompt, QString outMessage) bool
    }
    ChatController *-- OllamaProvider

    %% Ventana de Chat Independiente
    class ChatWindow {
        - QLabel* titleLabel
        - QLabel* promptLabel
        - QLabel* modelLabel
        - QLabel* answerLabel
        - QPushButton* sendPromptButton
        - QPushButton* calendarButton
        - QComboBox* modelCombobox
        - QLineEdit* prompLineEdit
        - QTextEdit* modelAnswer
        + ChatWindow(QWidget* parent)
        - sendPrompt() void
    }
    QMainWindow <|-- ChatWindow
    ChatController <|-- ChatWindow

    %% Diálogos
    class DayAgendaDialog {
        - Ui::DayAgendaDialog* ui
        + DayAgendaDialog(QDate date, QWidget* parent)
        + addTaskCard(QString title, QString time, QString description) void
        - on_createTaskButton_clicked() void
        - on_closeButton_clicked() void
    }
    QDialog <|-- DayAgendaDialog

    class NewTaskDialog {
        - Ui::NewTaskDialog* ui
        + NewTaskDialog(QWidget* parent)
        + getTitle() QString
        + getDescription() QString
        + getDateTime() QDateTime
        - on_saveButton_clicked() void
    }
    QDialog <|-- NewTaskDialog

    %% Modelos de Datos
    class DayMonYear {
        + int defaultDay$
        + int day
        + int month
        + int year
        + string titleTask
        + string descriptionTask
        + DayMonYear(int, int, int, string, string)
        + check() bool
        + getTitleTask() string
        + getDescriptionTask() string
        + getDay() int
        + getMonth() int
        + getYear() int
        + setDay(int d) void
        + setMonth(int m) void
        + setYear(int y) void
        # setTitleTask(string title) void
        # setDescriptionTask(string description) void
    }

    class Sender {
        <<enumeration>>
        User
        Assistant
        System
        Error
    }

    class Message {
        - Sender sender_
        - QString content_
        - QString validationError_
        + Message()
        + Message(Sender sender, QString content)
        + sender() Sender
        + content() QString
        + validationError() QString
        + isValid() bool
        + setContent(QString content) bool
        + senderName() QString
        + toDisplayString() QString
        + fromUser(QString content)$ Message
        + fromAssistant(QString content)$ Message
        + system(QString content)$ Message
        + error(QString content)$ Message
        + maxLength()$ int
    }
    Message *-- Sender

    %% Ventana Principal
    class MainWindow {
        - QStackedWidget* stack_
        - QWidget* chatPage_
        - QLabel* titleLabel_
        - QLabel* promptLabel_
        - QLabel* modelLabel_
        - QLabel* answerLabel_
        - QPushButton* sendPromptButton_
        - QComboBox* modelCombobox_
        - QLineEdit* prompLineEdit_
        - QTextEdit* modelAnswer_
        - QPushButton* switchButton_
        - calendarWin* calendarPage_
        + MainWindow(QWidget* parent)
        - sendPrompt() void
        - switchView() void
    }
    QMainWindow <|-- MainWindow
    ChatController <|-- MainWindow
    MainWindow *-- calendarWin

    %% Proveedor de API Local
    class OllamaProvider {
        - QString OLLAMA_URL$
        - QString modelo_
        - QNetworkAccessManager networkManager_
        + OllamaProvider(QObject* parent)
        + enviarMensaje(QString mensaje) QString
        + setModelo(QString modelo) void
        + modelo() QString
    }
    QObject <|-- OllamaProvider

    %% Excepciones Personalizadas
    class PromptVacioException {
        + PromptVacioException()
    }
    runtime_error <|-- PromptVacioException

    class ErrorConexionException {
        + ErrorConexionException(string detalle)
    }
    runtime_error <|-- ErrorConexionException

    class JsonInvalidoException {
        + JsonInvalidoException(string detalle)
    }
    runtime_error <|-- JsonInvalidoException
```

# Justifiación del diseño de clases

1. Separación de Responsabilidades y Desacoplamiento de la IA

    Aislamiento de la infraestructura de red: La clase OllamaProvider se encarga exclusivamente de la comunicación técnica, la configuración del modelo y las peticiones HTTP mediante QNetworkAccessManager. Esto evita que los componentes de la interfaz conozcan los detalles del protocolo de red o el formato de los datos JSON.

    Centralización de la lógica del asistente: ChatController actúa como la capa intermedia de lógica de negocio. Centraliza la preparación de los prompts, la simulación de respuestas y la lógica para detectar si el usuario quiere crear una tarea mediante texto, manteniendo esta funcionalidad independiente de cómo se visualice en la pantalla.

2. Integración de la Interfaz de Usuario mediante Herencia Múltiple

    Controladores integrados en la Vista: Tanto MainWindow como ChatWindow utilizan herencia múltiple, derivando de QMainWindow (para obtener el comportamiento nativo de ventanas de Qt) y de ChatController (para absorber directamente las capacidades de procesamiento de mensajes). Este enfoque simplifica la delegación de eventos, permitiendo que la propia ventana procese los textos ingresados por el usuario sin necesidad de una arquitectura de mediadores más compleja.

    Modularidad y navegación con QStackedWidget: La ventana principal (MainWindow) utiliza un contenedor de vistas apiladas para gestionar la experiencia del usuario. Mantiene la página del chat y el calendario (calendarWin) separados pero integrados firmemente por composición, exponiendo interfaces de navegación limpias mediante señales (regresarAlChat) y botones de intercambio.

3. Gestión Autónoma de Diálogos y Flujos Secundarios

    Descongestionamiento de las ventanas principales: Las operaciones específicas de visualización y edición, como revisar la agenda de un día (DayAgendaDialog) o capturar los datos de una nueva tarea (NewTaskDialog), se delegan a componentes que heredan de QDialog. Al ser autónomos, encapsulan sus propios elementos de UI (Ui::DayAgendaDialog, Ui::NewTaskDialog) y sus métodos de validación, evitando saturar de código a la ventana del calendario principal.

4. Modelado Homogéneo de Datos (Entidades Limpias)

    Abstracción del dominio: Las clases Message y DayMonYear funcionan como contenedores puros de datos (estructuras de datos del dominio).

    Message encapsula de forma segura los tipos de emisores mediante una enumeración (Sender), controlando el tamaño máximo del texto y la validez del contenido de forma aislada.

    DayMonYear almacena la información cronológica y los textos de las tareas, asegurando que las fechas y los atributos del calendario cuenten con métodos de acceso y verificación estandarizados (check()) antes de persistirse o mostrarse.

5. Robustez mediante Excepciones Especializadas

    Control de flujo ante fallos: En lugar de utilizar códigos de retorno numéricos o booleanos ambiguos para alertar sobre fallos en el chat o la IA, el sistema define excepciones explícitas en PeteExceptions.h (PromptVacioException, ErrorConexionException, JsonInvalidoException). Al heredar de std::runtime_error, permiten que las capas superiores (la UI) capturen de manera selectiva los errores de red, de procesamiento o de formato, mejorando la tolerancia a fallos y facilitando el envío de mensajes de alerta claros al usuario final.
