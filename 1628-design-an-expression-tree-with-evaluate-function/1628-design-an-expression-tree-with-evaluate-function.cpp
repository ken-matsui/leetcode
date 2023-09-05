/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node(){};
    virtual int evaluate() const = 0;

protected:
    Node* lhs;
    Node* rhs;
    char op;
};

class ValueNode : public Node {
public:
    ValueNode(int val) : val(val){};

    int evaluate() const {
        return val;
    }

protected:
    int val;
};

class Expr : public Node {
public:
    Expr(Node* lhs, Node* rhs, char op) {
        this->lhs = lhs;
        this->rhs = rhs;
        this->op = op;
    }

    int evaluate() const {
        switch (op) {
        case '+':
            return lhs->evaluate() + rhs->evaluate();
        case '-':
            return lhs->evaluate() - rhs->evaluate();
        case '*':
            return lhs->evaluate() * rhs->evaluate();
        case '/':
            return lhs->evaluate() / rhs->evaluate();
        default:
            throw -1;
        }
    }
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<Node*> st;
        for (const string& p : postfix) {
            if (p == "+" || p == "-" || p == "*" || p == "/") {
                Node* rhs = st.top();
                st.pop();

                Node* lhs = st.top();
                st.pop();

                st.push(new Expr(lhs, rhs, p[0]));
            } else {
                st.push(new ValueNode(stoi(p)));
            }
        }
        return st.top();
    }
};

/**
 * Your TreeBuilder object will be instantiated and called as such:
 * TreeBuilder* obj = new TreeBuilder();
 * Node* expTree = obj->buildTree(postfix);
 * int ans = expTree->evaluate();
 */
