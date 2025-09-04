#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iomanip>
#include <thread> 
#include <chrono>

using namespace std;

//Edges store kerne ke lye struct
struct Edge {                
    string destination;
    int distance;
    Edge* next;
};

//VERTICES STORE kerne ke struct
struct Node {
    string departure;
    Edge* head;
    Edge* tail;
    Node* next;
};

//Node wali list ka address rakhne ke lye global first or last
Node* head = NULL;
Node* tail = NULL;

vector<string> airports;  // airports ki list takeh metrix main index use ho ske 
vector< vector<int> > adjMatrix;  // Adjacency Matrix


class Stack {
private:
    int l;
    int* s;
    int top;

public:
    Stack(int length) {
        l = length;
        s = new int[length];
        top = -1;
    }

    ~Stack() {

    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == l - 1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        s[++top] = val;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        top--;
    }

    int peak() {
        if (isEmpty()) {
            return -1;
        }
        return s[top];
    }

};

class Queue {
    private:
    int l;
    int *q;
    int front;
    int rear;
    public:
    Queue(int length) {
        l = length;
        q = new int[length];
        front = rear = -1;
    }
    
    ~Queue() {}

    bool isFull() {
        return rear == l - 1;
    }

    bool isEmpty() {
        return front == -1 && rear == -1;
    }

    void enQueue(int val) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear++;
        }
        q[rear] = val;
    }

    void deQueue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }
        return q[front];
    }
};

// Function to insert a vertex
void insert_vertex(string departure) {
    Node* n = new Node;
    n->departure = departure;
    n->next = NULL;
    n->head =NULL;
    n->tail = NULL;
    if (head == NULL)
        head = tail = n;
    else {
        tail->next = n;
        tail = n;
    }

    // vertex ko airports wali vector main dalna he 
    airports.push_back(departure);

    //Adding new column in AdjacencyMetrix
    for (vector<int>& row: adjMatrix) {
        row.push_back(0);  // No direct path initially
    }
    //Adding a new row
    adjMatrix.push_back(vector<int>(airports.size(), 0)); 
}

// Check kre ga keh vertex exist kerta he ke nhi
bool check_vertex(string departure) {
    for (string c : airports) {
        if (c == departure) {
            return true;
        }
    }
    return false;
}

// Function to get the index of a departure
int getIndexFromAirportVertex(string departure) {
    for (int i = 0; i < airports.size(); i++) {
        if (airports[i] == departure) {
            return i;
        }
    }
    return -1;
}

//Yeh dono Adjacency list or Metrix main edge add krega 
void add_edge(string departure, string destination, int distance) {
    //List main search ker rhe hain Takeh usi ke sath edge link kren.
    Node* temp = head;
    while (temp != NULL) {
        if (temp->departure == departure) {
            break;
        }
        temp = temp->next;
    }
    if (temp == NULL) {
        cout << "Departure airport Not Found: " << departure << endl;
        return;
    }

    if (!check_vertex(destination)) {
        cout << "destination airport Not Found: " << destination << endl;
        return;
    }

    // Adjecemncy list main edge add kerhe hain 
    Edge* e = new Edge;
    e->destination = destination;
    e->distance = distance;
    e->next = NULL;

    if (temp->head == NULL)
        temp->head = temp->tail = e;
    else {
        temp->tail->next = e;
        temp->tail = e;
    }

    // Add edge in adjacency matrix
    int departure_idx = getIndexFromAirportVertex(departure);
    int destination_idx = getIndexFromAirportVertex(destination);
    adjMatrix[departure_idx][destination_idx] = distance;
}

