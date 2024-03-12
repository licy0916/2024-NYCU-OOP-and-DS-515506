/*
 
 We want to make an order system, which allows combining orders and the modification of products.

 Input Format:
    The main function explains everything.

 Constraints:
    Finish all the "// TODO".
    Do not add or modify other parts of the codes. You should be able to finish it  without adding additional elements.
    Note that for combining orders, you also need to combine two orderItems with the same products.
    The order of orderItems should be: first the orderItems from order1 without changing the order, and then the orderItems from order2 without changing the order that don't appear in order1.
 
 Output Format:
    As follow

 Sample Input:
     4
     laptop 20000
     mouse 500
     keyboard 1000
     laptop 20000
     3
     0 10
     2 20
     3 2
     2
     0 15
     1 5

 Sample Output:
     Order1:
     Items:
     laptop(22000) * 10 = 220000
     keyboard(1100) * 20 = 22000
     laptop(22000) * 2 = 44000
     Total Price with Taxes: 286000

     Order2:
     Items:
     laptop(22000) * 15 = 330000
     mouse(550) * 5 = 2750
     Total Price with Taxes: 332750

     Combined Order:
     Items:
     laptop(22000) * 25 = 550000
     keyboard(1100) * 20 = 22000
     laptop(22000) * 2 = 44000
     mouse(550) * 5 = 2750
     Total Price with Taxes: 618750

     Combined Order:
     Items:
     laptop(24000) * 25 = 600000
     keyboard(1200) * 20 = 24000
     laptop(24000) * 2 = 48000
     mouse(600) * 5 = 3000
     Total Price with Taxes: 675000

     Combined Order:
     Items:
     Invalid Product(24000) * 25 = 600000
     keyboard(1200) * 20 = 24000
     laptop(24000) * 2 = 48000
     mouse(120) * 5 = 600
     Total Price with Taxes: 672600
     
 */


#include <iostream>
#include <string>
#include <vector>

class Product {
public:
    Product() { }

    // TODO: Constructor
    Product(std::string newName, int newPrice) {
        setName(newName);
        setPrice(newPrice);
    };

    // TODO: setTaxRatio function
    static void setTaxRatio(float newtaxRatio){
        taxRatio = newtaxRatio;
    }

    void setName(std::string newName) {
        name = newName;
    }
    void setPrice(int newPrice) {
        price = newPrice;
    }

    // TODO: getName function
    std::string getName() const {
        return name;
    }

    // TODO: getPrice function
    float getPrice() const{
        return float(price)*(1+taxRatio);
    }
private:
    std::string name;
    int price;
    static float taxRatio;
};

// TODO: Initialize taxRatio to 0.1
float Product::taxRatio = 0.1;

class OrderItem {
public:
    // TODO: Constructor
    OrderItem(const Product& newProduct, int newCount) : product(newProduct) {
        count = newCount;
    };

    void setCount(int newCount) {
        count = newCount;
    }

    // TODO: getProduct function
    const Product& getProduct() const {
        return product;
    }

    // TODO: getCount function
    int getCount() const {
        return count;
    }

    // TODO: getPrice function
    int getPrice() const {
        return (product.getPrice())*getCount();
    }

private:
    const Product& product;
    int count;
};

class Order {
public:
    // TODO add function
    void add(OrderItem newOrderItem){
        orderItems.push_back(newOrderItem);
    }

    // TODO: getOrderItems
    std::vector<OrderItem> gerOrderItems () {
        return orderItems;
    }


    void output() const {
        int totalPrice = 0;
        std::cout << "Items: " << std::endl;
        for (int i = 0; i < orderItems.size(); i++) {
            std::cout << orderItems[i].getProduct().getName() << "(" << orderItems[i].getProduct().getPrice() << ")" << " * " << orderItems[i].getCount() << " = " << orderItems[i].getPrice() << std::endl;
            totalPrice += orderItems[i].getPrice();
        }
        std::cout << "Total Price with Taxes: " << totalPrice << std::endl;
    }
    // TODO: Override operator +
    friend Order operator+(const Order& order1, const Order& order2) {
        Order combinedOrder;

        // First, add all items from order1 to the combined order.
        for (const auto& item : order1.orderItems) {
            combinedOrder.add(item);
        }

        // Then, add items from order2, combining counts if the product already exists.
        for (const auto& item2 : order2.orderItems) {
            bool found = false;

            // Check if this item2 is already in the combined order.
            for (auto& itemCombined : combinedOrder.orderItems) {
                if (itemCombined.getProduct().getName() == item2.getProduct().getName()) {
                    // Found the same product, combine counts.
                    itemCombined.setCount(itemCombined.getCount() + item2.getCount());
                    found = true;
                    break;
                }
            }

            if (!found) {
                // If not found, simply add this item to the combined order.
                combinedOrder.add(item2);
            }
        }

        return combinedOrder;



    }



private:
    std::vector<OrderItem> orderItems;
};

int main(void) {
    int productCount;
    std::cin >> productCount;
    std::vector<Product> products;
    for (int i = 0; i < productCount; i++) {
        std::string name;
        int price;
        std::cin >> name >> price;
        products.push_back(Product(name, price));
    }

    Order order1;
    int orderItemCountForOrder1;
    std::cin >> orderItemCountForOrder1;
    for (int i = 0; i < orderItemCountForOrder1; i++) {
        int productIndex;
        int count;
        std::cin >> productIndex >> count;
        order1.add(OrderItem(products[productIndex], count));
    }

    Order order2;
    int orderItemCountForOrder2;
    std::cin >> orderItemCountForOrder2;
    for (int i = 0; i < orderItemCountForOrder2; i++) {
        int productIndex;
        int count;
        std::cin >> productIndex >> count;
        order2.add(OrderItem(products[productIndex], count));
    }

    std::cout << "Order1: " << std::endl;
    order1.output();
    std::cout << std::endl;

    std::cout << "Order2: " << std::endl;
    order2.output();
    std::cout << std::endl;

    Order combinedOrder = order1 + order2;
    std::cout << "Combined Order: " << std::endl;
    combinedOrder.output();
    std::cout << std::endl;

    Product::setTaxRatio(0.2);
    std::cout << "Combined Order: " << std::endl;
    combinedOrder.output();
    std::cout << std::endl;

    // Don't worry about this. We will make sure that the number of products exceeds 2.
    products[0].setName("Invalid Product");
    products[1].setPrice(100);
    std::cout << "Combined Order: " << std::endl;
    combinedOrder.output();
    std::cout << std::endl;
}
