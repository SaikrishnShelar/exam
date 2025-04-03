#include<iostream>
using namespace std;

class BT {
public:
    int emp_id;
    string emp_name;
    float salary;
    BT* left;
    BT* right;

    BT(int emp_id, string emp_name, float salary) {
        this->emp_id = emp_id;
        this->emp_name = emp_name;
        this->salary = salary;
        left = right = NULL;
    }
};

BT* root = NULL;

void insert(BT*& temp, BT* current) {
    if (current->salary < temp->salary) {
        if (temp->left == NULL) {
            temp->left = current;
        } else {
            insert(temp->left, current);
        }
    } else {
        if (temp->right == NULL) {
            temp->right = current;
        } else {
            insert(temp->right, current);
        }
    }
}

void create() {
    int id;
    float salary;
    string name;
    cout << "Enter the ID of Employee: ";
    cin >> id;
    cout << "Enter the Name of Employee: ";
    cin >> name;
    cout << "Enter the Salary of Employee: ";
    cin >> salary;

    BT* newnode = new BT(id, name, salary);
    if (root == NULL) {
        root = newnode;
    } else {
        insert(root, newnode);
    }
}

void inorder(BT* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << "Name: " << root->emp_name << "\tID: " << root->emp_id << "\tSalary: " << root->salary << endl;
    inorder(root->right);
}

float max_salary(BT* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->salary;
}

float min_salary(BT* root) {
    if (root == NULL) {
        return -1;
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->salary;
}

void search(BT* root, float key) {
    if (root == NULL) {
        cout << "Employee with Salary " << key << " not found." << endl;
        return;
    }
    if (key == root->salary) {
        cout << "Name: " << root->emp_name << "\tID: " << root->emp_id << "\tSalary: " << root->salary << endl;
    } else if (key < root->salary) {
        search(root->left, key);
    } else {
        search(root->right, key);
    }
}

int countEmployees(BT* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countEmployees(root->left) + countEmployees(root->right);
}

float totalSalary(BT* root) {
    if (root == NULL) {
        return 0.0;
    }
    return root->salary + totalSalary(root->left) + totalSalary(root->right);
}

void avg_salary() {
    int count = countEmployees(root);
    if (count == 0) {
        cout << "No employees in the company." << endl;
    } else {
        float avg = totalSalary(root) / count;
        cout << "Average salary of " << count << " employees is: " << avg << endl;
    }
}

int main() {
    int ch;
    do {
        cout << "\nMENU\n1.Insert\n2.Display\n3.Search by Salary\n4.Max Salary\n5.Min Salary\n6.Total Employees\n7.Average Salary\n8.Exit\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1: create(); break;
        case 2: inorder(root); break;
        case 3: {
            float key;
            cout << "Enter employee salary to search: ";
            cin >> key;
            search(root, key);
            break;
        }
        case 4: cout << "Maximum salary is: " << max_salary(root) << endl; break;
        case 5: cout << "Minimum salary is: " << min_salary(root) << endl; break;
        case 6: cout << "There are total " << countEmployees(root) << " employees." << endl; break;
        case 7: avg_salary(); break;
        case 8: cout << "Exiting..."; break;
        default: cout << "Invalid choice."; break;
        }
    } while (ch != 8);
}