// Function to display adjacency list
void displayAdjlist() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->departure << " ---> ";
        Edge* edge = temp->head;
        while (edge != NULL) {
            cout << "(" << edge->destination << " | " << edge->distance << " km) ";
            edge = edge->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

// Function to display adjacency matrix in Chunks
void displayAdjmatrix() {
    const int CHUNK_SIZE = 12; 

    cout << "\nAdjacency Matrix:\n";
    for (int start_col = 0; start_col < airports.size(); start_col += CHUNK_SIZE) {
        int end_col = min(start_col + CHUNK_SIZE, (int)airports.size());
        cout << setw(8) << " "; 
        for (int col = start_col; col < end_col; col++) {
            cout << setw(10) << airports[col];
        }
        cout << "\n";

        // Print each row with only the relevant chunk of columns
        for (int i = 0; i < airports.size(); i++) {
            cout << setw(8) << airports[i];

            for (int col = start_col; col < end_col; ++col) {
                cout << setw(10) << adjMatrix[i][col];
            }
            cout << "\n";
        }

        cout << "\n"; // Add spacing between chunks
    }
}


void bft(string start) {
    Queue q(airports.size());
    bool visited[100];
    //Start wale ki index find kerhe hain 
    int start_index = getIndexFromAirportVertex(start);
    if (start_index == -1) {
        cout << "Start departure not found!" << endl;
        return;
    }
    // Start BFT
    visited[start_index] = true;
    q.enQueue(start_index);

    cout << "BFT(Starting from " << start << "): " << endl;

    while (!q.isEmpty()) {
        int current_index = q.peek();
        q.deQueue();
        cout << airports[current_index] << " ---> ";

        Node* temp = head;
        while (temp != NULL) {
            if (temp->departure == airports[current_index]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int neighbor_index = getIndexFromAirportVertex(edge->destination);
            if (!visited[neighbor_index]) {
                visited[neighbor_index] = true;
                q.enQueue(neighbor_index);
            }
            edge = edge->next;
        }
    }
    cout << endl;
}


void dft(string start) {
    Stack s(airports.size());
    bool visited[100];

    int start_index = getIndexFromAirportVertex(start);
    if (start_index == -1) {
        cout << "Start departure not found!" << endl;
        return;
    }

    visited[start_index] = true;
    s.push(start_index);

    cout << "DFT (starting from " << start << "): " << endl;

    while (!s.isEmpty()) {
        int current_index = s.peak();
        s.pop();
        cout << airports[current_index] << " ---> ";
        Node* temp = head;
        while (temp != NULL) {
            if (temp->departure == airports[current_index]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int neighbor_index = getIndexFromAirportVertex(edge->destination);
            if (!visited[neighbor_index]) {
                visited[neighbor_index] = true;
                s.push(neighbor_index);
            }
            edge = edge->next;
        }
    }
    cout << endl;
}

// find edge with minimum distance or abhi tak jo visited nhi hoa 
int min_distance(vector<int>& dist,vector<bool>& visited, int num_airports) {
    int min = INT_MAX; 
    int min_index = -1;
    for (int i = 0; i < num_airports; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Function to reconstruct the path from the source to the target departure
string reconstruct_path(int target,vector<int>& previous) {
    vector<string> path;
    while (target != -1) {
        path.push_back(airports[target]);
        target = previous[target];
    }

    //Reverse kerhe takeh seedha path aye 
    reverse(path.begin(), path.end());
    // return path;
    string path_str="";
    for(int i=0;i<path.size();i++){
        path_str+=path[i]+"-->";
    }
    return path_str;
}

void dijkstra(string start) {
    int start_index = getIndexFromAirportVertex(start);
    if (start_index == -1) {
        cout << "Start departure not found!" << endl;
        return;
    }
    //Total airports kitne hain
    int num_airports = airports.size();

    vector<int> dist(num_airports, INT_MAX); 
    vector<bool> visited(num_airports, false);
    vector<int> previous(num_airports, -1);

    //Node ka khud se distance 0 hota he 
    dist[start_index] = 0;

    cout << "Dijkstra's Algorithm(starting from " << start << "): " << endl;

    for (int i = 0; i < num_airports - 1; i++) {
        //Jo node unvisited he or sab se kam dist he uska
        int current = min_distance(dist, visited, num_airports);
        visited[current] = true;

        //Current ke Neighbours ka distance update ker rhe hain
        Node* temp = head;
        while (temp != NULL) {
            if (temp->departure == airports[current]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int v = getIndexFromAirportVertex(edge->destination);
            if (!visited[v] && dist[current] != INT_MAX && dist[current] + edge->distance < dist[v]) {
                dist[v] = dist[current] + edge->distance;
                previous[v] = current;
            }
            edge = edge->next;
        }
    }
    cout<<"Airports   "<<"Distance    "<<"Route"<<endl;
    for(int i=0;i<100;i++){
        if(dist[i]<INT_MAX)
            cout<<left<<setw(11)<<airports[i]<<left<<setw(12)<<dist[i]<<reconstruct_path(i,previous)<<endl;
        else
            cout<<left<<setw(11)<<airports[i]<<left<<setw(12)<<"NO Path"<<"NO Route"<<endl;
    }
}
// Renamed the struct to KruskalEdge to avoid conflict
struct KruskalEdge {
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compare(KruskalEdge e1, KruskalEdge e2) {
    return e1.weight < e2.weight;
}

// Disjoint Set Union (DSU) functions
int findParent(int node, vector<int>& parent) {
    if (node != parent[node])
        parent[node] = findParent(parent[node], parent);
    return parent[node];
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    u = findParent(u, parent);
    v = findParent(v, parent);
    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[u] > rank[v])
        parent[v] = u;
    else{
        parent[v] = u;
        rank[u]++;
    }
}

// Function to perform Kruskal's Algorithm
void kruskal() {
    int num_airports = airports.size();
    //Simple edge ki jga Kruskul Edge use ker rhe hain
    vector<KruskalEdge> edges;  

    //List of all edges 
    Node* temp = head;
    while (temp != NULL) {
        Edge* edge = temp->head;
        while (edge != NULL) {
            int u = getIndexFromAirportVertex(temp->departure);
            int v = getIndexFromAirportVertex(edge->destination);
            KruskalEdge *newEdge=new KruskalEdge;
            newEdge->u=u;
            newEdge->v=v;
            newEdge->weight=edge->distance;
            edges.push_back(*newEdge);
            edge = edge->next;
        }
        temp = temp->next;
    }
    //Sorting of edges
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(num_airports), rank(num_airports, 0);
    for (int i = 0; i < num_airports; i++)
        parent[i] = i;

    vector<KruskalEdge> mst;
        int totalWeight = 0;
    
    // Iterate over sorted edges and build MST
    for (KruskalEdge edge : edges) {
        int u = findParent(edge.u, parent);
        int v = findParent(edge.v, parent);

        if (u != v) {
            mst.push_back(edge);
            totalWeight += edge.weight;
            unionSets(u, v, parent, rank);
        }
    }

    //Output the MST
    cout << "Kruskal's Algorithm: Minimum Spanning Tree" << endl;
    cout << left << setw(15) << "departure 1" << setw(15) << "departure 2" << setw(15) << "Weight" << endl;
    for (const KruskalEdge& e : mst) {
        cout << left << setw(15) << airports[e.u] << setw(15) << airports[e.v] << setw(15) << e.weight << endl;
    }
    cout << "Total weight of MST: " << totalWeight << endl;
}

void prim(string start) {
    int start_index = getIndexFromAirportVertex(start);
    if (start_index == -1) {
        cout << "Start departure not found!" << endl;
        return;
    }

    int num_airports = airports.size();
    vector<int> dist(num_airports, INT_MAX);   
    vector<bool> visited(num_airports, false); 
    vector<int> parent(num_airports, -1);

    dist[start_index] = 0;
    parent[start_index] = -1;

    cout << "Prim's Algorithm starting from " << start << ":" << endl;

    // Edges = V-1
    for (int i = 0; i < num_airports - 1; i++) {
        int current = min_distance(dist, visited, num_airports);
        visited[current] = true;

        // Update the dist and parent for neighbors of the selected node
        Node* temp = head;
        while (temp != NULL) {
            if (temp->departure == airports[current]) {
                break;
            }
            temp = temp->next;
        }

        Edge* edge = temp->head;
        while (edge != NULL) {
            int v = getIndexFromAirportVertex(edge->destination);
            if (!visited[v] && edge->distance < dist[v]) {
                dist[v] = edge->distance;
                parent[v] = current;
            }
            edge = edge->next;
        }
    }

    //Display
    int total_cost = 0; 
    cout << "Edges in the MST:\n";
    for (int i = 0; i < num_airports; i++) {
        if (parent[i] != -1) {
            cout << airports[parent[i]] << " - " << airports[i] << " : " << dist[i] << endl;
            total_cost += dist[i]; 
        }
    }

    cout << "\nTotal Cost of MST: " << total_cost << endl;
}
// Function to load data from CSV and build the graph
void load_data(const string& filename) {
    ifstream file(filename);
    string line, departure, destination;
    int distance;

    // Skip the header line if any
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        getline(ss, departure, ',');  // Read departure departure
        getline(ss, destination, ',');  // Read destination departure
        ss >> distance;  // Read distance

        // Insert vertices into the graph if not already present
        if (!check_vertex(departure)) {
            insert_vertex(departure);
        }
        if (!check_vertex(destination)) {
            insert_vertex(destination);
        }

        // Add edge between airports
        add_edge(departure, destination, distance);
        add_edge(destination, departure, distance);
    }

    file.close();
}

int main() {
    string filename = "filtered_routes_with_distances.csv";
    load_data(filename);
    int choice;
    string startdeparture;
    while (true) {
        cout << "\nMENU:\n";
        cout << "1: Display graph\n";
        cout << "2: Perform Breadth-First Traversal (BFT)\n";
        cout << "3: Perform Depth-First Traversal (DFT)\n";
        cout << "4: Apply Dijikstra Algorithm \n";
        cout << "5: Apply Kruskal's Algorithm \n";
        cout << "6: Apply Prim's Algorithm \n";
        cout << "7: Exit\n";
        cout << "Enter choicen here: ";
        cin >> choice;

        if (choice == 1){
            int c;
            cout << "1: Display Adjacency List of graph\n";
            cout << "2: Display Adjacency Matrix of graph\n";
            cout<<"Enter Your Choice:";
            cin>>c;
            for(;;){
                if(c==1){
                    displayAdjlist();
                    break;
                }
                else if(c==2){
                    displayAdjmatrix();
                    break;
                }
                else
                    cout<<"Invalid Choice.Plz enter Choice Again."<<endl;
            }
        }
        else if (choice == 2){
            cout << "Enter starting departure for BFT: ";
            cin >> ws;
            getline(cin, startdeparture);
            bft(startdeparture);
        }
        else if (choice == 3){
            cout << "Enter starting departure for DFT: ";
            cin >> ws; 
            getline(cin, startdeparture);
            dft(startdeparture);
        }
        else if (choice == 4){
            cout << "Enter starting departure for Dijikstra's Algorithm: ";
            cin >> ws;
            getline(cin, startdeparture);
            dijkstra(startdeparture);
        } 
        else if (choice == 5) {
            kruskal();
        } 
        else if (choice == 6) {
            cout << "Enter starting departure for Prim's Algorithm: ";
            cin >> ws; 
            getline(cin, startdeparture);
            prim(startdeparture);
        } 
        else if (choice == 7) {
            cout << "Exiting Program .";
            cout.flush();
            for(int i=0;i<=4;i++){
                this_thread::sleep_for(chrono::seconds(1));
                cout << " .";
                cout.flush();
            }
            break;
        } 
        else
            cout << "Invalid choice. Please enter choice Again.\n";
    }
    return 0;
}
