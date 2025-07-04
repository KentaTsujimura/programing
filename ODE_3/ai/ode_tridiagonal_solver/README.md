# ODE Tridiagonal Solver

This project implements a numerical solver for the second-order ordinary differential equation \( y'' = -y \) using a tridiagonal matrix algorithm. The solution is computed with specified boundary conditions.

## Project Structure

- `src/main.cpp`: Entry point of the application. It creates an instance of the `TridiagonalSolver` class, computes the solution, and outputs the results.
- `src/tridiagonal_solver.hpp`: Header file for the `TridiagonalSolver` class, which includes method declarations for setting boundary conditions, solving the equation, and retrieving the solution.
- `src/tridiagonal_solver.cpp`: Implementation file for the `TridiagonalSolver` class. The `solve` method utilizes a tridiagonal matrix to compute the solution to the differential equation.
- `CMakeLists.txt`: CMake configuration file that defines the build settings and dependencies for the project.

## Usage

1. Clone the repository or download the source code.
2. Navigate to the project directory.
3. Build the project using CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```
4. Run the application:
   ```bash
   ./your_executable_name
   ```

## Dependencies

- C++11 or later
- CMake

## License

This project is licensed under the MIT License. See the LICENSE file for more details.