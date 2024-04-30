# Traffic Intersection Simulation using Multithreading

This C++ program simulates the movement of cars at a traffic intersection using multithreading. The intersection consists of two roads: one with two lanes and the other with four lanes. The input data includes a list of car numbers, their directions, and a list of times when they pass through the intersection.

## Description

The program utilizes multithreading to simulate the movement of cars at the intersection. Each car is represented as a thread, and synchronization mechanisms are used to manage the flow of traffic at the intersection. The simulation provides a realistic depiction of how cars navigate through the intersection based on their directions and arrival times.

## Usage

1. Compile the program using a C++ compiler.
2. Run the compiled executable.
3. Input the list of car numbers, their directions, and the times when they pass through the intersection.
4. Observe the simulation output, which demonstrates the movement of cars at the traffic intersection.

## Inputs

- The user needs to provide the following input data:
  - List of car numbers.
  - Directions for each car.
  - List of times when each car passes through the intersection.

## Implementation Details

- The program uses multithreading to model each car as a separate thread.
- Synchronization mechanisms such as mutexes or semaphores are employed to coordinate the movement of cars at the intersection.
- The simulation may include features such as traffic lights, priority rules, or collision detection to enhance realism.

## Example

Consider a scenario where cars approach the intersection from two roads: Road A (with two lanes) and Road B (with four lanes). The program simulates the movement of these cars based on their directions and arrival times, providing insights into traffic flow dynamics at the intersection.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
