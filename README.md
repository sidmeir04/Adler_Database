# Adler Database Frontend

This folder contains the **C++ frontend** for the user database interface. It renders the UI using **Webview** and communicates with the Flask backend API to perform database operations.

## Key Components

- **`.vscode/`**: Some vscode configuration
- **`headers/`**: Contains the header files for the .cpp files
- **`src/`**: Main C++ source files
    - `main.cpp`: Entry point
    - `APIClient.cpp`: Handles API requests
    - `logger.cpp`: Only contains LogToFile() for creating logs
- **`web/`**: HTML, CSS, and JavaScript files for the UI
- **`libraries/`**: Includes dependencies like Webview
- **`CMakeLists.txt`**: Build configuration

## Notes for Developers

- **API URL Configuration**  
    Update `APIClient::url` in `src/APIClient.cpp` to match the backend address (e.g., `http://127.0.0.1`) - Do not include the port

- **Logs**  
    A `logs.txt` file is created in the same directory as the executable. It's useful for debugging C++ side errors.
    Also use LogToFile(const std::string &message) to log errors or anything else

- **UI Editing**  
    Modify the HTML/CSS/JS files in the `web/` folder to update the interface.
    HTML files use bootstrap, imported form the bootstrap folder. They should be mostly treated like stand alone HTML files. To interact with application C++ function can be called by binding them in main.cpp and calling them with window.function()

- **Build Output**  
    Compiled output and `AdlerDatabase.exe` will appear in the `build/` directory after compilation.

 - **Dependencies**
    - C++17+
    - Webview (included in libraries/)
    - CMake 3.16+
    - Compatible C++ compiler

### External Library Documentation

This project uses several external libraries, listed below with their official documentation and usage references:

- **Webview (Cross-platform Web UI library)**  
  GitHub: [https://github.com/webview/webview](https://github.com/webview/webview)  
  Docs: See README for embedding HTML/CSS/JS into native apps  

- **WebView2 (Windows-only modern alternative for Webview)**  
  Microsoft Docs: [https://learn.microsoft.com/en-us/microsoft-edge/webview2/](https://learn.microsoft.com/en-us/microsoft-edge/webview2/)  
  GitHub: [https://github.com/MicrosoftEdge/WebView2Samples](https://github.com/MicrosoftEdge/WebView2Samples)

- **nlohmann::json (C++ JSON library)**  
  GitHub: [https://github.com/nlohmann/json](https://github.com/nlohmann/json)  
  Docs: [https://json.nlohmann.me](https://json.nlohmann.me)