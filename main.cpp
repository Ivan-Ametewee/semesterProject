// To dos
// Getting creative if time is permitted we could convert all the info in text file so that if somebody manually opens up the text file they wouldn't have access to our info
// Formatting the output
// Reference id should be program generated not entered by user

#include <iostream>
#include <fstream>
#include <string> // For using the getline()
using namespace std;

class Inventory
{
    // private:
    int productRefNumber;
    fstream productFile;
    fstream tempFile; //temporary file for deleting items

    // public:
    Inventory();
    void addProduct();
    void displayProduct();
    void modifyProducts();
    void deleteProduct();
    void searchProducts();
};

Inventory::Inventory()
{
    productRefNumber = 0;

    productFile.open("inventory_file.txt", ios::out); // Writing to a text file
    if (productFile.is_open())
    {
        productFile << "List of Available Products\n";
    };
}

void Inventory::addProduct()
{

    string productName;
    int quantity;
    double prodPrice;
    cout << "[ Press Enter Key after entering each detail ]" << endl;

    cout << "Product ID: " << productRefNumber++ << endl
         << "Enter Product Name: ";
    cin >> productName;

    cout << "Price in GHS: ";
    cin >> prodPrice;

    cout << "Quantity: ";
    cin >> quantity;

    productFile.open("inventory_file.txt", ios::app); // Writting to a text file
    if (productFile.is_open())
    {
        productFile << productName << endl;
        productFile << productRefNumber << endl;
        productFile << prodPrice << endl;
        productFile << quantity << endl;
        productFile << "\n";
        productFile.close();
    }
}

void Inventory::displayProduct()
{

    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open())
    {
        string line;
        // The getline function reads a line of text from the text file and assigns it to the string var
        while (getline(productFile, line))
        {
            cout << line << endl;
        }
        productFile.close();
    }
}

void Inventory::modifyProducts()
{

    int userChoice;
    bool refExist = false;
    string refCode, line; // line keeps the individual line the pc reads.
    cout << "[ Press Enter Key after entering each detail ]" << endl;
    cout << "Enter the reference code of the product you would want to modify" << endl;
    productFile.open("inventory_file.txt", ios::in);
    if (productFile.is_open())
    {
        while (getline(productFile, line))
        {
            if (line == refCode)
            {
                refExist = true;
                break;
            }
        }
        productFile.close();
    }
    if (refExist)
    {
        cout << "What do you want to modify" << endl
             << "1. Product Name" << endl
             << "2. Price" << endl
             << "3. Quantity" << endl;
        cin >> userChoice;
    }
}

void Inventory::searchProducts()
{
// Function to search for an item in the inventory file
bool searchProducts(const std::string& itemName) {
    ifstream productFile("inventory_file.txt");

    if (!inventory_file) {
        std::cerr << "Error opening inventory file!" << endl;
        return false;
    }

    string line;
    while (getline(productFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos == string::npos) {
            cerr << "Invalid format in inventory file: " << line << endl;
            continue;
        }

        string productName = line.substr(0, commaPos);
        string quantityStr = line.substr(commaPos + 1);

        // Remove any leading/trailing whitespaces from item and quantity
        item.erase(0, item.find_first_not_of(" \t"));
        item.erase(item.find_last_not_of(" \t") + 1);

        quantityStr.erase(0, quantityStr.find_first_not_of(" \t"));
        quantityStr.erase(quantityStr.find_last_not_of(" \t") + 1);

        if (item == itemName) {
            std::cout << "Item found: " << item << ", Quantity: " << quantityStr << std::endl;
            return true;
        }
    }

    std::cout << "Item not found in inventory!" << std::endl;
    return false;
}
/*The function searchProducts takes an item name as input
and searches for it in the "inventory.txt" file. If the item is found,
it will display the item name and its quantity. Otherwise,
it will print a message indicating that the item was not found.*/
}


void Inventory::deleteProduct(){


// Function to delete an item from the inventory file
bool deleteProduct(const string& itemName) {
    ifstream productFile("inventory.txt");
    ofstream tempFile("temp.txt");

    if (!productFile || !tempFile) {
        cerr << "Error opening files!" << endl;
        return false;
    }

    string line;
    bool itemFound = false;
    while (getline(productFile, line)) {
        size_t commaPos = line.find(',');
        if (commaPos == string::npos) {
            cerr << "Invalid format in inventory file: " << line << endl;
            continue;
        }

        string item = line.substr(0, commaPos);
        if (item == productName) {
            itemFound = true;
            continue; // Skip writing this line to temp file (deleting the item)
        }

        tempFile << line << endl;
    }

    productFile.close();
    tempFile.close();

    if (itemFound) {
        remove("inventory_file.txt");
        rename("temp.txt", "inventory_file.txt");
        cout << "Item '" << itemName << "' has been deleted from the inventory." << endl;
        return true;
    } else {
        remove("temp.txt");
        cout << "Item not found in inventory!" << endl;
        return false;
    }
}
/*This code uses two files: "inventory_file.txt" (the original file) and "temp.txt" (a temporary file to store the modified content).
The function deleteProduct() takes an item name as input, reads the "inventory.txt" file, and writes all items except
the one to be deleted into the "temp.txt" file. After the operation is complete,
the original file is replaced with the temporary file, effectively deleting the item from the inventory.*/
}

// class Cashier
// {
// private:
//     double totalCash, cashIn, costOfItem;

// public:
//     Cashier();
//     Cashier(double totalAmount, double amountcashIn);
//     Cashier(double totalAmount);
//     int getBalance() const;
// };


/*int main() {
    string itemName;
    cout << "Enter the item name to search: ";
    getline(cin, itemName);

    if (searchItemInInventory(itemName)) {
        cout << "Item found in the inventory!" << endl;
    } else {
        cout << "Item not found in the inventory!" << endl;
    }


    cout << "Enter the item name to delete: ";
    getline(cin, itemName);

    if (deleteItemFromInventory(itemName)) {
        cout << "Item deleted successfully!" << endl;
    } else {
        cout << "Item not found in the inventory!" << endl;
    }

    return 0;
}*/
