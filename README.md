# Tutor-Learner System

The **Tutor-Learner System** is a C-based application designed to facilitate interactions between tutors and learners. This project is organized for clarity and ease of compilation.

## Project Structure

```
tutor-learner-system/
├── include/         # Header files (.h)
├── src/             # Source files (.c)
├── README.md        # Project documentation
└── (other files)
```

- **include/**: Contains all header files used by the program.
- **src/**: Contains the C source files for the project.
- **README.md**: This file, containing instructions and project details.

## Compilation

To compile the project, ensure you have `gcc` installed and run the following command from the project root directory:

```bash
gcc src/*.c -Iinclude -o TutorSystem
```

This will create an executable named `TutorSystem` in the project root.

## Execution

After successful compilation, run the program using:

```bash
./TutorSystem
```

## Requirements

- GCC Compiler (e.g., `gcc`)
- Compatible with Unix/Linux systems

## Notes

- Make sure all source files are present in the `src/` directory and all header files are in the `include/` directory before compiling.
- For any additional dependencies or instructions, refer to specific documentation or comments within the code.
