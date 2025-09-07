# ✈️ Airplane Management System (C++)

A **C++ project** that simulates an **Airplane Management System** using **Graphs and Data Structures**.  
It allows management of airports, routes, and distances between them, while implementing popular **graph traversal** and **shortest path algorithms**.  

---

## 📌 Features  
- Store **airports** and **routes** between them  
- Represent graph in:  
  - Adjacency List  
  - Adjacency Matrix  
- Graph Traversals:  
  - **Breadth-First Traversal (BFT)**  
  - **Depth-First Traversal (DFT)**  
- Shortest Path:  
  - **Dijkstra’s Algorithm**  
- Minimum Spanning Tree (MST):  
  - **Prim’s Algorithm**  
  - **Kruskal’s Algorithm**  
- Load graph data dynamically from a **CSV file**  
- Interactive **menu-based console program**  

---

## 🧮 Algorithms Used  
- **BFT (Breadth-First Traversal)** → Explores the graph level by level.  
- **DFT (Depth-First Traversal)** → Explores graph depth-wise using a stack.  
- **Dijkstra’s Algorithm** → Finds the shortest path from a starting airport.  
- **Prim’s Algorithm** → Builds MST starting from a given airport.  
- **Kruskal’s Algorithm** → Builds MST using union-find data structure.  

---

## 📂 Project Structure  

Airplane-Management-System/

│── main.cpp # Main C++ source code

│── filtered_routes_with_distances.csv # CSV file with airport routes & distances

│── README.md # Project documentation


---

## ⚙️ How to Run  

1. **Clone the repository**  
   ```bash
   git clone https://github.com/AmanBalouch/-Airplane-Management-System-.git
   cd Airplane-Management-System

2. Compile the program

g++ main.cpp -o airplane

3. Run the program
 ./airplane

📸 Screenshots

🏠 Main Menu

<img width="351" height="142" alt="Screenshot 2025-09-07 at 4 04 24 PM" src="https://github.com/user-attachments/assets/450d3d8f-0d57-49df-ab6f-0c6f9ad949ea" />

📊 Adjacency List Output

<img width="1438" height="898" alt="Screenshot 2025-09-07 at 4 04 49 PM" src="https://github.com/user-attachments/assets/51cd07c1-d455-49e1-a3c6-d67df6352091" />

📊 Adjacency Matrix Output

<img width="429" height="900" alt="Screenshot 2025-09-07 at 4 05 12 PM" src="https://github.com/user-attachments/assets/7b442959-95d2-43fb-9dc3-762b67e5afc7" />

🧮 BFT

<img width="661" height="68" alt="Screenshot 2025-09-07 at 4 05 48 PM" src="https://github.com/user-attachments/assets/ac87deec-b818-4570-9213-bc1b2eecd53f" />

🧮 DFT

<img width="605" height="62" alt="Screenshot 2025-09-07 at 4 06 00 PM" src="https://github.com/user-attachments/assets/9e1b0870-d323-43a0-9dd9-6df959aee49c" />


🧮 Dijkstra Algorithm

<img width="531" height="566" alt="Screenshot 2025-09-07 at 4 06 51 PM" src="https://github.com/user-attachments/assets/d7fea532-a2b2-4034-ae6e-01ae96fdab3b" />

🌲 MST with Prim’s Algorithm

<img width="535" height="802" alt="Screenshot 2025-09-07 at 4 07 26 PM" src="https://github.com/user-attachments/assets/0d9a8ac3-708a-4900-be4a-1a5029b9cb9b" />

🌲 MST with Kruskal’s Algorithm

<img width="574" height="844" alt="Screenshot 2025-09-07 at 4 07 12 PM" src="https://github.com/user-attachments/assets/49d05672-7ca7-46f5-a5d9-e163481a15ca" />


🚀 Future Improvements

GUI-based airport management

Real-world map integration

Airline ticket booking system

Support for weighted/undirected graphs with multiple routes

🤝 Contributing

Contributions are welcome! Feel free to fork this repo and submit pull requests.

Develpor 

Developed By Durmuhammad khan Data Structures Semester Project
