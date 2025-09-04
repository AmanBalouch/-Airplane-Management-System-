✈️ Airplane Management System
A C++ project that simulates an Airplane Management System using Graphs and Data Structures.
It allows management of airports, routes, and distances between them, while implementing popular graph traversal and shortest path algorithms.
📌 Features
Store airports and routes between them
Represent graph in:
Adjacency List
Adjacency Matrix
Graph Traversals:
Breadth-First Traversal (BFT)
Depth-First Traversal (DFT)
Shortest Path:
Dijkstra’s Algorithm
Minimum Spanning Tree (MST):
Prim’s Algorithm
Kruskal’s Algorithm
Load graph data dynamically from a CSV file
Interactive menu-based console program
🧮 Algorithms Used
BFT (Breadth-First Traversal) – explores the graph level by level.
DFT (Depth-First Traversal) – explores graph depth-wise using a stack.
Dijkstra’s Algorithm – finds the shortest path from a starting airport.
Prim’s Algorithm – builds MST starting from a given airport.
Kruskal’s Algorithm – builds MST using union-find data structure.
📂 Project Structure
Airplane-Management-System/
│── main.cpp                       # Main C++ source code
│── filtered_routes_with_distances.csv   # CSV file with airport routes & distances
│── README.md                      # Project documentation
⚙️ How to Run
1. Clone the repository
git clone  https://github.com/AmanBalouch/-Airplane-Management-System-.git
cd Airplane-Management-System
2. Compile the program
g++ main.cpp -o airplane
3. Run the program
./airplane
📊 Example Menu
MENU:
1: Display graph
2: Perform Breadth-First Traversal (BFT)
3: Perform Depth-First Traversal (DFT)
4: Apply Dijkstra Algorithm
5: Apply Kruskal's Algorithm
6: Apply Prim's Algorithm
7: Exit
📁 Input Data Format (CSV)
The system reads routes from a CSV file in the following format:
Source,Destination,Distance
Karachi,Lahore,1020
Karachi,Islamabad,1100
Lahore,Multan,340
🖥️ Sample Output
Adjacency List
Karachi ---> (Lahore | 1020 km) (Islamabad | 1100 km) 
Lahore  ---> (Multan | 340 km)
Islamabad ---> 
Multan ---> 
Adjacency Matrix (partial)
          Karachi   Lahore   Islamabad   Multan
Karachi       0      1020      1100       0
Lahore     1020         0         0     340
Islamabad  1100         0         0       0
Multan        0       340         0       0
🚀 Future Improvements
GUI-based airport management
Real-world map integration
Airline ticket booking system
Support for weighted/undirected graphs with multiple routes
🤝 Contributing
Contributions are welcome! Feel free to fork this repo and submit pull requests.
📜 License
This project is licensed under the MIT License – you are free to use, modify, and distribute.
✨ Made with C++ and Graph Algorithms 🚀
