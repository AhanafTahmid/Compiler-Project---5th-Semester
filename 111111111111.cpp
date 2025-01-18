
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(string val) : value(val), left(nullptr), right(nullptr) {}
};


void drawNode(int x, int y, const string& value, int color = WHITE) {
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    circle(x, y, 20); // Draw the node circle
    floodfill(x, y, color);

    // Adjust text size for better visibility
    setbkcolor(color);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2); // 2 = larger font size (increase as needed)
    setcolor(BLACK);

    // Display the value inside the node
    outtextxy(x - 10, y - 10, (char*)value.c_str());
}


void drawLine(int x1, int y1, int x2, int y2) {
    setcolor(WHITE);
    line(x1, y1, x2, y2);
}

void visualizeTree(TreeNode* root, int x, int y, int xOffset, int level = 0) {
    if (!root) return;

    drawNode(x, y, root->value, LIGHTBLUE);

    // Draw left child
    if (root->left) {
        drawLine(x, y + 20, x - xOffset, y + 80);
        visualizeTree(root->left, x - xOffset, y + 80, xOffset / 2, level + 1);
    }

    // Draw right child
    if (root->right) {
        drawLine(x, y + 20, x + xOffset, y + 80);
        visualizeTree(root->right, x + xOffset, y + 80, xOffset / 2, level + 1);
    }
}

// Function to construct a parsing tree from a mathematical expression
TreeNode* constructTree(const string& expression) {
    stack<TreeNode*> nodes;   // Stack for operand nodes
    stack<char> operators;    // Stack for operators

    for (char ch : expression) {
        if (isspace(ch)) continue; // Skip spaces

        // If character is a digit or variable, create a node
        if (isalnum(ch)) {
            nodes.push(new TreeNode(string(1, ch)));
        }
        // If character is an operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!operators.empty() &&
                   ((ch == '+' || ch == '-') || (ch == '*' || ch == '/')) &&
                   (operators.top() == '*' || operators.top() == '/')) {
                // Process higher precedence operators
                char op = operators.top();
                operators.pop();

                TreeNode* right = nodes.top(); nodes.pop();
                TreeNode* left = nodes.top(); nodes.pop();

                TreeNode* newNode = new TreeNode(string(1, op));
                newNode->left = left;
                newNode->right = right;

                nodes.push(newNode);
            }
            operators.push(ch);
        }
        // If opening parenthesis, push to operator stack
        else if (ch == '(') {
            operators.push(ch);
        }
        // If closing parenthesis, process until opening parenthesis
        else if (ch == ')') {
            while (!operators.empty() && operators.top() != '(') {
                char op = operators.top();
                operators.pop();

                TreeNode* right = nodes.top(); nodes.pop();
                TreeNode* left = nodes.top(); nodes.pop();

                TreeNode* newNode = new TreeNode(string(1, op));
                newNode->left = left;
                newNode->right = right;

                nodes.push(newNode);
            }
            if (!operators.empty() && operators.top() == '(') {
                operators.pop(); // Remove the opening parenthesis
            }
        }
    }

    // Process any remaining operators
    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        TreeNode* right = nodes.top(); nodes.pop();
        TreeNode* left = nodes.top(); nodes.pop();

        TreeNode* newNode = new TreeNode(string(1, op));
        newNode->left = left;
        newNode->right = right;

        nodes.push(newNode);
    }

    // The remaining node is the root of the tree
    return nodes.empty() ? nullptr : nodes.top();
}


void visualizeParsingTree(const string& expression) {
    cleardevice(); // Clear the screen
    TreeNode* root = constructTree(expression);

    if (!root) {
        cout << "Invalid expression!\n";
        return;
    }

    // Visualize the tree
    visualizeTree(root, getmaxx() / 2, 50, getmaxx() / 4);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    string expression = "(a+b)+c";
    visualizeParsingTree(expression);

    getch();
    closegraph();
    return 0;
}
