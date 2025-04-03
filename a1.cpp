#include <iostream>
#include <stack>

using namespace std;

class Node
{
public:
    int age;
    string name;
    Node *left, *right;
    Node(int x, string name1)
    {
        age = x;
        name = name1;
        left = right = NULL;
    }
} *root = NULL;

void insert(Node *root1, Node *temp1)
{
    char field;
    cout << "Enter the field (l/r) for insertion: ";
    cin >> field;
    if (field == 'l')
    {
        if (!root1->left)//root-<left==null
            root1->left = temp1;
        else
            insert(root1->left, temp1);
    }
    else if (field == 'r')
    {
        if (!root1->right)//root->right==null
            root1->right = temp1;
        else
            insert(root1->right, temp1);
    }
    else
    {
        cout << "Invalid choice! Please enter 'l' or 'r'.\n";
    }
}

void insertroot()
{
    int value;
    string name;
    cout << "Enter the age of the member: ";
    cin >> value;
    cout << "Enter the name of the member: ";
    cin >> name;
    Node *temp = new Node(value, name);
    if (!root)//root==null
        root = temp;
    else
        insert(root, temp);
}

void displaypreorder(Node *ro)
{
    if (!ro)
        return;
    cout << "Name: " << ro->name << "\nAge: " << ro->age << "\n";
    displaypreorder(ro->left);
    displaypreorder(ro->right);
}

// void leafDisplay(Node *ro)
// {
//     if (!ro)
//         return;
//     leafDisplay(ro->left);
//     leafDisplay(ro->right);
//     if (ro->left && ro->right)
//         cout << "Name: " << ro->name << "\nAge: " << ro->age << "\n";
// }

int displayTotalNode(Node *ro)
{
    if (ro == NULL)
    {
        return 0;
    }

    return 1 + displayTotalNode(ro->left) + displayTotalNode(ro->right);
}

bool search(Node *root, string &name)
{
    if (!root)
        return false;
    if (root->name == name)
    {
        cout << "The member is present in the family.\n";
        return true;
    }
    return search(root->left, name) || search(root->right, name);
}

void update(Node *root, string &member)
{
    if (!root)
        return;
    if (root->name == member)
    {
        cout << "Enter new age: ";
        cin >> root->age;
        cout << "Enter new name: ";
        cin >> root->name;
        cout<<"Record updated successfully.\n";
        return;
    }
    update(root->left, member);
    update(root->right, member);
}

bool checkancestors(Node *root, string &member)
{
    if (!root)
        return false;
    if (root->name == member)
        return true;
    if (checkancestors(root->left, member) || checkancestors(root->right, member))
    {
        cout << root->name << endl;
        return true;
    }
    return false;
}

void ancestors(Node *root, string &member)
{
    if (!checkancestors(root, member))
        cout << "Ancestor not found\n";
  
}

void descendants(Node *root, string &member)
{
    if (!root)
        return;
    if (root->name == member)
    {
        cout << "Descendants of " << member << " are:\n";
        displaypreorder(root->left);
        displaypreorder(root->right);
        return;
    }
    descendants(root->left, member);
    descendants(root->right, member);
}

void siblings(Node *root, string &member)
{
  if (root == NULL)
    {
        return;
    }
    if (root->name == member)
    {
        if (root->left != NULL)
        {
            cout << root->left->name << endl;
        }
        else{
            cout << "no sibling" << endl;
        }
        if (root->right != NULL)
        {
            cout << root->right->name << endl;
    }
    else{
        cout << "no sibling" << endl;
    }
    return;
    }
        displaypreorder(root->left);
        displaypreorder(root->right);
 
  
}

int main()
{
    int ch;
    string member;
    do
    {
        cout << "\nOperations:\n1. Insert Member\n2. Display Members\n3. Search Member\n4. Update Member Info\n5. Total Members\n6. Ancestor of Given Member\n7. Descendants of Given Member\n8. Oldest Member\n9. Find Siblings\n10. Exit\nEnter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            insertroot();
            break;
        case 2:
            displaypreorder(root);
            break;
        case 3:
            cout << "Enter name to search: ";
            cin >> member;
            if (!search(root, member))
                cout << "Member not found in family.\n";
            break;
        case 4:
            cout << "Enter name to update: ";
            cin >> member;
            update(root, member);
            break;
        case 5:
            cout << "Total members: " << displayTotalNode(root) << "\n";
            break;
        case 6:
            cout << "Enter name to find ancestors: ";
            cin >> member;
            ancestors(root, member);
            break;
        case 7:
            cout << "Enter name to find descendants: ";
            cin >> member;
            descendants(root, member);
            break;
        case 8:
            if (root)
                cout << "Oldest member: " << root->name << "\n";
            else
                cout << "No members present.\n";
            break;
        case 9:
            cout << "Enter name to find siblings: ";
            cin >> member;
            siblings(root, member);
            break;
        case 10:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Enter a valid choice.\n";
        }
    } while (ch != 10);
    return 0;
}
