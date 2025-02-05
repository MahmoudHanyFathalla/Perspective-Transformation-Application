# Image Processing and Perspective Transformation Application

## Overview
This project is a C++ application built using the **Qt framework** and **OpenCV**. It demonstrates how to load images, apply perspective transformations, and display the original and transformed images in a Qt-based GUI. The application is designed to be cross-platform and supports both Qt5 and Qt6.

## Features
- **Image Loading**: Loads images from the local file system using OpenCV.
- **Perspective Transformation**: Applies a perspective transformation to the loaded images using OpenCV.
- **GUI Display**: Displays the original and transformed images in a Qt-based GUI using `QLabel` widgets.
- **Cross-Platform**: Supports both Qt5 and Qt6, making it compatible with multiple platforms.
- **Translation Support**: Includes support for internationalization (i18n) with Qt Linguist.

## Prerequisites
Before building and running the project, ensure you have the following installed:

- **CMake** (version 3.5 or higher)
- **Qt** (version 5 or 6)
- **OpenCV** (version 4.5.2 or higher)
- **C++ Compiler** with C++17 support

## Installation

### 1. Clone the Repository
```bash
git clone https://github.com/yourusername/your-repo-name.git
cd your-repo-name
```

### 2. Install Dependencies
Ensure that Qt and OpenCV are installed on your system. You can install them using your package manager or download them manually.

- **Qt**: Follow the official [Qt installation guide](https://www.qt.io/download).
- **OpenCV**: Download and install from the [official website](https://opencv.org/releases/).

### 3. Configure the Project
Update the paths in the `CMakeLists.txt` file to point to your local installations of OpenCV.

```cmake
# Update this path to match your local OpenCV installation
set(OpenCV_DIR "C:/path/to/opencv/build")
```

### 4. Build the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 5. Run the Application
After building the project, you can run the executable:

```bash
./untitled
```

## Usage
1. **Launch the Application**: Run the executable to start the application.
2. **Load Images**: The application will automatically load images from the specified paths in the code.
3. **View Images**: The original and transformed images will be displayed in the GUI.
4. **Perspective Transformation**: The application applies a perspective transformation to the images and displays the results.

## Project Structure
- **CMakeLists.txt**: CMake configuration file for building the project.
- **main.cpp**: Entry point of the application, initializes the Qt application and sets up translation support.
- **mainwindow.h**: Header file for the `MainWindow` class, containing declarations for the main window and its components.
- **mainwindow.cpp**: Implementation of the `MainWindow` class, including functions for loading images, applying perspective transformations, and displaying images.
- **mainwindow.ui**: Qt Designer UI file defining the layout of the main window.
- **untitled_en_US.ts**: Translation file for English (United States).

## Customization
- **Image Paths**: Modify the image paths in `mainwindow.cpp` to load different images.
- **Perspective Transformation**: Adjust the source and destination points in the `applyPerspectiveTransformation` function to customize the transformation.
- **Translations**: Add more translation files and update the `TS_FILES` variable in `CMakeLists.txt` to support additional languages.

## Troubleshooting
- **Build Errors**: Ensure that all dependencies are correctly installed and the paths in `CMakeLists.txt` are accurate.
- **Runtime Errors**: Check the console output for any error messages related to image loading or OpenCV.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request with your changes.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Acknowledgments
- **Qt**: For providing a powerful framework for building cross-platform applications.
- **OpenCV**: For enabling advanced image processing and computer vision tasks.
