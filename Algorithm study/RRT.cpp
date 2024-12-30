#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define a Node structure to represent points in the tree
struct Node {
    double x, y;
    Node* parent;
    Node(double x, double y) : x(x), y(y), parent(nullptr) {}
};

// Function to calculate the Euclidean distance between two points
double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// Function to find the nearest node in the tree to a given point
Node* nearestNode(const vector<Node>& tree, double x, double y) {
    Node* nearest = nullptr;
    double minDist = numeric_limits<double>::max();
    for (const Node& node : tree) {
        double d = distance(node.x, node.y, x, y);
        if (d < minDist) {
            nearest = const_cast<Node*>(&node);
            minDist = d;
        }
    }
    return nearest;
}

// Function to grow the RRT tree towards a random point
Node* growTree(const vector<Node>& tree, double goalX, double goalY, double stepSize) {
    Node* newNode = nullptr;
    while (newNode == nullptr) {
        double x = static_cast<double>(rand()) / RAND_MAX * 100.0;
        double y = static_cast<double>(rand()) / RAND_MAX * 100.0;
        Node* nearest = nearestNode(tree, x, y);
        double angle = atan2(y - nearest->y, x - nearest->x);
        double newX = nearest->x + stepSize * cos(angle);
        double newY = nearest->y + stepSize * sin(angle);

        // Check if the new point is within the boundaries of the workspace
        if (newX >= 0 && newX <= 100 && newY >= 0 && newY <= 100) {
            newNode = new Node(newX, newY);
            newNode->parent = nearest;
        }
    }
    return newNode;
}

// Function to trace the path from the goal node to the start node
vector<Node> tracePath(Node* goalNode) {
    vector<Node> path;
    Node* current = goalNode;
    while (current != nullptr) {
        path.push_back(*current);
        current = current->parent;
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    srand(time(nullptr));

    // Define the start and goal points
    Node start(10, 10);
    Node goal(90, 90);

    // Create a vector to store the tree
    vector<Node> tree;
    tree.push_back(start);

    // Define the maximum step size
    double stepSize = 5.0;

    // Maximum number of iterations
    int maxIterations = 1000;

    // RRT algorithm
    for (int i = 0; i < maxIterations; i++) {
        Node* newNode = growTree(tree, goal.x, goal.y, stepSize);
        if (newNode != nullptr) {
            tree.push_back(*newNode);
            if (distance(newNode->x, newNode->y, goal.x, goal.y) < stepSize) {
                // If the goal is within reach, add it to the tree
                goal.parent = newNode;
                tree.push_back(goal);
                break;
            }
        }
    }

    // Find the path
    vector<Node> path = tracePath(&goal);

    // Print the path
    for (const Node& node : path) {
        cout << "(" << node.x << ", " << node.y << ")" << " <- ";
    }
    cout << "Start" << endl;

    return 0;
}
