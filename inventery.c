 
 #include <stdio.h>
#include <string.h>

#define MAX 100

struct Product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product p[MAX];
int count = 0;

// Add Product
void addProduct() {
    if (count >= MAX) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter Product ID: ");
    scanf("%d", &p[count].id);

    printf("Enter Product Name: ");
    scanf(" %49[^\n]", p[count].name);

    printf("Enter Quantity: ");
    scanf("%d", &p[count].quantity);

    printf("Enter Price: ");
    scanf("%f", &p[count].price);

    count++;
    printf("Product added successfully!\n");
}

// Display Products
void displayProducts() {
    int i;

    if (count == 0) {
        printf("No products available.\n");
        return;
    }

    printf("\nID\tName\t\tQuantity\tPrice\n");

    for (i = 0; i < count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n",
        p[i].id, p[i].name,
        p[i].quantity, p[i].price);
    }
}

// Purchase Stock
void purchaseStock() {
    int id, qty, i;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter quantity to purchase: ");
            scanf("%d", &qty);

            if (qty <= 0) {
                printf("Invalid quantity!\n");
                return;
            }

            p[i].quantity += qty;
            printf("Stock updated successfully!\n");
            return;
        }
    }

    printf("Product not found!\n");
}

// Sell Product
void sellProduct() {
    int id, qty, i;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("Enter quantity to sell: ");
            scanf("%d", &qty);

            if (qty <= 0) {
                printf("Invalid quantity!\n");
            }
            else if (qty > p[i].quantity) {
                printf("Insufficient stock!\n");
            }
            else {
                p[i].quantity -= qty;
                printf("Product sold successfully!\n");
            }
            return;
        }
    }

    printf("Product not found!\n");
}

// Low Stock Alert
void lowStockAlert() {
    int i, found = 0;

    printf("\n--- LOW STOCK PRODUCTS ---\n");

    for (i = 0; i < count; i++) {
        if (p[i].quantity < 5) {
            printf("%s - Only %d left!\n",
            p[i].name, p[i].quantity);
            found = 1;
        }
    }

    if (!found)
        printf("All products have sufficient stock.\n");
}

// Search Product
void searchProduct() {
    int id, i;

    printf("Enter Product ID: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++) {
        if (p[i].id == id) {
            printf("\nProduct Found!\n");
            printf("Name: %s\n", p[i].name);
            printf("Quantity: %d\n", p[i].quantity);
            printf("Price: %.2f\n", p[i].price);
            return;
        }
    }

    printf("Product not found!\n");
}

// Main Function
int main() {
    int choice;

    do {
        printf("\n===== INVENTORY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Product\n");
        printf("2. Display Products\n");
        printf("3. Purchase Stock\n");
        printf("4. Sell Product\n");
        printf("5. Low Stock Alert\n");
        printf("6. Search Product\n");
        printf("7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addProduct(); break;
            case 2: displayProducts(); break;
            case 3: purchaseStock(); break;
            case 4: sellProduct(); break;
            case 5: lowStockAlert(); break;
            case 6: searchProduct(); break;
            case 7: printf("Thank you!\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while (choice != 7);

    return 0;
}