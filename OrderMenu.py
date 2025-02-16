# Define menu of the restaurant 
menu = {
    'Pizza': 80,
    'Pasta': 100,
    'Caesar Salad': 120,
    'Coffee': 60
}

# Greet
print("Welcome to Jerry's Kitchen")
print("Pizza: 80\nPasta: 100\nCaesar Salad: 120\nCoffee: 60")  # Fixed \n

order_total = 0

while True:
    item = input("Enter the name of the item you want to order (or type 'done' to finish): ")
    
    if item.lower() == "done":
        break  # Stop taking orders

    if item in menu:
        order_total += menu[item]
        print(f"Your item {item} has been added to the cart.")
    else:
        print(f"Sorry! {item} is not available, please order something else.")

print(f"The total amount to pay is {order_total}.")

