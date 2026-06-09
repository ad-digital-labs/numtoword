# numtoword

A lightweight command-line utility written in C++ that converts any non-negative integer into its English word representation. It supports the full range of unsigned 64-bit integers, from **1** up to **18,446,744,073,709,551,615** (eighteen quintillion, four hundred forty-six quadrillion...).

---

## Features

- Covers number groups from ones up to **quintillions**
- Accepts input directly from the command line — no configuration required
- Strict input validation with descriptive error messages
- Zero external dependencies — uses only the C++ standard library
- Single-file source, easy to audit and integrate

---

## Requirements

| Platform | Compiler | Minimum Version |
|----------|----------|-----------------|
| Linux | g++ / clang++ | C++11 or later |
| macOS | clang++ (Xcode Command Line Tools) / g++ | C++11 or later |
| Windows | MSVC (Visual Studio), MinGW-w64 (g++), or Clang | C++11 or later |

No third-party libraries or build systems are required. Only a C++11-compliant compiler is needed.

---

## Installation

### Clone the repository

```bash
git clone https://github.com/your-username/numtoword.git
cd numtoword
```

> If Git is not installed, you can also download the source as a ZIP archive from the repository page and extract it manually.

---

## Compilation

### Linux

Install g++ if not already present:

```bash
sudo apt install g++        # Debian / Ubuntu
sudo dnf install gcc-c++    # Fedora / RHEL
sudo pacman -S gcc           # Arch Linux
```

Compile:

```bash
g++ -std=c++11 -o numtoword numtoword.cpp
```

The binary `numtoword` will be placed in the current directory.

---

### macOS

Install the Xcode Command Line Tools if not already present:

```bash
xcode-select --install
```

Compile using clang++ (bundled with Xcode tools):

```bash
clang++ -std=c++11 -o numtoword numtoword.cpp
```

Alternatively, using g++ installed via Homebrew:

```bash
brew install gcc
g++ -std=c++11 -o numtoword numtoword.cpp
```

The binary `numtoword` will be placed in the current directory.

---

### Windows

#### Option 1 — MSVC (Visual Studio)

1. Install [Visual Studio](https://visualstudio.microsoft.com/) with the **Desktop development with C++** workload.
2. Open a **Developer Command Prompt for VS**.
3. Navigate to the project directory and run:

```cmd
cl /EHsc /std:c++11 numtoword.cpp /Fe:numtoword.exe
```

The binary `numtoword.exe` will be placed in the current directory.

#### Option 2 — MinGW-w64 (g++ on Windows)

1. Download and install [MinGW-w64](https://www.mingw-w64.org/) or install it via [MSYS2](https://www.msys2.org/).
2. Open a terminal (MSYS2 shell or a Command Prompt with MinGW on `PATH`) and run:

```cmd
g++ -std=c++11 -o numtoword.exe numtoword.cpp
```

#### Option 3 — Windows Subsystem for Linux (WSL)

If you have WSL installed, follow the Linux instructions above inside your WSL terminal. The binary will run within the WSL environment.

---

## Usage

### Linux / macOS

```bash
./numtoword <number>
```

### Windows

```cmd
numtoword.exe <number>
```

`<number>` must be a positive integer with no spaces, signs, or decimal points.

### Examples

```bash
$ ./numtoword 1
One

$ ./numtoword 42
Fourty Two

$ ./numtoword 1000
One Thousand

$ ./numtoword 1500000
One Million Five Hundred Thousand

$ ./numtoword 1000000000000
One Trillion

$ ./numtoword 18446744073709551615
Eighteen Quintillion Four Hundred Fourty Six Quadrillion ...
```

---

## Error Handling

| Error Message | Cause |
|---|---|
| `ERR: Invalid ARG Input` | No argument supplied, or more than one argument given |
| `ERR: Invalid ARG Input` | Input contains non-numeric characters (letters, symbols, decimals) |
| `ERR: Number out of Range` | Value exceeds the maximum supported range or is zero |

### Exit codes

| Code | Constant | Meaning |
|------|----------|---------|
| `0` | `P_OK` | Conversion successful |
| `-5` | `P_ERR_ARG` | Wrong number of arguments |
| `-10` | `P_ERR_RANGE` | Value out of supported range |
| `-15` | `P_ERR_TYPE` | Non-numeric input detected |

---

## Project Structure

```
numtoword/
├── numtoword.cpp   # Full source — converter logic and CLI entry point
└── README.md       # This file
```

---

## How It Works

The converter breaks the input number into named groups (quintillions, quadrillions, trillions, billions, millions, thousands, and a remainder below 1,000). Each group is processed from largest to smallest, converting the group's value into words using three helper functions that handle ones, tens, and teens independently, then concatenating the results with the appropriate group label.

---

## License

This project is released under the [MIT License](LICENSE).
